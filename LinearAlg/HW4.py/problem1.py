import numpy as np
import scipy.linalg as linalg
import sympy

#First we defined the variables a,b,c to put in the matrix
#Then we make the matrix with the variables
#Perform row reduction to find pivots
#Pivots indicate dimensionality 
#Then we extract the pivot columns to get the basis vectors


#Define the variables
a, b, c = sympy.symbols('a b c')

#Define the vectors
v1 = sympy.Matrix([2*b + 3*c, 
                   a + b - 2*c,
                   3*a - b - c])

# Directly assign v1 to matrix
matrix = v1

#Perform row reduction to find rank aka dimension of the span
#.rref() stores 2 elements, but we will only use the pivot_columns from here
rref_matrix, pivot_columns = matrix.T.rref()

#Rank = dimension of the span
dimension = len(pivot_columns)

# Extracts the columns of the matrix corresponding to the pivot 
# columns to form the basis vectors
basis = [matrix.col(i) for i in pivot_columns]

print(f"Dimension of the set: {dimension}")
print("Basis for the set: ")
for vec in basis:
    print(vec)
