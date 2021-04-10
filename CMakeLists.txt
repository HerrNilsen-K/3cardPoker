cmake_minimum_required(VERSION 3.17)
project(3cardPoker)

set(CMAKE_CXX_STANDARD 20)

include_directories(third-party/renderer/src)

add_subdirectory(third-party/renderer)

add_executable(3cardPoker main.cpp src/game.cpp src/game.h src/logic/cardShuffler.cpp src/logic/cardShuffler.h src/logic/hand.hpp src/logic/randomGenerator.hpp src/player/bankAccount.cpp src/player/bankAccount.hpp src/player/bets.cpp src/player/bets.hpp src/renderer/renderer.cpp src/renderer/renderer.hpp src/renderer/consoleRenderer.cpp src/renderer/consoleRenderer.hpp src/input/consoleInput.cpp src/input/consoleInput.hpp src/input/input.cpp src/input/input.hpp src/cards/cardsDeck.cpp src/cards/cardsDeck.hpp src/logic/calculateProfit.cpp src/logic/calculateProfit.hpp)

target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL_renderer)
