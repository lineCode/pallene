-- vim: set filetype=lua : --

-- Luacheck configuration file[1]
--
-- How to use Luacheck:
--    - luarocks install luacheck
--    - luacheck ./titan-compiler
--
-- Luacheck can also be integrated with vim, through Syntastic[2]:
--    - let g:syntastic_lua_checkers = ['luac', 'luacheck']
--
-- [1] https://luacheck.readthedocs.io/en/stable/config.html
-- [2] https://github.com/vim-syntastic/syntastic

ignore = {
    "212/_.*",  -- Unused argument, when name starts with "_"
    "212/self", -- Unused argument "self"

    "411/ok",    -- Redefining local "ok"
    "411/errs?", -- Redefining local "err" or "errs"

    "421/ok",    -- Shadowing local "ok"
    "421/errs?", -- Shadowing local "err" or "errs"

    "542", -- Empty if branch.
    "6..", -- Whitespace warnings
}
