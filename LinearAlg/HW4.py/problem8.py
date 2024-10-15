import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def create_transformation_matrix():
    # Define the rotation matrix for 90° clockwise about the x-axis
    theta = -np.pi / 2  # 90° clockwise
    R_x = np.array([
        [1, 0, 0, 0],
        [0, np.cos(theta), -np.sin(theta), 0],
        [0, np.sin(theta), np.cos(theta), 0],
        [0, 0, 0, 1]
    ])
    
    # Define the translation matrices
    T_translate_to_origin = np.array([
        [1, 0, 0, -1],
        [0, 1, 0, 2],
        [0, 0, 1, -2],
        [0, 0, 0, 1]
    ])
    
    T_translate_back = np.array([
        [1, 0, 0, 1],
        [0, 1, 0, -2],
        [0, 0, 1, 2],
        [0, 0, 0, 1]
    ])
    
    # Combine the transformations
    T = T_translate_back @ R_x @ T_translate_to_origin
    
    return T

def apply_transformation(T, point):
    return T @ point

def plot_points(original_point, transformed_point):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    
    # Plot the original point
    ax.scatter(original_point[0], original_point[1], original_point[2], color='blue', label='Original Point')
    
    # Plot the transformed point
    ax.scatter(transformed_point[0], transformed_point[1], transformed_point[2], color='red', label='Transformed Point')
    
    # Set labels
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    
    # Set title
    ax.set_title('Original and Transformed Points')
    
    # Show legend
    ax.legend()
    
    # Show plot
    plt.show()

# Define the point x in homogeneous coordinates
x = np.array([1, 2, 1, 1])

# Create the transformation matrix
T = create_transformation_matrix()

# Apply the transformation
x_transformed = apply_transformation(T, x)

# Print the results
print("Original point:", x[:3])
print("Transformed point:", x_transformed[:3])

# Plot the points
plot_points(x[:3], x_transformed[:3])