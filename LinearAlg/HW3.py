import numpy as np
import scipy.linalg as linalg
import sympy

#create matrix A
A = np.array([
    [4,8,-5],
    [-3,-6,-7],
    [2,4,2]
])

#create vector b
b = np.array([
    [-1],
    [-1],
    [3]
])

#A, convert matrix into a sympy matrix
A_sympy = sympy.Matrix(A)
print(A_sympy)

#B, Reduced Echelon Form
A_rref = A_sympy.rref()
print('A_rref (from sympy):\n', A_rref)

#C,  Find the column space of A
U, S, Vt = linalg.svd(A)
rank = np.linalg.matrix_rank(A)
column_space = U[:, :rank]
print('Column space of A:\n', column_space)

#D,  Solve the matrix equation Ax=b
x = linalg.solve(A, b)
print('solved x vector\n', x)

print('A@x =\n', A@x)

# Compute the null space of A
nullA = linalg.null_space(A)
print('Null space\n', nullA)
