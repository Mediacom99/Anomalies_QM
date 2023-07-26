import numpy as np
import matplotlib.pyplot as plt

"""
Python script per renderizzare il testo tramite latex
"""



#SETTINGS SECTION

plt.style.use('./style_sheet.mplstyle') #To render using TeX

fig, axs = plt.subplots(1,1, layout='constrained')




#MATH FOR PLOT SECTION





#PLOT SECTION

lsp = np.linspace(1,100,100)

axs.plot(lsp,lsp*lsp, color='black')



#CUSTOMIZE SECTION

axs.set_xlabel(r'$\gamma \frac{1}{e^{\Delta_{\epsilon}}}$')
axs.set_ylabel(r'$\int_{a}^{b}f(x)d\Gamma(x)$')
axs.set_title('TITOLone incredibbile', fontsize = 12)
axs.grid()



#SAVING SECTION

plt.savefig('prova.pdf',format='pdf')

#plt.show()