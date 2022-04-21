'''
Descripttion: 
version: 
Author: sch
Date: 2022-04-21 15:09:39
LastEditors: sch
LastEditTime: 2022-04-21 15:10:49
'''
import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
sns.set()

f = lambda x, y: np.exp(-(x*x*y*y+x*x+y*y-8*x-8*y)/2.)

xx = np.linspace(-1, 8, 100)
yy = np.linspace(-1, 8, 100)
xg,yg = np.meshgrid(xx, yy)
z = f(xg.ravel(), yg.ravel())
z2 = z.reshape(xg.shape)
plt.contourf(xg, yg, z2, cmap='BrBG')
plt.show()