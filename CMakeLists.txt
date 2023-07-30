# CMakeList.txt : CMake project for IMGUI Test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("IMGUI Test")

# https://brendanwhitfield.wordpress.com/2015/02/26/using-cmake-with-sdl2/
# https://discourse.libsdl.org/t/new-cmake-usage/37675/3
# https://stackoverflow.com/questions/10765885/how-to-install-your-custom-cmake-find-module
# https://wiki.libsdl.org/SDL2/README/cmake
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_SOURCE_DIR}/ext/sdl2/cmake")
set(SDL2_LIBRARY ${SDL2_LIBRARY} SDL2::SDL2 SDL2::SDL2main)
#set(SDL2_INCLUDE_DIR ${SDL2_INCLUDE_DIR} "${CMAKE_SOURCE_DIR}/ext/sdl2/include")

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

#include_directories(${SDL2_INCLUDE_DIR})

# Add source to this project's executable.
add_executable (IMGUITest "IMGUI Test.cpp" "IMGUI Test.h")

# ----- Dependencies -----

target_link_libraries(IMGUITest PRIVATE ${SDL2_LIBRARY})

# TODO: Add tests and install targets if needed.
