from ctypes import cdll, c_bool, c_void_p, c_int, pointer, byref, POINTER
from _ctypes import Array


inc_lib = cdll.LoadLibrary("sudoku.so")

a_list = [
            [5, 3, 0, 0, 7, 0, 0, 0, 0],
            [6, 0, 0, 1, 9, 5, 0, 0, 0],
            [0, 9, 8, 0, 0, 0, 0, 6, 0],
            [8, 0, 0, 0, 6, 0, 0, 0, 3],
            [4, 0, 0, 8, 0, 3, 0, 0, 1],
            [7, 0, 0, 0, 2, 0, 0, 0, 6],
            [0, 6, 0, 0, 0, 0, 2, 8, 0],
            [0, 0, 0, 4, 1, 9, 0, 0, 5],
            [0, 0, 0, 0, 8, 0, 0, 7, 9],
]

arr_0 = (c_int * len(a_list))(*a_list[0])
print(arr_0)
for i in arr_0:
    print(i)
solve = inc_lib.solve
solve.restype = c_bool

printer = inc_lib.print()

print(solve(byref(arr_0)))
printer()
