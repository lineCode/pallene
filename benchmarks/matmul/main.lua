local matmul = require(arg[1])

--local function print_mat(A)
--    for i = 1, #A do
--        print(table.concat(A[i], " "))
--    end
--end

local N = 800
--local N = 400
--local N = 200
--local N = 100

local BIG1 = {}
for i = 1, N do
    BIG1[i] = {}
    for j = 1, N do
        BIG1[i][j] = (i + j) * 3.1415
    end
end

local BIG2 = BIG1

local C
for _ = 1, 2 do
--for _ = 1, 16 do
--for _ = 1, 128 do
--for _ = 1, 1024 do
    C = matmul.matmul(BIG1, BIG2)
end
print("#C", #C, #C[1])
print("C[1][1]", C[1][1])
--print_mat(C)
