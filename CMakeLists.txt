cmake_minimum_required(VERSION 3.22)
project(qubiq_solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(qubiq_solver config_file.cpp relations.cpp solver.cpp particle_state.cpp main.cpp)
