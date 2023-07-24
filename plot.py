import matplotlib.pyplot as plt 
import numpy as np
from scipy import special as sp



def func(x):
    return 2*np.exp((np.angle(sp.gamma(complex(1,x))) - np.pi)/x)

 #PLOT EQUAZIONI DIFFERENZIALI

f = np.genfromtxt("zero.txt", delimiter=',',dtype=np.longdouble, usecols=1)
x = np.genfromtxt("zero.txt", delimiter=',',dtype=np.longdouble, usecols=0)





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
ax.plot(x,f, color = "purple") #RK4
ax.plot(lsp, a, color = "green")

plt.vlines(x = 3, ymin = 0, ymax = 4,
           colors = 'blue',
           label = 'g = 3')


ax.set_xlabel(r'$g$', fontsize = 20, loc = "right")
ax.set_ylabel(r'$k_{1}\epsilon$', fontsize = 20, loc = "top")
ax.legend(["Numerical solution","Approximation","g = 3"])
ax.set(xlim=(0,6))
plt.show()