import numpy as np
import scipy.linalg as linalg
import sympy

def change_basis(basis_matrix, vector):
    """
    Change the basis of a vector using a given change-of-basis matrix.

    Parameters:
    basis_matrix (numpy.ndarray or sympy.Matrix): The change-of-basis matrix.
    vector (numpy.ndarray or sympy.Matrix): The vector to be represented in the new basis.

    Returns:
    numpy.ndarray or sympy.Matrix: The vector represented in the new basis.

    Approach:
    - Compute the inverse of the change-of-basis matrix.
    - Multiply the inverse matrix by the input vector to obtain the new basis representation.
    """
    #Convert inputs to numpy arrays if they're sympy matrices
    if isinstance(basis_matrix, sympy.Matrix):
        basis_matrix = np.array(basis_matrix).astype(np.float64)
    if isinstance(vector, sympy.Matrix):
        vector = np.array(vector).astype(np.float64)

    #compute the inverse of the basis matrix
    inverse_basis_matrix = linalg.inv(basis_matrix)

    #multiply the inverse matrix by the vector
    new_basis_vector = np.dot(inverse_basis_matrix, vector)

    return new_basis_vector

#define basis matrix B
B = np.array([
    [0, -1, -1],
    [-4, 0, 0],
    [6, 6, 3]
])

#Define vectors x and [x]B
x = np.array([-18, 8, 5])
x_B = np.array([-2, 6, 5])

#Transform x to basis B
x_basisB = change_basis(B, x)

# Transform [x]B to the standard basis
# This is done by multiplying B with [x]B
x_in_standard_basis = np.dot(B, x_B)

print("Vector x in the basis B: ", x_basisB)
print("Vector x[B] in the standard basis: ", x_in_standard_basis)