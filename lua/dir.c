#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"

static int dir_iter(lua_State *L);

static int l_dir(lua_State *L) {
    const char *path = luaL_checkstring(L, 1);
    DIR **d = (DIR **)lua_newuserdata(L, sizeof(DIR *));  /* new userdata*/
    luaL_getmetatable(L, "LuaBook.dir");  /* get metatable */
    lua_setmetatable(L, -2);  /* set metatable for userdata */
    *d = opendir(path);
    if (*d == NULL)
        luaL_error(L, "cannot open %s: %s", path, strerror(errno));
    lua_pushcclosure(L, dir_iter, 1);  /* upvalue already at the top of stack */
    return 1;
}

static int dir_iter(lua_State *L) {
    DIR *d = *(DIR **)lua_touserdata(L, lua_upvalueindex(1));
    struct dirent *entry;
    if ((entry = readdir(d)) != NULL) {
        lua_pushstring(L, entry->d_name);
        return 1;
    } else {
        return 0;
    }
}

static int dir_gc(lua_State *L) {
    DIR *d = *(DIR **)lua_touserdata(L, 1);
    if (d) closedir(d);
    return 0;
}

int luaopen_dir(lua_State *L) {
    luaL_newmetatable(L, "LuaBook.dir");
    lua_pushstring(L, "__gc");
    lua_pushcfunction(L, dir_gc);
    lua_settable(L, -3);
    lua_pushcfunction(L, l_dir);
    lua_setglobal(L, "dir");
    return 0;
}
