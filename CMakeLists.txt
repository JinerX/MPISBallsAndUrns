cmake_minimum_required(VERSION 3.28)
project(MPISBallsAndBins)

set(CMAKE_CXX_STANDARD 17)

# Find Python
find_package(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)

if(Python3_FOUND)
    message(STATUS "Found Python3: ${Python3_EXECUTABLE}")
    include_directories(${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
    link_directories(${Python3_LIBRARY_DIRS})
    set(PYTHON_LIBRARY ${Python3_LIBRARIES})
else()
    message(FATAL_ERROR "Python3 not found. Please install Python3 and required modules.")
endif()

# Add include and source directories
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

#add_executable(MPISBallsAndBins main.cpp
#        include/experiments.h
#        src/experiments.cpp
#        include/plots.h
#        src/plots.cpp)

# Add executable
add_executable(${PROJECT_NAME} main.cpp ${SOURCES}
        include/funcWrapper.h
        src/funcWrapper.cpp)

# Link Python library
target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARY})
