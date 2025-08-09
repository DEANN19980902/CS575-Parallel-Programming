# CS575 Introduction to Parallel Programming

A comprehensive collection of parallel programming projects and assignments developed for CS575 Introduction to Parallel Programming course, focusing on high-performance computing, parallel algorithms, and multi-threading techniques.

## 📋 Table of Contents

- [Overview](#overview)
- [Projects](#projects)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Parallel Programming Concepts](#parallel-programming-concepts)
- [Performance Analysis](#performance-analysis)
- [Learning Objectives](#learning-objectives)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This repository contains a series of parallel programming projects that explore various aspects of high-performance computing and parallel algorithm design, including:

- **Multi-threading and Concurrency**: Thread-based parallel programming
- **OpenMP Programming**: Shared-memory parallel programming
- **MPI (Message Passing Interface)**: Distributed-memory parallel computing
- **CUDA Programming**: GPU parallel computing and acceleration
- **Performance Optimization**: Parallel algorithm analysis and optimization
- **Synchronization Mechanisms**: Thread synchronization and coordination
- **Parallel Design Patterns**: Common parallel programming patterns

Each project demonstrates different parallel programming concepts and practical implementation skills using modern parallel computing frameworks.

## 📁 Projects

### Project 0 - Introduction to Parallel Programming
- **Focus**: Fundamentals of parallel programming concepts
- **Topics**: Basic parallel programming principles, performance metrics
- **Files**: `project0/`
- **Key Components**:
  - Introduction to parallel computing concepts
  - Performance measurement and analysis basics

### Project 1 - Multi-threading Fundamentals
- **Focus**: Basic multi-threading and thread management
- **Topics**: Thread creation, synchronization, shared memory
- **Files**: `project1/`
- **Key Components**:
  - Thread-based parallel programming
  - Mutex and synchronization primitives
  - Performance comparison analysis

### Project 2 - OpenMP Parallel Programming
- **Focus**: Shared-memory parallel programming with OpenMP
- **Topics**: Parallel loops, work sharing, thread coordination
- **Files**: `project2/`
- **Key Components**:
  - OpenMP directives and clauses
  - Parallel loop optimization
  - Load balancing techniques

### Project 3 - Advanced OpenMP Techniques
- **Focus**: Advanced OpenMP features and optimization
- **Topics**: Parallel sections, reductions, scheduling strategies
- **Files**: `project3/`
- **Key Components**:
  - Advanced OpenMP constructs
  - Performance tuning and optimization
  - Scalability analysis

### Project 4 - MPI Distributed Computing
- **Focus**: Message Passing Interface for distributed computing
- **Topics**: Point-to-point communication, collective operations
- **Files**: `project4/`
- **Key Components**:
  - MPI communication patterns
  - Distributed algorithm implementation
  - Network performance analysis

### Project 5 - GPU Computing with CUDA
- **Focus**: GPU parallel programming and acceleration
- **Topics**: CUDA kernels, memory management, parallel algorithms
- **Files**: `project5/`
- **Key Components**:
  - CUDA kernel development
  - GPU memory optimization
  - Performance comparison (CPU vs GPU)

### Project 6 - Advanced Parallel Algorithms
- **Focus**: Complex parallel algorithm implementation
- **Topics**: Parallel sorting, searching, numerical algorithms
- **Files**: `project6/`
- **Key Components**:
  - Parallel algorithm design
  - Complexity analysis
  - Performance optimization techniques

### Project 7 - Parallel Programming Optimization
- **Focus**: Performance optimization and advanced techniques
- **Topics**: Cache optimization, NUMA awareness, hybrid programming
- **Files**: `project7/`
- **Key Components**:
  - Advanced optimization techniques
  - Hybrid parallel programming models
  - Comprehensive performance analysis

## 🛠 Technologies Used

### Parallel Programming Frameworks
- **OpenMP**: Shared-memory parallel programming
- **MPI**: Message Passing Interface for distributed computing
- **CUDA**: NVIDIA GPU programming platform
- **Pthreads**: POSIX threads for multi-threading

### Programming Languages
- **C/C++**: Primary programming language for performance-critical code
- **CUDA C**: GPU kernel programming
- **Assembly**: Low-level optimization (where applicable)

### Development Tools
- **GCC**: GNU Compiler Collection with OpenMP support
- **NVCC**: NVIDIA CUDA Compiler
- **MPICH/OpenMPI**: MPI implementations
- **Profiling Tools**: Performance analysis and debugging

### Performance Analysis
- **Timing Libraries**: High-resolution timing measurements
- **Profilers**: Code profiling and bottleneck analysis
- **Visualization Tools**: Performance data visualization
- **Benchmarking**: Standardized performance testing

## 🚀 Getting Started

### Prerequisites

- **Compiler**: GCC 9.0+ with OpenMP support
- **MPI**: MPICH or OpenMPI installation
- **CUDA**: NVIDIA CUDA Toolkit (for GPU projects)
- **Hardware**: Multi-core CPU, GPU (optional for CUDA projects)
- **OS**: Linux (Ubuntu 20.04+), macOS, or Windows with WSL

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/DEANN19980902/CS575.git
   cd CS575
   ```

2. **Install required tools**:
   ```bash
   # Ubuntu/Debian
   sudo apt update
   sudo apt install build-essential gcc g++ libomp-dev
   sudo apt install mpich libmpich-dev
   
   # macOS (using Homebrew)
   brew install gcc libomp mpich
   ```

3. **Install CUDA (for GPU projects)**:
   ```bash
   # Download and install NVIDIA CUDA Toolkit
   # Follow official NVIDIA installation guide
   ```

### Usage

#### General Project Compilation

Most projects follow a similar compilation pattern:

```bash
# Navigate to project directory
cd project1

# Compile with OpenMP
gcc -fopenmp -O3 -o program source.c

# Compile with MPI
mpicc -O3 -o program source.c

# Compile CUDA project
nvcc -O3 -o program source.cu
```

#### Running Programs

```bash
# OpenMP program
export OMP_NUM_THREADS=4
./program

# MPI program
mpirun -np 4 ./program

# CUDA program
./program
```

## 📂 Project Structure

```
CS575/
├── project0/                    # Introduction to Parallel Programming
│   ├── intro.c
│   ├── Makefile
│   └── results/
├── project1/                    # Multi-threading Fundamentals
│   ├── threads.c
│   ├── Makefile
│   └── performance_analysis/
├── project2/                    # OpenMP Parallel Programming
│   ├── openmp_basic.c
│   ├── parallel_loops.c
│   └── benchmarks/
├── project3/                    # Advanced OpenMP Techniques
│   ├── advanced_openmp.c
│   ├── optimization/
│   └── scalability_tests/
├── project4/                    # MPI Distributed Computing
│   ├── mpi_communication.c
│   ├── collective_ops.c
│   └── network_analysis/
├── project5/                    # GPU Computing with CUDA
│   ├── cuda_kernels.cu
│   ├── memory_optimization/
│   └── gpu_benchmarks/
├── project6/                    # Advanced Parallel Algorithms
│   ├── parallel_sort.c
│   ├── parallel_search.c
│   └── algorithm_analysis/
├── project7/                    # Parallel Programming Optimization
│   ├── hybrid_programming/
│   ├── cache_optimization/
│   └── performance_tuning/
└── README.md                    # This file
```

## 📋 Requirements

### System Requirements
- **CPU**: Multi-core processor (4+ cores recommended)
- **Memory**: 8GB+ RAM (16GB+ for large-scale problems)
- **GPU**: NVIDIA GPU with CUDA support (for GPU projects)
- **Storage**: 20GB+ free space for development and datasets

### Software Requirements
- **GCC**: Version 9.0+ with OpenMP support
- **MPI**: MPICH 3.0+ or OpenMPI 4.0+
- **CUDA**: NVIDIA CUDA Toolkit 11.0+ (for GPU projects)
- **Make**: Build automation tool

## 🎓 Learning Objectives

Through these projects, you will master:

### 1. **Parallel Programming Fundamentals**
   - Understanding of parallel computing concepts
   - Thread creation and management
   - Synchronization and coordination mechanisms
   - Performance measurement and analysis

### 2. **Shared-Memory Programming**
   - OpenMP parallel programming model
   - Parallel loop constructs and optimizations
   - Work sharing and load balancing
   - Memory consistency and synchronization

### 3. **Distributed-Memory Programming**
   - MPI communication patterns
   - Point-to-point and collective operations
   - Distributed algorithm design
   - Network performance considerations

### 4. **GPU Programming**
   - CUDA programming model
   - Kernel development and optimization
   - Memory hierarchy and optimization
   - CPU-GPU hybrid programming

### 5. **Performance Optimization**
   - Parallel algorithm analysis
   - Scalability and efficiency metrics
   - Cache optimization techniques
   - NUMA-aware programming

### 6. **Parallel Design Patterns**
   - Common parallel programming patterns
   - Algorithm parallelization strategies
   - Performance trade-offs and considerations
   - Debugging and profiling techniques

## 💡 Key Concepts Covered

### Parallel Programming Models
- **Shared Memory**: OpenMP, Pthreads
- **Distributed Memory**: MPI, cluster computing
- **GPU Computing**: CUDA, parallel acceleration
- **Hybrid Models**: MPI + OpenMP, CPU + GPU

### Synchronization Mechanisms
- **Mutexes**: Mutual exclusion locks
- **Barriers**: Thread synchronization points
- **Atomic Operations**: Lock-free programming
- **Condition Variables**: Thread coordination

### Performance Metrics
- **Speedup**: Performance improvement ratio
- **Efficiency**: Resource utilization effectiveness
- **Scalability**: Performance with increasing resources
- **Load Balance**: Work distribution optimization

### Optimization Techniques
- **Cache Optimization**: Memory access patterns
- **Loop Optimization**: Parallel loop constructs
- **Memory Management**: Efficient memory usage
- **Communication Optimization**: Minimizing overhead

## 📊 Performance Analysis

### Benchmarking Methodology
- **Baseline Measurements**: Sequential performance reference
- **Scalability Testing**: Performance with varying thread/process counts
- **Profiling**: Identifying performance bottlenecks
- **Optimization Validation**: Measuring improvement effectiveness

### Common Performance Patterns
```c
// Example timing code
#include <omp.h>
double start_time = omp_get_wtime();
// Parallel computation here
double end_time = omp_get_wtime();
double execution_time = end_time - start_time;
```

### Performance Metrics Calculation
```c
// Speedup calculation
double speedup = sequential_time / parallel_time;

// Efficiency calculation
double efficiency = speedup / num_threads;

// Parallel overhead
double overhead = (num_threads * parallel_time) - sequential_time;
```

## 🎯 Use Cases

### High-Performance Computing
- **Scientific Computing**: Numerical simulations and modeling
- **Data Processing**: Large-scale data analysis and processing
- **Machine Learning**: Parallel training and inference
- **Financial Modeling**: Risk analysis and optimization

### Software Development
- **Application Optimization**: Performance-critical software development
- **System Programming**: Operating system and driver development
- **Game Development**: Real-time graphics and physics simulation
- **Web Services**: High-throughput server applications

### Research and Education
- **Algorithm Research**: Parallel algorithm development and analysis
- **Performance Studies**: Parallel computing research
- **Educational Tools**: Teaching parallel programming concepts
- **Benchmarking**: Performance comparison and evaluation

## 🤝 Contributing

This repository represents coursework for educational purposes. If you're a student in a similar course:

1. Use this as a reference and learning resource
2. Understand the concepts rather than copying code
3. Respect academic integrity policies
4. Feel free to suggest improvements or report issues

## 📄 License

This project is created for educational purposes as part of CS575 Introduction to Parallel Programming coursework. Please respect academic integrity guidelines when referencing this work.

## 📞 Contact

**Author**: Yi Chiun Chang  
**Course**: CS575 Introduction to Parallel Programming  
**Institution**: [Your University Name]  
**Focus Areas**: High-Performance Computing, Parallel Algorithms, GPU Programming

---

⭐ If you found this repository helpful for learning parallel programming, please consider giving it a star!

## 🔗 Additional Resources

### Parallel Programming Books
- [Introduction to Parallel Computing](https://www.pearson.com/us/higher-education/program/Grama-Introduction-to-Parallel-Computing-2nd-Edition/PGM97509.html) - Grama, Gupta, Karypis, Kumar
- [Parallel Programming in C with MPI and OpenMP](https://www.mcs.anl.gov/research/projects/mpi/tutorial/) - Michael Quinn
- [CUDA Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/) - NVIDIA Official Guide

### Online Resources
- [OpenMP Official Site](https://www.openmp.org/) - OpenMP specifications and tutorials
- [MPI Forum](https://www.mpi-forum.org/) - MPI standard and documentation
- [NVIDIA CUDA Zone](https://developer.nvidia.com/cuda-zone) - CUDA resources and tutorials
- [Lawrence Livermore HPC Tutorials](https://hpc-tutorials.llnl.gov/) - Comprehensive HPC tutorials

### Tools and Profilers
- [Intel VTune Profiler](https://software.intel.com/content/www/us/en/develop/tools/vtune-profiler.html) - Performance analysis tool
- [NVIDIA Nsight](https://developer.nvidia.com/nsight-systems) - GPU profiling and debugging
- [Valgrind](https://valgrind.org/) - Memory debugging and profiling
- [TAU Performance System](https://www.cs.uoregon.edu/research/tau/home.php) - Performance analysis framework 