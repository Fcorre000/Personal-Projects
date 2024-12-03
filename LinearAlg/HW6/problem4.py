import numpy as np
import matplotlib.pyplot as plt

#Define the matrix A
A = np.array([[1, -2],
              [-4, 1]])

#Calculate the eigenvalues and eigenvectors
eigenvalues, eigenvectors = np.linalg.eig(A)

#Standard basis vectors
e1 = np.array([1, 0])
e2 = np.array([0, 1])

#Vectors defined by the columns of A
col1 = A[:, 0]
col2 = A[:, 1]

#Plotting
plt.figure()
ax = plt.gca()

#Plot standard basis vectors
ax.quiver(0, 0, e1[0], e1[1], angles='xy', scale_units='xy', scale=1, color='r', label='e1')
ax.quiver(0, 0, e2[0], e2[1], angles='xy', scale_units='xy', scale=1, color='g', label='e2')

#Plot vectors defined by the columns of A
ax.quiver(0, 0, col1[0], col1[1], angles='xy', scale_units='xy', scale=1, color='b', label='col1 of A')
ax.quiver(0, 0, col2[0], col2[1], angles='xy', scale_units='xy', scale=1, color='c', label='col2 of A')

#Plot eigenvectors
for i in range(len(eigenvectors)):
    ax.quiver(0, 0, eigenvectors[0, i], eigenvectors[1, i], angles='xy', scale_units='xy', scale=1, color='m', label=f'eigenvector {i+1}')

#Set plot limits
ax.set_xlim([-5, 5])
ax.set_ylim([-5, 5])

#Add grid, legend, and labels
plt.grid()
plt.legend()
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.title('Standard Basis Vectors, Columns of A, and Eigenvectors')
plt.xlabel('x')
plt.ylabel('y')

#Save the plot
plt.savefig('problem4_plot.png')

#Show the plot
plt.show()