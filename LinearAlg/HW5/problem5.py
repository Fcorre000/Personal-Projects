import numpy as np
import matplotlib.pyplot as plt

# Load the data from dataset1.txt
data = np.loadtxt('/Users/fortnitekorea/Desktop/Personal-Projects/LinearAlg/HW5/dataset1.txt')

# Separate the data into x and y components
x = data[:, 0]
y = data[:, 1]

# Prepare the matrix A for the least squares computation
# A should be a matrix with two columns: one for x and one for the intercept term (ones)
A = np.vstack([x, np.ones(len(x))]).T

# Compute the least squares solution
# np.linalg.lstsq returns several values, we only need the first one (the solution)
solution, residuals, rank, s = np.linalg.lstsq(A, y, rcond=None)

# Extract the slope and intercept from the solution
slope, intercept = solution

# Print the slope and intercept
print(f"Slope: {slope}")
print(f"Intercept: {intercept}")

# Plot the data points
plt.scatter(x, y, label='Data points')

# Plot the least squares solution (the fitted line)
plt.plot(x, slope * x + intercept, 'r', label='Least squares fit')

# Add labels and legend
plt.xlabel('x')
plt.ylabel('y')
plt.title('Least Squares Fit')
plt.legend()

# Show the plot
plt.show()