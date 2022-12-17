cmake_minimum_required(VERSION 3.23)
project(ProjektHaslo)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjektHaslo main.cpp Account.cpp Account.h CategoryRepository.cpp CategoryRepository.h AccountRepository.cpp AccountRepository.h Coder.cpp Coder.h Service.cpp Service.h Validator.cpp Validator.h)
