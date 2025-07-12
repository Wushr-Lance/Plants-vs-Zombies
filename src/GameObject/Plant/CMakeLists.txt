cmake_minimum_required(VERSION 3.16)

add_library(
  Plant
  STATIC
  PlantBase.hpp
  PlantBase.cpp
  Sunflower.hpp
  Sunflower.cpp
  Peashooter.hpp
  Peashooter.cpp
  Wallnut.hpp
  Wallnut.cpp
  CherryBomb.hpp
  CherryBomb.cpp
)

target_link_libraries(
    Plant
    GameObject
)

target_include_directories(
  Plant
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
