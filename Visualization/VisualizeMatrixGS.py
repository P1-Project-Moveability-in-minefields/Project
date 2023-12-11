import numpy as np
import matplotlib.pyplot as plt

# Open the file for reading
with open("../OutputMatrices/outputMatrix.txt", "r") as file:
    # Read lines from the file
    matrix = np.loadtxt(file)

# Use the 'gray' colormap for grayscale
colormap = 'gray'

# Print the array
plt.imshow(matrix, cmap=colormap)
plt.title('Map and Optimal Route')
plt.show()
