#include <limits.h>
#include "lua.h"
#include "lauxlib.h"
#define BITS_PER_WORD (CHAR_BIT * sizeof(unsigned int))
#define I_WORD(i)     ((unsigned int)(i) / BITS_PER_WORD)
#define I_BIT(i)      (1 << ((unsigned int)(i) % BITS_PER_WORD))
#define checkarray(L) \
            (NumArray *)luaL_checkudata(L, 1, "LuaBook.array")

typedef struct NumArray {
    int size;
    unsigned int values[1];
} NumArray;

static int newarray(lua_State *L) {
    int i, n;
    size_t nbytes;
    NumArray *a;
    n = luaL_checkint(L, 1);
    luaL_argcheck(L, n >= 1, 1, "invalid size");
    nbytes = sizeof(NumArray) + I_WORD(n - 1) * sizeof(unsigned int);
    a = (NumArray *)lua_newuserdata(L, nbytes);
    a->size = n;
    for (i = 0; i <= I_WORD(n - 1); ++i)
        a->values[i] = 0;
    luaL_getmetatable(L, "LuaBook.array");
    lua_setmetatable(L, -2);
    return 1;
}

static unsigned int *getindex(lua_State *L, unsigned int *mask) {
    NumArray *a = checkarray(L);
    int index = luaL_checkint(L, 2) - 1;
    luaL_argcheck(L, 0 <= index && index < a->size, 2, "index out of range");
    *mask = I_BIT(index);
    return &a->values[I_WORD(index)];
}

static int setarray(lua_State *L) {
    /*NumArray *a = (NumArray *)lua_touserdata(L, 1);
    int index = luaL_checkint(L, 2) - 1;
    luaL_checkany(L, 3);
    luaL_argcheck(L, a != NULL, 1, "'array' expected");
    luaL_argcheck(L, 0 <= index && index < a->size, 2, "index out of range");
    if (lua_toboolean(L, 3))
        a->values[I_WORD(index)] |= I_BIT(index);
    else
        a->values[I_WORD(index)] &= ~I_BIT(index);
    return 0;*/
    unsigned int mask;
    unsigned int *entry = getindex(L, &mask);
    luaL_checkany(L, 3);
    if (lua_toboolean(L, 3))
        *entry |= mask;
    else
        *entry &= ~mask;
    return 0;
}

static int getarray(lua_State *L) {
    /*NumArray *a = (NumArray *)lua_touserdata(L, 1);
    int index = luaL_checkint(L, 2) - 1;
    luaL_argcheck(L, a != NULL, 1, "'array' expected");
    luaL_argcheck(L, 0 <= index && index < a->size, 2, "index out of range");
    lua_pushboolean(L, a->values[I_WORD(index)] & I_BIT(index)); 
    return 1;*/
    unsigned int mask;
    unsigned int *entry = getindex(L, &mask);
    lua_pushboolean(L, *entry & mask);
    return 1;
}

static int getsize(lua_State *L) {
    NumArray *a = (NumArray *)lua_touserdata(L, 1);
    luaL_argcheck(L, a != NULL, 1, "'array' expected");
    lua_pushinteger(L, a->size);
    return 1;
}

static int array2string(lua_State *L) {
    NumArray *a = checkarray(L);
    lua_pushfstring(L, "array(%d)", a->size);
    return 1;
}

/*static const struct luaL_Reg arraylib[] = {
    {"new", newarray},
    {"set", setarray},
    {"get", getarray},
    {"size", getsize},
    {NULL, NULL},
};*/

static const struct luaL_Reg arraylib_f[] = {
    {"new", newarray},
    {NULL, NULL}
}; 

static const struct luaL_Reg arraylib_m[] = {
    {"set", setarray},
    {"get", getarray},
    {"size", getsize},
    {"__newindex", setarray},
    {"__index", getarray},
    {"__len", getsize},
    {"__tostring", array2string},

    {NULL, NULL},
};

int luaopen_array(lua_State *L) {
    luaL_newmetatable(L, "LuaBook.array");
    luaL_register(L, NULL, arraylib_m);
    luaL_register(L, "array", arraylib_f);
    return 1;
}
