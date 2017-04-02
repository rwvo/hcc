HCC : An open source C++ compiler for heterogeneous devices
===========================================================
This repository hosts HCC compiler implementation project. The goal is to 
implement a compiler that takes a program conforming parallel programming 
standards such as C++ AMP, HC, C++ 17 ParallelSTL, or OpenMP and transforms it 
into AMD GCN ISA.

The project is based on LLVM+CLANG. For more information, please visit the 
[hcc wiki][1]:

[https://github.com/RadeonOpenCompute/hcc/wiki][1]

Git submodules
==============
The project now employs git submodules to manage external components it depends 
upon. It it advised to add `--recursive` when you clone the project so all 
submodules are fetched automatically.

For example:
```bash
# automatically fetches all submodules
git clone --recursive -b clang_tot_upgrade https://github.com/RadeonOpenCompute/hcc.git
```

For more information about git submodules, please refer to [git documentation][2].

Device libraries
================
HCC device library is a part of [ROCm-Device-Libs][3]. When compiling device 
code with hcc, the rocm-device-libs package needs to be installed.

You can install its binary package via:

```
    sudo apt-get install rocm-device-libs libc6-dev-i386
```

In case rocm-device-libs package is not present, or you want to build it
from source, please refer to 
[ROCm-Device-Libs build procedure][4] for more details.

Once it's built, run `make install` and config ToT HCC like:

```bash
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DHSA_AMDGPU_GPU_TARGET=<AMD GPU ISA version string> \
    -DROCM_DEVICE_LIB_DIR=<location of the ROCm-Device-Libs bitcode> \
    <ToT HCC checkout directory>
```

An example would be:
```bash
# Use gfx803 AMD GPU ISA
# ROCm-Device-Libs is built at ~/ocml/build , bitcodes are at
# ~/ocml/build/dist/lib
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DHSA_AMDGPU_GPU_TARGET=gfx803 \
    -DROCM_DEVICE_LIB_DIR=~/ocml/build/dist/lib \
    ..
```

Multiple ISA
============

HCC now supports having multiple GCN ISAs in one executable file. You can do it 
in different ways:

use `--amdgpu-target=` command line option
------------------------------------------
It's possible to specify multiple `--amdgpu-target=` option. Example:

```bash
# ISA for Hawaii(gfx701), Carrizo(gfx801), Tonga(gfx802) and Fiji(gfx803) would 
# be produced
hcc `hcc-config --cxxflags --ldflags` \
    --amdgpu-target=gfx701 \
    --amdgpu-target=gfx801 \
    --amdgpu-target=gfx802 \
    --amdgpu-target=gfx803 \
    foo.cpp
```

use `HCC_AMDGPU_TARGET` env var
------------------------------------------
Use `,` to delimit each AMDGPU target in HCC. Example:

```bash
export HCC_AMDGPU_TARGET=gfx701,gfx801,gfx802,gfx803
# ISA for Hawaii(gfx701), Carrizo(gfx801), Tonga(gfx802) and Fiji(gfx803) would 
# be produced
hcc `hcc-config --cxxflags --ldflags` foo.cpp
```

configure HCC use CMake `HSA_AMDGPU_GPU_TARGET` variable
---------------------------------------------------------
If you build HCC from source, it's possible to configure it to automatically
produce multiple ISAs via `HSA_AMDGPU_GPU_TARGET` CMake variable.

Use `;` to delimit each AMDGPU target. Example:

```bash
# ISA for Hawaii(gfx701), Carrizo(gfx801), Tonga(gfx802) and Fiji(gfx803) would 
# be produced by default
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DROCM_DEVICE_LIB_DIR=~hcc/ROCm-Device-Libs/build/dist/lib \
    -DHSA_AMDGPU_GPU_TARGET="gfx701;gfx801;gfx802;gfx803" \
    ../hcc
```

CodeXL Activity Logger
======================
To enable the [CodeXL Activity Logger][7], use the `USE_CODEXL_ACTIVITY_LOGGER` 
environment variable.

Configure the build in the following way: 

```bash
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DHSA_AMDGPU_GPU_TARGET=<AMD GPU ISA version string> \
    -DROCM_DEVICE_LIB_DIR=<location of the ROCm-Device-Libs bitcode> \
    -DUSE_CODEXL_ACTIVITY_LOGGER=1 \
    <ToT HCC checkout directory>
```

In your application compiled using hcc, include the CodeXL Activiy Logger header:
```
#include <CXLActivityLogger.h>
```

For information about the usage of the Activity Logger for profiling, please 
refer to its [documentation][8].

[//]: # (References)
[1]: https://github.com/RadeonOpenCompute/hcc/wiki
[2]: https://git-scm.com/book/en/v2/Git-Tools-Submodules
[3]: https://github.com/RadeonOpenCompute/ROCm-Device-Libs
[4]: https://github.com/RadeonOpenCompute/ROCm-Device-Libs#building
[5]: https://packages.debian.org/sid/libc++1
[6]: https://packages.debian.org/sid/libc++-dev
[7]: https://github.com/RadeonOpenCompute/ROCm-Profiler/tree/master/CXLActivityLogger
[8]: https://github.com/RadeonOpenCompute/ROCm-Profiler/blob/master/CXLActivityLogger/doc/AMDTActivityLogger.pdf
