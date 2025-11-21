cmake_minimum_required (VERSION 3.15)

# Include Conan-generated toolchain (must be before project())
# Conan generates this when you run: conan install . --output-folder=build
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/build/conan_toolchain.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/build/conan_toolchain.cmake")
endif()

project (MatrixH)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

# Option to enable/disable OpenMP
# Default is ON, but can be overridden with -DENABLE_OPENMP=ON/OFF
option(ENABLE_OPENMP "Enable OpenMP support" ON)

add_executable (MatrixH ${source_files})

# Find and link OpenMP if enabled
if(ENABLE_OPENMP)
    find_package(OpenMP)
    
    if(OpenMP_CXX_FOUND)
        message(STATUS "OpenMP found, enabling parallelization")
        target_link_libraries(MatrixH PRIVATE OpenMP::OpenMP_CXX)
        target_compile_definitions(MatrixH PRIVATE HAVE_OPENMP)
    else()
        message(WARNING "OpenMP requested but not found, building without OpenMP support")
    endif()

else()
    message(STATUS "OpenMP disabled by user")

endif()
