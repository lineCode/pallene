local Complex = require(arg[1])

local function level(x, y)
    local c = Complex.new(x, y)
    local z = Complex.clone(c)
    local l = 0
    repeat
        z = Complex.add(Complex.mul(z, z), c)
        l = l + 1
    until Complex.abs(z) > 2.0 or l > 255
    return l - 1
end

local xmin = -2.0
local xmax = 2.0
local ymin = -2.0
local ymax = 2.0
local N = 256

local dx = (xmax - xmin) / N
local dy = (ymax - ymin) / N

print("P2")
--print("# mandelbrot set", xmin, xmax, ymin, ymax, N)
print(N, N, 255)

for i = 1, N do
    local x = xmin + (i - 1) * dx
    for j = 1, N do
        local y = ymin + (j - 1) * dy
        print(level(x, y))
    end
end

