cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_LIST
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Engine.cpp
    Car.cpp
)

set(TEST_LIST
    HibridCarTests.cpp
    ElectricCarTests.cpp
    PetrolCarTests.cpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME}-gt ${TEST_LIST})
target_link_libraries(${PROJECT_NAME}-gt ${PROJECT_NAME}-lib gtest_main)
enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-gt)
