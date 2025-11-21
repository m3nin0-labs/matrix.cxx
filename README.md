# matrix.cxx

C++ Header with matrix operations

## Building

### Using Conan (Recommended)

Install Conan 2.x if you haven't already:

```bash
pip install conan
```

Install dependencies:

```bash
conan install . --output-folder=build --build=missing
```

Configure and build with CMake:

```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake
cmake --build build
```

### Without Conan

Simply use CMake directly:
```bash
cmake -S . -B build
cmake --build build
```

## Using OpenMP

matrix.cxx uses OpenMP in some methods. To set the number of threads used, use the `OMP_NUM_THREADS` environment variable.

OpenMP can be enabled/disabled with:
```bash
cmake -DENABLE_OPENMP=ON ..   # Enable (default)
cmake -DENABLE_OPENMP=OFF ..  # Disable
```
