cmake_minimum_required(VERSION 3.10)
project(AlchemyShop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp Product.cpp SacredIngredient.cpp CursedIngredient.cpp Potion.cpp Shop.cpp Player.cpp
        Menu.h
        Menu.cpp
        Exceptions.h)

add_executable(AlchemyShop ${SOURCES})
