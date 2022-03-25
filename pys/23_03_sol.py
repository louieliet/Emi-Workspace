"""
1- Crea una clase llamada Cuenta que tendrá los siguientes atributos: 
- Número de cuenta
- Nombre del Titular
- Cantidad
- RFC
2- Crea un constructor de dicha clase que le de valor a los atributos Número de cuenta y Nombre del Titular a través de sus parámetros de entrada.
3- Genera dos métodos:
	Ingresar(cantidad): se ingresa una cantidad a la cuenta, si la cantidad introducida es negativa, no se hará nada y se emitirá un cartel que diga “Cantidad incorrecta”. Si es positiva se suma a la cantidad que ya se tenga.
	Retirar(cantidad): Se retira una cantidad a la cuenta. Si la cantidad introducida es negativa, no se hará nada y se emitirá un cartel que diga “Cantidad incorrecta”. Si restando la cantidad actual a la que nos pasan la cantidad de la cuenta queda negativa, la cantidad de la cuenta pasa a ser 0, de lo contrario se resta a la cantidad. 

4- Genere dos subclases de la clase Cuenta que sean Cuenta_Individual y Cuenta_Corporativa. Esas subclases tendrán, además de los demás atributos, el atributo de persona que valdrá “Persona Física” para Cuenta_Individual y “Persona Moral” para Cuenta_Corporativa.

5- Genere una subclase Mixta que herede de Cuenta_Individual y Cuenta_Corporativa y que en el atributo de persona tenga el valor de “Indistinto”.

6- La clase Mixta debe tener un destructor que emita un cartel que diga que ese objeto fue eliminado.

7- Genere tantos objetos como sea necesario para mostrar las funcionalidades de las tres subclases.

"""
class Cuenta:
    def __init__(self, No_cuenta, Nombre, RFC):
        self.numero_de_cuenta = No_cuenta
        self.nombre_del_titular = Nombre
        self.RFC = RFC
        self.cantidad = 0

    def Ingresar(self, cantidad):
        if cantidad < 0:
            print("Cantidad incorrecta")
        else:
            self.cantidad += cantidad
    
    def Retirar(self, cantidad):
        if cantidad < 0:
            print("Cantidad incorrecta")
        elif self.cantidad - cantidad < 0:
            self.cantidad = 0
        else:
            self.cantidad = self.cantidad - cantidad
            
        
class Cuenta_Individual(Cuenta):
    def __init__(self, No_cuenta, Nombre, RFC):
        super().__init__(No_cuenta, Nombre, RFC)
        self.persona = "Persona Física"
        
class Cuenta_Corporativa(Cuenta):
    def __init__(self, No_cuenta, Nombre, RFC):
        super().__init__(No_cuenta, Nombre, RFC)
        self.persona = "Persona Moral"
        
class Mixta(Cuenta_Individual, Cuenta_Corporativa):
    def __init__(self, No_cuenta, Nombre, RFC):
        Cuenta_Individual.__init__(self, No_cuenta, Nombre, RFC)
        Cuenta_Corporativa.__init__(self, No_cuenta, Nombre, RFC)
        self.persona = "Indistinto"
        
    def __del__(self):
        print("Este objeto fue eliminado")
        
        
No_1 = input("¿Cual es el numero de la cuenta?: ")
Nombre1 = input("¿Cual es el nombre del dueño de la cuenta?: ")
rfc1 = input("¿Cual es el RFC del dueño?: ")

c1 = Cuenta_Individual(No_1, Nombre1, rfc1)
print(vars(c1))
c1.Ingresar(1000)
c1.Retirar(500)
print(c1.cantidad)

No_2 = input("¿Cual es el numero de la cuenta?: ")
Nombre2 = input("¿Cual es el nombre del dueño de la cuenta?: ")
rfc2 = input("¿Cual es el RFC del dueño?: ")

c2 = Cuenta_Corporativa(No_2, Nombre2, rfc2)
print(vars(c2))
c2.Ingresar(1000)
c2.Retirar(500)
print(c2.cantidad)

No_3 = input("¿Cual es el numero de la cuenta?: ")
Nombre3 = input("¿Cual es el nombre del dueño de la cuenta?: ")
rfc3 = input("¿Cual es el RFC del dueño?: ")

c3 = Mixta(No_3, Nombre3, rfc3)
print(vars(c3))
c3.Ingresar(1000)
c3.Retirar(500)
print(c3.cantidad)
del c3
