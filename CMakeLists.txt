cmake_minimum_required(VERSION 3.5)

project (myapp)
set(TARGET myapp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LUA_VERSION "lua-5.4.7")

include(ExternalProject)

ExternalProject_Add(lua_project
  PREFIX ${CMAKE_BINARY_DIR}/${LUA_VERSION}
  URL https://www.lua.org/ftp/${LUA_VERSION}.tar.gz
  CONFIGURE_COMMAND ""
  BUILD_COMMAND make generic
  INSTALL_COMMAND ""
  BUILD_IN_SOURCE true
  DOWNLOAD_EXTRACT_TIMESTAMP false
)

# Specify where to find Lua includes and libraries after building
ExternalProject_Get_Property(lua_project BINARY_DIR)
set(LUA_INCLUDE_DIR ${BINARY_DIR}/src)
set(LUA_LIBRARIES ${BINARY_DIR}/src/liblua.a)

# Add your C++ executable
add_executable(${TARGET}  ./src/main.cpp)

# Link your executable to the Lua library
add_dependencies(${TARGET} lua_project) # Ensure Lua is built before your project
target_include_directories(${TARGET} PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(${TARGET} PRIVATE ${LUA_LIBRARIES})
target_link_libraries(${TARGET} PRIVATE m)

