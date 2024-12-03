import numpy as np

#Step (a): Generate a random N x M matrix X
N = 5
M = 3
X = np.random.rand(N, M)

#Step (b): Compute the eigendecomposition of the covariance matrix X^T X
cov_matrix = np.dot(X.T, X)
eigenvalues, eigenvectors = np.linalg.eig(cov_matrix)

#Step (c): Project the computed eigenvectors onto the data and normalize them
projected_eigenvectors = np.dot(X, eigenvectors)
normalized_eigenvectors = projected_eigenvectors / np.linalg.norm(projected_eigenvectors, axis=0)

#Step (d): Compute the singular value decomposition of the matrix X
U, S, Vt = np.linalg.svd(X, full_matrices=False)

#Step (e): Compare the U matrix and the normalized eigenvectors
#Note: The columns of U and the normalized eigenvectors should span the same subspace
print("U matrix from SVD:")
print(U)
print("\nNormalized eigenvectors projected onto the data:")
print(normalized_eigenvectors)

# Observations:
#The columns of U and the normalized eigenvectors should span the same subspace.
#The signs of the vectors may differ, but the directions should be the same.
#The singular values S are related to the square roots of the eigenvalues of X^T X.

#Additional comparison
print("\nSingular values from SVD:")
print(S)
print("\nSquare roots of eigenvalues of X^T X:")
print(np.sqrt(eigenvalues))