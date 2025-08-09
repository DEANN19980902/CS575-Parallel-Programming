#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <iostream>

int NowYear = 2024;
int NowMonth = 0;
float NowPrecip;  // inches of rain per month
float NowTemp;    // temperature this month in Fahrenheit
float NowHeight = 5.0;  // grain height in inches
int NowNumDeer = 2;     // number of deer in the current population
int NowNumNatives = 1; 


const int END_YEAR = 2030;
const float GRAIN_GROWS_PER_MONTH =	       12.0;
const float ONE_DEER_EATS_PER_MONTH =		1.0;

const float AVG_PRECIP_PER_MONTH =		7.0;	// average
const float AMP_PRECIP_PER_MONTH =		6.0;	// plus or minus
const float RANDOM_PRECIP =			2.0;	// plus or minus noise

const float AVG_TEMP =				60.0;	// average
const float AMP_TEMP =				20.0;	// plus or minus
const float RANDOM_TEMP =			10.0;	// plus or minus noise

const float MIDTEMP =				40.0;
const float MIDPRECIP =				10.0;
unsigned int seed = 0;

omp_lock_t Lock;
int NumInThreadTeam;
int NumAtBarrier;
int NumGone;

float Ranf( unsigned int* seedp, float low, float high )
{
        float r = (float) rand();               // 0 - RAND_MAX
        float t = r  /  (float) RAND_MAX;       // 0. - 1.

        return   low  +  t * ( high - low );
}
float SQR( float x )
{
        return x*x;
}

void
InitBarrier( int n )
{
        NumInThreadTeam = n;
        NumAtBarrier = 0;
	omp_init_lock( &Lock );
}

void
WaitBarrier( )
{
        omp_set_lock( &Lock );
        {
                NumAtBarrier++;
                if( NumAtBarrier == NumInThreadTeam )
                {
                        NumGone = 0;
                        NumAtBarrier = 0;
                        // let all other threads get back to what they were doing
			// before this one unlocks, knowing that they might immediately
			// call WaitBarrier( ) again:
                        while( NumGone != NumInThreadTeam-1 );
                        omp_unset_lock( &Lock );
                        return;
                }
        }
        omp_unset_lock( &Lock );

        while( NumAtBarrier != 0 );	// this waits for the nth thread to arrive

        #pragma omp atomic
        NumGone++;			// this flags how many threads have returned
}


void Grain();
void Deer();
void Watcher();
void MyAgent();  // Your custom agent

int main() {
    omp_set_num_threads(4);
    InitBarrier(4);

#pragma omp parallel sections
    {
#pragma omp section
        {
            Deer();
        }

#pragma omp section
        {
            Grain();
        }

#pragma omp section
        {
            Watcher();
        }

#pragma omp section
        {
            MyAgent();
        }
    }  // Implied barrier here

    return 0;
}

void Grain() {
    while (NowYear < END_YEAR) {
        float tempFactor = exp(-SQR((NowTemp - MIDTEMP) / 10.0));
        float precipFactor = exp(-SQR((NowPrecip - MIDPRECIP) / 10.0));
        float nextHeight = NowHeight;
        nextHeight += tempFactor * precipFactor * GRAIN_GROWS_PER_MONTH;
        nextHeight -= (float)NowNumDeer * ONE_DEER_EATS_PER_MONTH;
        if (nextHeight < 0.) nextHeight = 0.;

        // Done computing
        WaitBarrier();
        NowHeight = nextHeight;
        // Done assigning
        WaitBarrier();
        // Done printing
        WaitBarrier();
    }
}

void Deer() {
    while (NowYear < END_YEAR) {
        int carryingCapacity = (int)(NowHeight);
        int nextNumDeer = NowNumDeer;
        if (nextNumDeer < carryingCapacity)
            nextNumDeer++;
        else if (nextNumDeer > carryingCapacity)
            nextNumDeer--;
        if (nextNumDeer < 0)
            nextNumDeer = 0;

        // Done computing
        WaitBarrier();
        NowNumDeer = nextNumDeer;
        // Done assigning
        WaitBarrier();
        // Done printing
        WaitBarrier();
    }
}

void Watcher() {
    while (NowYear < END_YEAR) {
        // Done computing
        WaitBarrier();
        // Done assigning
        WaitBarrier();

        std::cout << NowMonth << "," 
                  << NowYear << ","
                  << ((5./9.)*(NowTemp-32)) << "," 
                  << (NowPrecip*2.54) << ","
                  << (NowHeight*2.54) << ","
                  << NowNumDeer << ","
                  << NowNumNatives << std::endl;

        // Increment month
        NowMonth++;
        if (NowMonth > 11) {
            NowMonth = 0;
            NowYear++;
        }

         float ang = (30.0 * (float)NowMonth + 15.0) * (M_PI / 180.0);
        float temp = AVG_TEMP - AMP_TEMP * cos(ang);
        NowTemp = temp + Ranf(&seed, -RANDOM_TEMP, RANDOM_TEMP);
        float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin(ang);
        NowPrecip = precip + Ranf(&seed, -RANDOM_PRECIP, RANDOM_PRECIP);
        if( NowPrecip < 0. ){
	        NowPrecip = 0.;
        }
        // Done printing
        WaitBarrier();
	}
}

void MyAgent() {
    int lastNumDeer = NowNumDeer;  // 存储前一次的鹿的数量
    while (NowYear < END_YEAR) {
        int nextNumNatives = NowNumNatives;
        int currentNumDeer = NowNumDeer;  // 获取当前的鹿数量
        int deerChange = currentNumDeer - lastNumDeer;  // 计算鹿数量的变化

        // 根据鹿的数量变化调整原住民数量
        nextNumNatives += deerChange;

        // 温度和降水对原住民的负面影响
        float tempC = (NowTemp - 32.0) * 5.0 / 9.0;  // 转换为摄氏度
        if (tempC < 0.0 || tempC > 40.0 || NowPrecip <= 0.1) {
            nextNumNatives -= 3;  // 环境恶劣时减少3个原住民
        }

        // 保证原住民数量不低于0
        if (nextNumNatives < 0) {
            nextNumNatives = 0;
        }

        // 更新前一次鹿的数量
        lastNumDeer = currentNumDeer;

        // 同步屏障
        WaitBarrier();
        NowNumNatives = nextNumNatives;
        WaitBarrier();
        WaitBarrier();
    }
}
       

