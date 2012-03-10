#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static int l_dir(lua_State *L) {
    DIR *dir;
    struct dirent *entry;
    int i;
    const char *path = luaL_checkstring(L, 1);
    dir = opendir(path);
    if (dir == NULL) {
        lua_pushnil(L);
        lua_pushstring(L, (const char*)strerror(errno));
        return 2;
    }
    lua_newtable(L);
    i = 1;
    while ((entry = readdir(dir)) != NULL) {
        lua_pushnumber(L, i++);
        lua_pushstring(L, entry->d_name);
        lua_settable(L, -3);
    }
    closedir(dir); /*maybe memory leak*/
    return 1;
}

static int l_map(lua_State *L) {
    int i;
    luaL_checktype(L, 1, LUA_TTABLE);
    luaL_checktype(L, 2, LUA_TFUNCTION);
    int n = lua_objlen(L, 1);
    for (i = 1; i <= n; ++i) {
        lua_pushvalue(L, 2);
        lua_rawgeti(L, 1, i);
        /*void lua_call (lua_State *L, int nargs, int nresults);*/
        lua_call(L, 1, 1);
        lua_rawseti(L, 1, i);
    }
    return 0;
}

static const struct luaL_Reg mylib[] = {
    {"dir", l_dir},
    {"map", l_map},
    {NULL, NULL}
};

int luaopen_mylib(lua_State *L) {
    luaL_register(L, "mylib", mylib);
    return 1;
}
