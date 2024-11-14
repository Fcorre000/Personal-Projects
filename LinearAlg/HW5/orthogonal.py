import numpy as np

def gram_schmidt(A):
    #Get the number of columns in A
    n = A.shape[1]

    #initialize an empty list to store the orthogonal vectors
    Q = np.zeros_like(A, dtype=float)

    for j in range(n):
        #Start with the jth column of A
        v = A[:,j]

        #subtract the projection of v onto the previous vectors
        for i in range(j):
            q = Q[:,i]
            v -= np.dot(v,q)*q
        #normalize the vector
        v /= np.linalg.norm(v)

        #store the normalized vector in Q
        Q[:,j] = v
    return Q

if __name__ == "__main__":
    A = np.array([[1, 1, 0], [1, 0, 1], [0, 1, 1]], dtype=float)
    Q = gram_schmidt(A)
    print("Orthonormal basis Q:")
    print(Q)