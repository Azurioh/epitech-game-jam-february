cmake_minimum_required(VERSION 3.10)

project(BloonsIllusionTowerDefense7+PremiumDeluxeDefinitiveEditionCollectorReloaded)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 4.5.0
)
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

set(COMMON_LIBS raylib m pthread dl)
set(LINUX_LIBS GL rt X11 config++)
set(MACOS_LIBS "-framework OpenGL" "-framework CoreFoundation")
set(MACOS_INCLUDE_PATH "-I /opt/homebrew/include")
set(MACOS_LIB_PATH "-L /opt/homebrew/lib")

if(APPLE)
    set(LIBS ${COMMON_LIBS} ${MACOS_LIBS} ${MACOS_LIB_PATH})
    add_compile_options(${MACOS_INCLUDE_PATH})
elseif(UNIX)
    set(LIBS ${COMMON_LIBS} ${LINUX_LIBS})
endif()

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_SOURCE_DIR}/src)
