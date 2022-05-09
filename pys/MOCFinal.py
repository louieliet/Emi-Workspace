class Persona:
    def __init__(self, nombre, edad, sexo, peso):
        self.nombre = nombre
        self.edad = int(edad)
        self.sexo = sexo
        self.peso = int(peso)
        self.altura = 0
        self.__RFC = ''
        
    def llenarAltura(self, altura):
        try:
            self.altura = float(altura)
        except ValueError:
            print("Introduzca un valor decimal")
        else:
            if (altura < 100):
                self.altura = 100
            else:
                self.altura = altura
        
    def llenarRFC(self, RFC):
        self.__RFC = RFC
        
    def calcularIMC(self):
        self.IMC = self.peso / (self.altura / 100)**2 
        if (self.IMC < 20):
            print('Por debajo de su peso ideal')
        elif (self.IMC >= 20 and self.IMC <= 25):
            print('En su peso ideal')
        else:
            print('Tiene sobrepeso')
    
    def esMayorDeEdad(self):
        if (self.edad >= 18):
            print('Es mayor de edad')
        else: 
            print('Es menor de edad')
    
    def mostrarDatos(self):
        print(vars(self))


class Profesionista(Persona):
    def __init__(self, nombre, edad, sexo, peso, grado):
        super().__init__(nombre, edad, sexo, peso)
        self.grado_de_estudios = grado
            
    def esMayorDeEdad(self):
        if (self.edad >= 18):
            print('Es mayor de edad y profesionista')
        else: 
            print('Parece que esta es una persona superdotada porque es Profesionista sin ser mayor de edad')
    
class Estudiante(Persona):
    def __init__(self, nombre, edad, sexo, peso, nivel):
        super().__init__(nombre, edad, sexo, peso)
        self.nivel_de_estudios = nivel
        
    def esMayorDeEdad(self):
        if (self.edad >= 18):
            print('Es mayor de edad y estudiante')
        else: 
            print('Es menor de edad')
    
class Profesionista_Alto_Nivel(Profesionista, Estudiante):

    def __init__(self, nombre, edad, sexo, peso, grado):
        self.nombre = nombre
        self.edad = int(edad)
        self.sexo = sexo
        self.peso = int(peso)
        self.altura = 0
        self.__RFC = ''
        self.grado_de_estudios = grado
        self.nivel_de_estudios = 'Posgrado'

    def esMayorDeEdad(self):
        Profesionista.esMayorDeEdad(self)
            
    def __del__(self):
        print('Este profesionista de alto nivel fue eliminado')

    def PercentilDeResponsabilidad(self,percentil_calculado,percentil_extra):
        try:
            self.percentil_calculado = int(percentil_calculado)
        except ValueError:
            print("Solo valores floats validos")

        else:
            if percentil_calculado>100:
                print("Introduza una cantidad de entre 0 - 100")
            else:
                self.percentil_calculado = percentil_calculado
                
        
            if percentil_extra == 0:
                self.percentil_extra = 0
            else:
                self.percentil_extra = percentil_extra
            
            print("El percentil de responsabilidad calculado de: " + str(self.nombre) + " es: " + str(self.percentil_calculado + self.percentil_extra))

        


A = Profesionista('Juan', 20, 'H', 70, 'Universidad')
B = Estudiante('Ana', 19, 'M', 65, 'Prepa')
C = Profesionista_Alto_Nivel('German', 50, 'H', 80, 'Masters')


A.llenarAltura(180)
A.llenarRFC('ABC123DEF456')
A.calcularIMC()
A.esMayorDeEdad()
A.mostrarDatos()

B.llenarAltura(160)
B.llenarRFC('JKU789FCD345')
B.calcularIMC()
B.esMayorDeEdad()
B.mostrarDatos()

C.llenarAltura(175)
C.llenarRFC('HJY765HBF012')
C.calcularIMC()
C.esMayorDeEdad()
C.PercentilDeResponsabilidad(70,0)
C.mostrarDatos()

print(vars(C))
del C



        
        
        

