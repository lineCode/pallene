/* This file was generated by the Titan compiler. Do not edit by hand */
/* Indentation and formatting courtesy of titan-compiler/pretty.lua */

#include <string.h>

#include "tcore.h"

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lfunc.h"
#include "lgc.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "lvm.h"

#include "math.h"

static int function_istriple_titan(
    lua_State * L,
    lua_Integer x1 /* a */,
    lua_Integer x2 /* b */,
    lua_Integer x3 /* c */
){
    CClosure * x4 = clCvalue(s2v(L->ci->func));
    Table * x5 /* upvalue table */ = hvalue(&x4->upvalue[0]);
    TValue * x6 /* upvalue array */ = x5->array;
    (void)x6;
    {
        lua_Integer x7 = intop(*, x1, x1);
        lua_Integer x8 = intop(*, x2, x2);
        lua_Integer x9 = intop(+, x7, x8);
        lua_Integer x10 = intop(*, x3, x3);
        int x11 = x9 == x10;
        return x11;
    }
}

static int function_istriple_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 3)) {
        titan_runtime_arity_error(L, 3, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisinteger(x6))) {
        titan_runtime_argument_type_error(L, "a", 1, LUA_TNUMINT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisinteger(x7))) {
        titan_runtime_argument_type_error(L, "b", 1, LUA_TNUMINT, x7);
    }
    TValue* x8 = s2v(x4 + 3);
    if (TITAN_UNLIKELY(!ttisinteger(x8))) {
        titan_runtime_argument_type_error(L, "c", 1, LUA_TNUMINT, x8);
    }
    lua_Integer x9 = ivalue(s2v(x4 + 1));
    lua_Integer x10 = ivalue(s2v(x4 + 2));
    lua_Integer x11 = ivalue(s2v(x4 + 3));
    int x12 /* ret */ = function_istriple_titan(L, x9, x10, x11);
    setbvalue(s2v(L->top), x12);
    api_incr_top(L);
    return 1;
}

static Table * function_pyth_titan(
    lua_State * L,
    lua_Integer x1 /* N */
){
    lua_checkstack(L, 3);
    CClosure * x2 = clCvalue(s2v(L->ci->func));
    Table * x3 /* upvalue table */ = hvalue(&x2->upvalue[0]);
    TValue * x4 /* upvalue array */ = x3->array;
    (void)x4;
    {


        lua_Integer x5 /* nsol */ = 0;

        Table * x6 = luaH_new(L);
        luaH_resizearray(L, x6, 0);
        TValue * x7 = x6->array;
        (void) x7;
        Table * x8 /* xs */ = x6;


        Table * x10 = luaH_new(L);
        luaH_resizearray(L, x10, 0);
        TValue * x11 = x10->array;
        (void) x11;
        Table * x12 /* ys */ = x10;


        Table * x14 = luaH_new(L);
        luaH_resizearray(L, x14, 0);
        TValue * x15 = x14->array;
        (void) x15;
        Table * x16 /* zs */ = x14;

        StackValue* x29 = L->top;
        sethvalue(L, s2v(x29), x8); x29++;
        sethvalue(L, s2v(x29), x12); x29++;
        sethvalue(L, s2v(x29), x16); x29++;
        L->top = x29;

        lua_Integer x17 /* start */ = 1;
        lua_Integer x18 /* finish */ = x1;
        lua_Integer x19 /* inc */ = 1;
        while ((x19 >= 0 ? x17 <= x18 : x17 >= x18)) {
            lua_Integer x20 /* x */ = x17;
            (void) x20;
            {
                lua_Integer x21 /* start */ = 1;
                lua_Integer x22 /* finish */ = x1;
                lua_Integer x23 /* inc */ = 1;
                while ((x23 >= 0 ? x21 <= x22 : x21 >= x22)) {
                    lua_Integer x24 /* y */ = x21;
                    (void) x24;
                    {
                        lua_Integer x25 /* start */ = 1;
                        lua_Integer x26 /* finish */ = x1;
                        lua_Integer x27 /* inc */ = 1;
                        while ((x27 >= 0 ? x25 <= x26 : x25 >= x26)) {
                            lua_Integer x28 /* z */ = x25;
                            (void) x28;
                            {
                                {
                                    int x30 = function_istriple_titan(L, x20, x24, x28);
                                    if (x30) {
                                        lua_Integer x31 = intop(+, x5, 1);
                                        x5 = x31;
                                        lua_Unsigned x32 /* ui */ = ((lua_Unsigned)x5) - 1;
                                        if (TITAN_UNLIKELY(x32 >= x8->sizearray)) {
                                            titan_renormalize_array(L, x8, x32, 16);
                                        }
                                        TValue * x33 /* slot */ = &x8->array[x32];
                                        setivalue(x33, x20);
                                        lua_Unsigned x34 /* ui */ = ((lua_Unsigned)x5) - 1;
                                        if (TITAN_UNLIKELY(x34 >= x12->sizearray)) {
                                            titan_renormalize_array(L, x12, x34, 17);
                                        }
                                        TValue * x35 /* slot */ = &x12->array[x34];
                                        setivalue(x35, x24);
                                        lua_Unsigned x36 /* ui */ = ((lua_Unsigned)x5) - 1;
                                        if (TITAN_UNLIKELY(x36 >= x16->sizearray)) {
                                            titan_renormalize_array(L, x16, x36, 18);
                                        }
                                        TValue * x37 /* slot */ = &x16->array[x36];
                                        setivalue(x37, x28);
                                    }
                                }
                            }
                            x25 = intop(+, x25, x27);
                        }
                    }
                    x21 = intop(+, x21, x23);
                }
            }
            x17 = intop(+, x17, x19);
        }
        luaC_condGC(L, {
            StackValue* x38 = L->top;
            sethvalue(L, s2v(x38), x8); x38++;
            sethvalue(L, s2v(x38), x12); x38++;
            sethvalue(L, s2v(x38), x16); x38++;
            L->top = x38;
        }, {
            L->top -= 3;
        });
        Table * x39 = luaH_new(L);
        luaH_resizearray(L, x39, 0);
        TValue * x40 = x39->array;
        (void) x40;
        Table * x41 /* out */ = x39;
        lua_Unsigned x42 /* ui */ = ((lua_Unsigned)1) - 1;
        if (TITAN_UNLIKELY(x42 >= x41->sizearray)) {
            titan_renormalize_array(L, x41, x42, 25);
        }
        TValue * x43 /* slot */ = &x41->array[x42];
        sethvalue(L, x43, x8);
        if (isblack(obj2gco(x41)) && iswhite(obj2gco(x8))) {
            luaC_barrierback_(L, obj2gco(x41));
        }
        lua_Unsigned x44 /* ui */ = ((lua_Unsigned)2) - 1;
        if (TITAN_UNLIKELY(x44 >= x41->sizearray)) {
            titan_renormalize_array(L, x41, x44, 26);
        }
        TValue * x45 /* slot */ = &x41->array[x44];
        sethvalue(L, x45, x12);
        if (isblack(obj2gco(x41)) && iswhite(obj2gco(x12))) {
            luaC_barrierback_(L, obj2gco(x41));
        }
        lua_Unsigned x46 /* ui */ = ((lua_Unsigned)3) - 1;
        if (TITAN_UNLIKELY(x46 >= x41->sizearray)) {
            titan_renormalize_array(L, x41, x46, 27);
        }
        TValue * x47 /* slot */ = &x41->array[x46];
        sethvalue(L, x47, x16);
        if (isblack(obj2gco(x41)) && iswhite(obj2gco(x16))) {
            luaC_barrierback_(L, obj2gco(x41));
        }

        L->top -= 3;

        return x41;
    }
}

