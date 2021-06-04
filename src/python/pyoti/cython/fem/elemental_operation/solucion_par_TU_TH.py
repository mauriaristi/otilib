import CoolProp.CoolProp as cp

from scipy.optimize import root_scalar

# ====================================================================================
def residual(d,*args):
    """
    PROPÓSITO: Definir la función residual para la solución del estado de una sustancia
               dada la temperatura y energía interna, o temperatura y entalpía.
    
    ENTRADAS:
               d:   Densidad en kg / m^3.
               T:   Temperatura en K.
               VAL: Valor a buscar de energía interna o entalpía (en J/kg).
               U_H: indicador de si se entrega entalpía o energía interna ('U', 'H').
         
    """
    # --------------------------------------------------------------------------------    
    T   = args[0]
    VAL = args[1]
    U_H = args[2]
    
    dif = cp.PropsSI(U_H,'T',T,'D',d,'WATER')-VAL
    
    return dif

# ************************************************************************************


# Ejemplo de uso:
# Encontrar la densidad que corresponde al estado definido por el par TU siguiente:

u  = 1818931.9999597894
T  = 422.039

# Definir los valores "limite" para la busqueda de soluciones.
dmin = 1e-4
dmax = 1000

# Llamado de la función root_scalar que encuentra la densidad correspondiente.
res = root_scalar(residual,bracket=[dmin, dmax],args=(T,u,'U'))

# El resultado se extrae de la siguiente manera:
rho = res.root

print(rho)


# Corroborar:

up = cp.PropsSI('U','T',T,'D',rho,'WATER')

print('u (dada)'      , u/1000, 'kJ/kg')
print('u (encontrada)', up/1000, 'kJ/kg')


# ======================================================================
# ======================================================================
# ======================================================================








print("===========================================")








# lo mismo se puede hacer para el par TH
h  = 1900000
T  = 422.039


# Llamado de la función root_scalar que encuentra la densidad correspondiente.
# Notar los cambios en la entrada "args", la cual ahora determina la entalpía.
res2 = root_scalar(residual,bracket=[dmin, dmax],args=(T,h,'H'))

# El resultado se extrae de la siguiente manera:
rho2 = res2.root

print(rho2)

# Corroborar:
hp = cp.PropsSI('H','T',T,'D',rho2,'WATER')

print('h (dada)'      , h/1000, 'kJ/kg')
print('h (encontrada)', hp/1000, 'kJ/kg')



