class Funcionamiento:
    motor="Si"
    fallas="False"

    def Funcionar(self):
        print("El vehículo está funcionando")

class Descompuesto:
    motor="No"
    fallas="True"

    def Funcionar(self):
        print("El vehículo NO está funcionando")

class Vehiculo(Funcionamiento, Descompuesto):
    def __init__(self):
        Funcionamiento.__init__(self)       
        Descompuesto.__init__(self)
        print("Se ha creado el vehciulo")

class Coche(Vehiculo):
    def __init__(self,marca,modelo,color):
        self.marca=marca
        self.modelo=modelo
        self.color=color
        Vehiculo.__init__(self)
    
    def Funcionar(self, funcion):
        if funcion:
            Funcionamiento.Funcionar(self)
        else:
            Descompuesto.Funcionar(self)

    def Vender(self,binario):
        if binario == 0:
            print("El coche no se vendio")
        elif binario == 1:
            print("El coche ya se vendio")
        else:
            print ("El valor es invalido")


Coche1=Coche("Tesla" , "Roadster" , "Blanco")
Coche2=Coche("BMW" , "M850" , "Azul")
Coche3=Coche("Mercedez" , "AMG GT" , "Plateado")


print(vars(Coche1))
Coche1.Funcionar(True)
Coche1.Vender(0)
print(vars(Coche2))
Coche1.Funcionar(False)
Coche1.Vender(1)
print(vars(Coche3))
Coche1.Funcionar(True)
Coche1.Vender(2)


        
               