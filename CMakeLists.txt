cmake_minimum_required(VERSION 3.10)
project(SentinelTrace VERSION 2.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define directories
include_directories(src/include)

# Source files
set(SOURCES 
    src/main.cpp 
    src/modules/IngestionEngine.cpp 
    src/modules/ReasoningEngine.cpp 
    src/modules/AlertManager.cpp
)

# Executable
add_executable(SentinelTrace ${SOURCES})

# Target properties (output name)
set_target_properties(SentinelTrace PROPERTIES OUTPUT_NAME "SentinelTrace")