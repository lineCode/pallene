local util = require "titan-compiler.util"

describe("Titanc", function()
    before_each(function()
        util.set_file_contents("test.titan", [[
            function f(x:integer): integer
                return x + 17
            end
        ]])
        util.set_file_contents("test_script.lua", [[
            local test = require "test"
            print(test.f(0))
        ]])
    end)

    after_each(function()
        os.execute("rm -f test.titan")
        os.execute("rm -f test.c")
        os.execute("rm -f test.s")
        os.execute("rm -f test.so")
        os.execute("rm -f test_script.lua")
    end)

    it("Can compile titan files", function()
        util.shell("./titanc test.titan")
        local out = util.shell("./lua/src/lua test_script.lua")
        assert.equals("17\n", out)
    end)

    it("Can compile C files", function()
        util.shell("./titanc --emit-c test.titan")
        util.shell("./titanc --compile-c test.c")
        local out = util.shell("./lua/src/lua test_script.lua")
        assert.equals("17\n", out)
    end)

    it("Can create asm files", function()
        util.shell("./titanc --emit-c test.titan")
        util.shell("./titanc --emit-asm test.c")
        local s, err = util.get_file_contents("test.s")
        assert.is_truthy(s)
    end)
end)
