cmake_minimum_required(VERSION 3.16)

add_library(
  Projectile
  STATIC
  Pea.hpp
  Pea.cpp
  Explosion.hpp
  Explosion.cpp
)

target_link_libraries(
    Projectile
    GameObject
)

target_include_directories(
  Projectile
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
