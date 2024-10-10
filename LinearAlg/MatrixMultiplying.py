import numpy as np
import scipy.linalg as linalg
import sympy
import sys

#Just for fun, program to test user input matrix multiplying

print("This program will test Matrix Multiplication")
print("Remember matrix multiplication only works for matching Matrices:")
print("For example, 2x2 & 2x1 will work, but 3x2 and 3x2 won't")

print() #Blank Line
rows_A = int(input("Enter the number of rows for Matrix A: "))
cols_A = int(input("Enter the number of columns for Matrix A: "))
print() #Blank Line

rows_B = int(input("Enter the number of rows for Matrix B: "))
cols_B = int(input("Enter the number of columns for matrix B: "))
print() #Blank Line

if cols_A != rows_B:
    print("Error: Matrices can't be multiplied, non-matching rows/cols")
    sys.exit(1) # Exit program with non-zero status

print("Generating Matrices A & B")
A = np.random.randint(-9, 9, (rows_A, cols_A))
print('Matrix A\n', A)
print()
B = np.random.randint(-9, 9, (rows_B, cols_B))
print('Matrix B\n', B)

#do the matrix multplication
result = np.dot(A,B)

#print out result
print("\nResult of the mutliplication is:\n")
print(result)
