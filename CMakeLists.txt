cmake_minimum_required(VERSION 3.10)
project(CopyControl)

set(CMAKE_CXX_STANDARD 11)

add_executable(CopyControl main.cpp List.h DoublyLinkedNode.h DoublyLinkedNodeIterator.h DynamicStack.h DynamicStackIterator.h DynamicQueue.h DynamicQueueIterator.h)