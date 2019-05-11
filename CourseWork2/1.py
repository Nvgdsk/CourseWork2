import matplotlib.pyplot as plt
import numpy as np

from mpl_toolkits.mplot3d import axes3d
ax = axes3d.Axes3D(plt.figure())

Xi = np.arange(0, 2, 0.01)
Ti = np.arange(0, 1, 0.00005)
X, Y = np.meshgrid(Xi, Ti)
Z = (4-X)/(5+Y)

ax.plot_wireframe(X, Y, Z, rstride=10, cstride=10)

plt.show()
