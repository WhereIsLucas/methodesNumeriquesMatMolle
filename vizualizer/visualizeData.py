import numpy as np

import matplotlib.pyplot as plt
import matplotlib.animation as animation

types = ['float', 'float', 'float', 'float', 'float', 'float', 'float']
data = []

# Set up formatting for the movie files
Writer = animation.writers['imagemagick']
writer = Writer(fps=15, metadata=dict(artist='Me'), bitrate=1800)
fig = plt.figure(figsize=(7, 7))

for i in range(0, 75):
    fileName = "datas/grain" + str(i) + ".txt"
    data.insert(i, np.genfromtxt(fileName,
                                 delimiter=',',
                                 dtype=types,
                                 names=["ID", 'x', 'y','vx','vy','theta','radius']))

scat = plt.scatter(data[0]["x"], data[0]['y'], alpha=0.5,s=data[0]['radius']*1*100000)
plt.title('Scatter plot test')
plt.gca().set_aspect('equal', adjustable='box')
plt.xlabel('x')
plt.ylabel('y')
plt.show()
plt.axis("equal")

def update(frame_number):
    scat.set_offsets(np.c_[data[frame_number]["x"], data[frame_number]["y"]])


animation = animation.FuncAnimation(fig, update, interval=10,frames=75)
# plt.show()
animation.save('im.gif', writer=writer)