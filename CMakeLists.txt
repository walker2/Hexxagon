cmake_minimum_required(VERSION 3.5)
project(Hexxagon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Hexxagon_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SFML 2 REQUIRED window system graphics network audio)

include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Hex.h Game.h Game.cpp HexHash.h Board.cpp Board.h States/Game_State.h States/Intro_State.cpp
        States/Intro_State.h States/Menu_State.cpp States/Menu_State.h States/GameStates.h States/Multiplayer_State.cpp
        States/Multiplayer_State.h Player.cpp Player.h ResourceManager.cpp ResourceManager.h GameGUI.cpp GameGUI.h
        States/Difficulty_Singleplayer_State.cpp States/Difficulty_Singleplayer_State.h
        States/Difficulty_Computerwars_State.cpp States/Difficulty_Computerwars_State.h)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
add_executable(Hexxagon ${SOURCE_FILES})
target_link_libraries(Hexxagon ${SFML_LIBRARIES})