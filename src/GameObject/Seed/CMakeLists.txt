cmake_minimum_required(VERSION 3.16)

add_library(
  Seed
  STATIC
  Seed.hpp
  Seed.cpp
  SeedBase.hpp
  SeedBase.cpp
)

target_link_libraries(
    Seed
    GameObject
)

target_include_directories(
  Seed
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
