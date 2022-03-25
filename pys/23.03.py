class Cuenta:
    cantidad=0
    rfc=""
    def __init__(self,ncuenta,ntitular):
        self.ncuenta=ncuenta
        self.ntitular=ntitular
    
    def Ingresar(self,cantidad):
        if cantidad<0:
            print("Cantidad incorrecta")
        if cantidad>0:
            self.cantidad+=cantidad
    
    def Retirar(self,cantidad):
        if cantidad<0:
            print("Cantidad incorrecta")
        if cantidad>0:
            self.cantidad-=cantidad
            if self.cantidad<0:
                self.cantidad=0
    

class Cuenta_Individual(Cuenta):
    def __init__(self, personaf):
        self.personaf=personaf
        Cuenta.__init__(self)

class Cuenta_Corporativa(Cuenta):
    def __init__(self, personam):
        self.personam=personam
        Cuenta.__init__(self)

class Cuenta_Indistinto(Cuenta_Individual,Cuenta_Corporativa):
    persona="Indistinto"
    def __init__(self):
        Cuenta_Individual.__init__(self)
        Cuenta_Corporativa.__init__(self)


cuenta1=Cuenta_Individual(1)
        