static int function_pyth_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 1)) {
        titan_runtime_arity_error(L, 1, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisinteger(x6))) {
        titan_runtime_argument_type_error(L, "N", 5, LUA_TNUMINT, x6);
    }
    lua_Integer x7 = ivalue(s2v(x4 + 1));
    Table * x8 /* ret */ = function_pyth_titan(L, x7);
    sethvalue(L, s2v(L->top), x8);
    api_incr_top(L);
    return 1;
}

int luaopen_benchmarks_pythagoras_saveearly(lua_State *L)
{
    lua_checkstack(L, 4);
    /* Allocate upvalue table */
    /* ---------------------- */
    Table * x1 = luaH_new(L);
    luaH_resizearray(L, x1, 4);
    TValue * x2 = x1->array;
    /* Initialize upvalues */
    /* ------------------- */
    TString * x3 = luaS_new(L, "__index");
    setsvalue(L,  &x2[0] , x3);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x3))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x4 = luaS_new(L, "__metatable");
    setsvalue(L,  &x2[1] , x4);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x4))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* istriple */
    CClosure* x5 = luaF_newCclosure(L, 1);
    x5->f = function_istriple_lua;
    sethvalue(L, &x5->upvalue[0], x1);
    TValue x6; setclCvalue(L, &x6, x5);
    setobj(L,  &x2[2] , &x6);
    if (iscollectable(&x6) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x6))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* pyth */
    CClosure* x7 = luaF_newCclosure(L, 1);
    x7->f = function_pyth_lua;
    sethvalue(L, &x7->upvalue[0], x1);
    TValue x8; setclCvalue(L, &x8, x7);
    setobj(L,  &x2[3] , &x8);
    if (iscollectable(&x8) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x8))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* Create exports table */
    /* -------------------- */
    StackValue* x9 = L->top;
    sethvalue(L, s2v(x9), x1); x9++;
    L->top = x9;
    lua_createtable(L, 0, 2);
    lua_pushstring(L, "istriple");
    setobj(L, s2v(L->top),  &x2[2] ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "pyth");
    setobj(L, s2v(L->top),  &x2[3] ); api_incr_top(L);
    lua_settable(L, -3);
    return 1;
}

