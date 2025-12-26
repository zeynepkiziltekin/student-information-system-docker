cmake_minimum_required(VERSION 3.10)

project(StudentInfoSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)

# PostgreSQL Kutuphanesini Bul (Docker ortaminda calisacak)
find_package(libpqxx REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(StudentInfoSystem ${SOURCES})

# Kutuphaneyi projeye bagla
target_link_libraries(StudentInfoSystem PRIVATE libpqxx::pqxx)
