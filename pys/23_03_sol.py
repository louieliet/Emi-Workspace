class Cuenta():
    def __init__(self, numcuenta, nombre):
        self.numero_de_cuenta=numcuenta
        self.nombre_del_titular=nombre
        self.cantidad=0
        self.__RFC=""
        
    def llenarCantidad(self):
        self.cantidad=int(input("Ingrese la cantidad en su cuenta (mínimo de 1000): "))
        if self.cantidad<1000:
            self.cantidad=1000
    
    def llenarRFC(self):
        self.__RFC=input("Ingrese su RFC: ")
        
    def Ingresar(self, cantidad):
        print()
        print("-------DEPÓSITO-------")
        if cantidad<0:
            print("Cantidad incorrecta.")
        else:
            self.cantidad= self.cantidad + cantidad
            
    def Retirar(self, cantidad):
        print()
        print("-------RETIRO-------")
        if cantidad<0:
            print("Cantidad incorrecta.")
        else:
            self.cantidad= self.cantidad - cantidad

class Cuenta_Individual(Cuenta):
    def __init__(self, numcuenta, nombre):
        super().__init__(numcuenta, nombre)
        self.persona="Persona Física"
    
class Cuenta_Corporativa(Cuenta):
    def __init__(self, numcuenta, nombre):
        super().__init__(numcuenta, nombre)
        self.persona="Persona Moral"

class Mixta(Cuenta_Individual, Cuenta_Corporativa):
    def __init__(self, numcuenta, nombre):
        Cuenta_Individual.__init__(self, numcuenta, nombre)
        Cuenta_Corporativa.__init__(self, numcuenta, nombre)
        self.persona="Indistinto"
    
    def __del__(self):
        print("La cuenta fue eliminada.")



numcuenta= input("Ingrese su número de cuenta: ")
nombre= input("Ingrese su nombre: ")
cliente1= Cuenta_Individual(numcuenta, nombre)
cliente1.llenarCantidad()
cliente1.llenarRFC()
cliente1.Ingresar(-100)
cliente1.Retirar(100)
print("---------")
print(vars(cliente1))

print("-----------------------------")

numcuenta= input("Ingrese su número de cuenta: ")
nombre= input("Ingrese su nombre: ")
corporacion1= Cuenta_Corporativa(numcuenta, nombre)
corporacion1.llenarCantidad()
corporacion1.llenarRFC()
corporacion1.Ingresar(200)
corporacion1.Retirar(18000)
print("---------")
print(vars(corporacion1))

print("-----------------------------")

numcuenta= input("Ingrese su número de cuenta: ")
nombre= input("Ingrese su nombre: ")
mixto1= Mixta(numcuenta, nombre)
mixto1.llenarCantidad()
mixto1.llenarRFC()
mixto1.Ingresar(500)
mixto1.Retirar(-100)
print("---------")
print(vars(mixto1))
print("-----------------------------")
del mixto1

print(corporacion1.__RFC)
print(mixto1.nombre)
