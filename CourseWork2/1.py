import matplotlib.pyplot as plt
import numpy as np

from mpl_toolkits.mplot3d import axes3d
ax = axes3d.Axes3D(plt.figure())
a = 4
b = 5
tau = 0.00001
h = 0.01
row = 1000
column = 100
arrayX = []
arrayT = []
i = 0
t=0
while(i<row):
    arrayT.append(t)
    t+=tau
    i+=1
i = 0
x=0
while(i<column):
    arrayT.append(x)
    x+=h
    i+=1
row = 1000
Xi = np.arange(arrayX)
Ti = np.arange(arrayT)
X, Y = np.meshgrid(Xi, Ti)
Z = (4-X)/(5+Y)

ax.plot_wireframe(X, Y, Z, rstride=10, cstride=10)

plt.show()