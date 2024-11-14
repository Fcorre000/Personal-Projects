import numpy as np
import scipy.linalg as linalg
from scipy.spatial.transform import Rotation as R

def rotation_matrix(angle, axis):
    #normalize the axis vector
    axis = axis / np.linalg.norm(axis)

    #create a rotation object using the axis-angle representation
    rotation = R.from_rotvec(angle * axis)

    #get the rotation matrix
    rotation_matrix = rotation.as_matrix()

    return rotation_matrix

# Example
angle = np.pi / 4  # 45 degrees in radians
axis = np.array([0, 0, 1])  # Rotation around the z-axis
R_matrix = rotation_matrix(angle, axis)
print(R_matrix)