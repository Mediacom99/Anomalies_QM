import matplotlib.pyplot as plt 
import numpy as np
from scipy import special as sp



def func(x):
    return 2*np.exp((np.angle(sp.gamma(complex(1,x))) - np.pi)/x)

 #PLOT EQUAZIONI DIFFERENZIALI

f = np.genfromtxt("deltaDati.txt", delimiter=',',dtype=np.longdouble, usecols=1)
x = np.genfromtxt("deltaDati.txt", delimiter=',',dtype=np.longdouble, usecols=0)





plt.style.use('_mpl-gallery')

#fig,axs = plt.subplots(1, sharex=True, sharey=True)
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


lsp = np.linspace(0.00000001,10,100)
a = np.zeros(100)
for n in range(100):
    a[n] = func(lsp[n]);


#fig.text(0.5,0.04,"x", ha='center')
#fig.text(0.04,0.5, "f(x)", va='center',rotation='vertical')

#ax.plot(x,y, color = "green") #Eulero
#ax.plot(A,B, color = "red")  #Runge Kutta 2
ax.plot(x,f, color = "black") #RK4
#plt.xticks(np.arange(min(x), max(x), 0.05))

#ax.hlines(y=0, xmin = 0.0, xmax = 0.6, linewidth=2, color='black')
ax.vlines(x=3*np.pi/2.0, ymin = np.amin(f), ymax = np.amax(f), linewidth=5, color='black')

#ax.plot(lsp, a, color = "green")

"""
plt.vlines(x = 3, ymin = 0, ymax = 4,
           colors = 'blue',
           label = 'g = 3')
"""

ax.set_xlabel(r'$g$', fontsize = 20, loc = "right")
ax.set_ylabel(r'$k_{1}\epsilon$', fontsize = 20, loc = "top")
ax.legend(["Numerical solution","Approximation","g = 3"])
#ax.set(xlim =(np.amin(x),np.amax(x)),ylim=(np.amin(f)*1.25,np.amax(f)*1.25))
ax.set(xlim =(np.amin(x),np.amax(x)),ylim=(-0.025, 0.025))
#xlim=(np.amin(x),np.amax(x)+2)
plt.show()