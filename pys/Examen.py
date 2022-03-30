from ast import Pass


class Mascota:
    def __init__(self,nombre,edad,sexo,peso):
        self.nombre=nombre
        self.edad=int(edad)
        self.__chip=0
        self.sexo=sexo
        self.peso=float(peso)
        self.__altura=0
    
    def Altura(self):
        altura=float(input("Deme su altura en cm: "))
        if altura<20:
            self.__altura=20
        else:
            self.__altura=altura
    
    def llenarchip(self):
        self.__chip=input("Chip: ")
    
    def indiceAltura(self):
        a=int(self.__altura)
        if a<=32:
            self.tamaño="Chico"
        if a>32 and a<50:
            self.tamaño="Mediano"
        if a>=50:
            self.tamaño="Grande"

        print(str(self.tamaño))
    
    def esAlergico(self):
        self.alergia=input("Es alergico (Y/N): ")
    
    def mostrarDatos(self):
        print("Nombre: ",self.nombre,"Edad: ",self.edad,"Sexo: ",self.sexo,"Peso: ",self.peso,"Altura: ",self.__altura,"Alergico: ",self.alergia, "Chip: ",self.__chip)
    
class Perro(Mascota):
    def __init__(self, nombre, edad, sexo, peso, pedigree, raza):
        super().__init__(nombre, edad, sexo, peso)
        self.pedigree=pedigree
        self.raza=raza
    
    def esAlergico(self):
        return super().esAlergico()
  
    def Alergico(self):
        print("Es alergico: ",self.alergia,", y es: ", self.tamaño)
    
class Gato(Mascota):
    def __init__(self, nombre, edad, sexo, peso,color,pelaje):
        super().__init__(nombre, edad, sexo, peso)
        self.color=color
        self.pelaje=pelaje
    
    def esAlergico(self):
        return super().esAlergico()
    
    def Alergico(self):
        print("Es alergico: ",self.alergia, ", y tiene pelaje: ",self.pelaje)

class Quimera(Perro,Gato):
    def __init__(self):
        pass

    def __del__(self):
        print("Las quimeras no existen por eso la eliminamos")
    
p1=Perro("Firulais",5,"M",20,"Si","Salchicha")
g1=Gato("Bigotes",3,"M",32,"Gris","Mucho")
q1=Quimera()       

p1.Altura()
p1.llenarchip()
p1.indiceAltura()
p1.esAlergico()
p1.Alergico()

g1.Altura()
g1.llenarchip()
g1.indiceAltura()
g1.esAlergico()
g1.Alergico()

q1.Altura()
q1.llenarchip()
q1.indiceAltura()
q1.esAlergico()

p1.mostrarDatos()
g1.mostrarDatos()
print(vars(q1))
    

        

        

        
