cmake_minimum_required(VERSION 3.16)

add_library(
  Zombie
  STATIC
  ZombieBase.hpp
  ZombieBase.cpp
  RegularZombie.hpp
  RegularZombie.cpp
)

target_link_libraries(
    Zombie
    GameObject
)

target_include_directories(
  Zombie
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
