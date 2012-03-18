#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static void error(lua_State *L) {
    lua_pushstring(L, (const char*)strerror(errno));
    lua_error(L);
}

static void traversal(lua_State *L, char *fullpath, DIR *dir, int *idx) {
    struct dirent *entry;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        if (lstat(entry->d_name, &statbuf) == -1)
            error(L);
        if (S_ISREG(statbuf.st_mode)) {
            char *ptr = fullpath + strlen(fullpath);
            *ptr++ = '/';
            strcpy(ptr, entry->d_name);
            lua_pushnumber(L, (*idx)++);
            lua_pushstring(L, fullpath);
            lua_settable(L, -3);
            *--ptr = '\0';
        } else if (S_ISDIR(statbuf.st_mode)) {
            DIR *subdir = opendir(entry->d_name);
            if (subdir == NULL)
                error(L);
            if (chdir(entry->d_name) == -1)
                error(L);
            char *ptr = fullpath + strlen(fullpath);
            *ptr++ = '/';
            strcpy(ptr, entry->d_name);
            traversal(L, fullpath, subdir, idx);
            *--ptr = '\0';
            close(subdir);
            chdir("..");
        } 
    }
}

static int l_get_path(lua_State *L) {
    const char *path = luaL_checkstring(L, 1);
    DIR *dir = opendir(path);
    if (dir == NULL)
        error(L);
    if (chdir(path) == -1)
        error(L);
    lua_newtable(L);
    int idx = 1;
    const int max_len = 200;
    char fullpath[max_len];
    strcpy(fullpath, path);
    traversal(L, fullpath, dir, &idx);
    close(dir);
    chdir("..");
    return 1;
}

static const struct luaL_Reg myio[] = {
    {"get_path_r", l_get_path},
    {NULL, NULL}
};

int luaopen_myio(lua_State *L) {
    luaL_register(L, "myio", myio);
    return 1;
}
