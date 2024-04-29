import matplotlib.pyplot as plt 
import numpy as np
from scipy import optimize
from scipy.integrate import quad
from scipy import special



"""
Python 3.0 code for graphs involving bessel functions (& modified) of purely imaginary order and real variable 
by using their integration representation formulas [dunster paper]
"""
#Already defined a,b

def F1(t, x, g):
	return np.cos(x*np.sin(t))*np.cosh(g*t)

def F2(t,x,g):
	return np.exp(-x*np.sinh(t))*np.sin(g*t) 

def G1(t,x,g):
	return np.sin(x*np.sin(t))*np.sinh(g*t)

def G2(t,x,g):
	return np.exp(-x*np.sinh(t))*np.cos(g*t)

def F(x,g):
	res1 = quad(F1, 0, np.pi, args=(x,g))
	res2 = quad(F2, 0, np.infty, args=(x,g))
	return (1/np.pi)*(1.0/np.cosh(g*np.pi / 2.0))*res1[0] - 2/np.pi * np.sinh(g*np.pi/2.0)*res2[0];

def G(x,g):
	ges1 = quad(G1, 0, np.pi, args=(x,g))
	ges2 = quad(G2, 0, np.infty, args=(x,g))
	return (1/np.pi)*(1.0/np.sinh(g*np.pi / 2.0))*ges1[0] - 2/np.pi * np.cosh(g*np.pi/2.0)*ges2[0];


def delta(x,g):
	return -np.arctan(G(x,g) / F(x,g)) - np.pi/4.0

sample = 100
g = 0.0;
lsp = np.linspace(0.1,0.4, sample)
a = np.zeros(sample)
for n in range(sample):
	a[n] = delta(lsp[n],g)

	

fig = plt.figure()
ax = fig.add_subplot()
plt.tight_layout()
#ax.set_xscale("log")
#ax.set_yscale("log")
ax.plot(lsp, a, color = "green")
plt.show()