# DataExecutionPrevention

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Possible Output](#possible-output)

## Introduction
This project shows how Data Execution Prevention (DEP) works by trying to run code from a data buffer in C++. It demonstrates how operating systems block execution from non-code memory regions to improve security.

## Build and Run
To clone and run this project, you'll need [Git](https://git-scm.com) and [CMake](https://cmake.org/) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/DataExecutionPrevention

# Go into the repository
$ cd DataExecutionPrevention

# Generate the build files
$ cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build

# Build the project
$ cmake --build build --config Debug
```

Then, run the executables generated in the `build` directory.

## Possible Output

`./build/no_dep` will output:

```
Shellcode executed!
```

`./build/with_dep` will throw a segmentation fault (SIGSEGV) error, indicating that the operating system has prevented the execution of code from a data segment.


