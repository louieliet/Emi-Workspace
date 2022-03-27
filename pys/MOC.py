class Persona:
    def __init__(self,nombre, edad, sexo,peso):
        self.nombre=nombre
        self.sexo=sexo
        self.peso=peso
        self.edad=edad
        self.__altura=0
        self.__rfc=" "
        
    def Altura(self):
        altura=float(input("Deme su altura en metros: "))
        if altura<1:
            self.__altura=1
        else:
            self.__altura=altura
    
    def llenarRFC(self):
        self.__rfc=input("Ingrese su RFC: ")

    def calcularIMC(self):
        imc=int((self.peso/(self.__altura*self.__altura)))
        if imc<20:
            print("Por debajo del peso ideal")
        if imc<25 & imc>20:
            print("En su peso ideal")
        if imc>25:
            print("Tiene sobrepeso")
    
    def esMayorDeEdad(self):
        if self.edad>=18:
            print("Es mayor de edad")
        elif self.edad<18:
            print("No es mayor de edad")

    def mostrarDatos(self):
        print("Nombre: ",self.nombre,", Sexo: ",self.sexo,", Peso: ",self.peso,", Edad: ",self.edad,", Altura: ",self.__altura,", RFC: ",self.__rfc)

class Profesionista(Persona):
    def __init__(self, nombre, edad, sexo, peso, grado):
        super().__init__(nombre, edad, sexo, peso)
        self.grado=grado
    
    def esMayorDeEdad(self):
        if self.edad>=18:
            print("Es mayor de edad y profesionista")
        elif self.edad<18:
            print("Parece que esta es una persona superdotada porque es Profesionista sin ser mayor de edad")

class Estudiante(Persona):
    def __init__(self, nombre, edad, sexo, peso, nivel_de_estudios):
        super().__init__(nombre, edad, sexo, peso)
        self.nivel_de_estudios=nivel_de_estudios
    
    def esMayorDeEdad(self):
        if self.edad>=18:
            print("Es mayor de edad y estudiante")
        elif self.edad<18:
            print("Es menor de edad")

class Profesionista_Alto_Nivel(Profesionista,Estudiante):
    def __init__(self, nombre, edad, sexo, peso, grado):
        Profesionista.__init__(nombre,edad,sexo,peso,grado)
        Estudiante.__init__(self)
        self.nivel_de_estudios="Posgrado"
    
    def esMayorDeEdad(self):
        if self.edad>=18:
            print("Es mayor de edad y profesionista")
        elif self.edad<18:
            print("Parece que esta es una persona superdotada porque es Profesionista sin ser mayor de edad")
    
    def __del__(self):
        print("Este profesionista de alto nivel fue eliminado")

p1=Profesionista("Emi",19,"H",45,2)
p1.llenarRFC()
p1.Altura()

p2=Estudiante("Ari",19,"M",50,"2do")
p2.llenarRFC()
p2.Altura()

p3=Profesionista_Alto_Nivel("Liz",19,"M",45,"Licenciatura")
p3.llenarRFC()
p3.Altura()

p1.calcularIMC()
p2.calcularIMC()
p3.calcularIMC()

p1.esMayorDeEdad()
p2.esMayorDeEdad()
p3.esMayorDeEdad()

p1.mostrarDatos()
p2.mostrarDatos()
p3.mostrarDatos()