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
