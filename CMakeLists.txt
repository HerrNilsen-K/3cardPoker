cmake_minimum_required(VERSION 3.17)
project(3cardPoker)

set(CMAKE_CXX_STANDARD 20)

add_executable(3cardPoker main.cpp src/game.cpp src/game.h src/logic/cardShuffler.cpp src/logic/cardShuffler.h src/logic/hand.hpp src/logic/randomGenerator.hpp src/player/bankAccount.cpp src/player/bankAccount.hpp)