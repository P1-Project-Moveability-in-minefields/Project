import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap

# Colormap  R     G     B
colors = [(0.95, 0.74, 0.43),  # 1.  Light soil/
          (0.85, 0.63, 0.29),  # 2.  Hard soil
          (0.60, 0.94, 0.88),  # 3.  Shallow water
          (0.14, 0.60, 0.76),  # 4.  Water
          (0.20, 0.57, 0.53),  # 5.  Swamp
          (0.30, 0.80, 0.27),  # 6.  Vegetation
          (0.12, 0.51, 0.09),  # 7.  Dark vegetation
          (0.68, 0.68, 0.68),  # 8.  Light roads
          (0.43, 0.43, 0.43),  # 9.  Hard roads
          (0.9, 0.0, 0.0),     # 10. Mines
          (0.80, 0.00, 0.98)]  # 11. Optimal route
values = [0,
          0.1,
          0.2,
          0.3,
          0.4,
          0.5,
          0.6,
          0.7,
          0.8,
          0.9,
          1.0]
custom_cmap = ListedColormap(colors, name='Custom Colormap', N=len(values))

# Open the file for reading
with open("../OutputMatrices/outputMatrix.txt", "r") as file:
    # Read lines from the file
    matrix = np.loadtxt(file)

# Print the array
plt.imshow(matrix, cmap=custom_cmap)
plt.title(f'Map and Optimal Route')
plt.show()