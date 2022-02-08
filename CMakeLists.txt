cmake_minimum_required(VERSION 3.20)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project (${ProjectId})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

find_package(GTest REQUIRED)

add_executable(${ProjectId} # WIN32
    SBomberProject.cpp
    
    SBomber.h
    SBomber.cpp
    
    LevelGUI.h
    LevelGUI.cpp
    
    Plane.h
    Plane.cpp
    
    Bomb.h
    Bomb.cpp
    
    Ground.h
    Ground.cpp
    
    Tank.h
    Tank.cpp
    
    House.h
    House.cpp
    
    DynamicObject.h
    DestroyableGroundObject.h
    GameObject.h
    
    FileLoggerSingleton/FileLoggerSingleton.h
    FileLoggerSingleton/FileLoggerSingleton.cpp
)


