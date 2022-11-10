cmake_minimum_required(VERSION 3.16)

set(TARGET_NAME qwe)

set(QT_MAJOR_VERSION 6) # Works fine if set to "5"

project(${TARGET_NAME} VERSION 0.0.1 DESCRIPTION "Project Description")

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt${QT_MAJOR_VERSION}
  COMPONENTS Widgets WebEngineCore WebEngineWidgets REQUIRED)

add_executable(${TARGET_NAME}
    src/Widget.cpp
    src/Widget.h
    src/main.cpp)
    
if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

target_include_directories(${TARGET_NAME} PRIVATE
  ${Qt${QT_MAJOR_VERSION}_INCLUDE_DIRS})
target_include_directories(${TARGET_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${TARGET_NAME} PROPERTIES
  DEBUG_OUTPUT_NAME "${TARGET_NAME}d"
  RELEASE_OUTPUT_NAME ${TARGET_NAME})

#Add any extra libs to link also.
target_link_libraries(${TARGET_NAME} PRIVATE
  Qt${QT_MAJOR_VERSION}::Widgets
  Qt${QT_MAJOR_VERSION}::WebEngineCore
  Qt${QT_MAJOR_VERSION}::WebEngineWidgets)

