cmake_minimum_required(VERSION 3.25)
project(Magical_Iterators_a)

set(CMAKE_CXX_STANDARD 17)

add_executable(Magical_Iterators_a Demo.cpp sources/MagicalContainer.cpp sources/MagicalContainer.hpp sources/DoublyLinkedList.cpp sources/DoublyLinkedList.h Test.cpp)
