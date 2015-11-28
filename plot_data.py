#!/usr/bin/python

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sys

d = pd.read_csv(sys.argv[1])
dmax = d.apply(max)
dmin = d.apply(min)

figure = str(sys.argv[0])[:-3] + "jpg"
plt.figure(1, figsize = (12, 9))
plt.pcolormesh(d[0], d[1], d[2], cmap = plt.cm.hot)
plt.colorbar()
plt.show()
savefig(figure)
