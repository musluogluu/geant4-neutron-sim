cmake_minimum_required(VERSION 3.16)
project(NeutronSim)

find_package(Geant4 REQUIRED ui_all)

include(${Geant4_USE_FILE})
include_directories(include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(neutronSim main.cc ${sources} ${headers})
target_link_libraries(neutronSim ${Geant4_LIBRARIES})
