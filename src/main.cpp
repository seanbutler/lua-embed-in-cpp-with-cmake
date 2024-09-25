#include <iostream>
#include "lua.hpp"

int main(int argc, char **argv)
{
    // Create a new Lua state
    lua_State *L = luaL_newstate();

    if (L == nullptr)
    {
        std::cerr << "Failed to create Lua state!" << std::endl;
        return -1;
    }

    // Load the Lua libraries (optional but useful for standard functions like print)
    luaL_openlibs(L);

    // Run a Lua script
    if (luaL_dofile(L, "hello_world.lua") != LUA_OK)
    {
        std::cerr << "Error: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1); // Remove error message from the stack
    }

    // Close the Lua state
    lua_close(L);

    return 0;
}