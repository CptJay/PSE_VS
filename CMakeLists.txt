cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES
        src/main.cpp
        src/DesignByContract.h

        TinyXML/tinyxml.h TinyXML/tinyxml.cpp TinyXML/tinystr.h TinyXML/tinystr.cpp TinyXML/tinyxmlerror.cpp TinyXML/tinyxmlparser.cpp

        src/Verkeerssimulatie.cpp src/Verkeerssimulatie.h
        src/Baan.cpp src/Baan.h
        src/Verkeerslicht.cpp src/Verkeerslicht.h
        src/Voertuig.cpp src/Voertuig.h
        src/Parser.h src/Parser.cpp
        src/Bushalte.cpp src/Bushalte.h
        src/Kruispunt.cpp src/Kruispunt.h)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES
        src/tests/projectTests.cpp src/tests/projectDomainTests.cpp src/tests/projectInputTests.cpp src/tests/projectOutputTests.cpp
        src/DesignByContract.h

        TinyXML/tinyxml.h TinyXML/tinyxml.cpp TinyXML/tinystr.h TinyXML/tinystr.cpp TinyXML/tinyxmlerror.cpp TinyXML/tinyxmlparser.cpp

        src/Verkeerssimulatie.cpp src/Verkeerssimulatie.h
        src/Verkeerslicht.cpp src/Verkeerslicht.h
        src/Voertuig.cpp src/Voertuig.h
        src/Baan.h src/Baan.cpp
        src/Parser.h src/Parser.cpp
        src/Bushalte.cpp src/Bushalte.h
        src/Kruispunt.cpp src/Kruispunt.h
        src/projectImporter.cpp src/projectImporter.h
        src/projectExporter.cpp src/projectExporter.h
        src/projectUtils.cpp src/projectUtils.h src/Voertuiggenerator.cpp src/Voertuiggenerator.h)

# Create RELEASE target
add_executable(ttt ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(ttt_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ttt_debug gtest)