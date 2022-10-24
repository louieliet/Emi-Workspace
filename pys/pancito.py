
class Mascota:
    nombrependejo = " "
class Perro (Mascota):
    def __init__(self, name, vida):
        self.nombrependejo = name
        self.vida = vida
    def getName(self):
        return self.nombrependejo
class Juego:
    @staticmethod
    def follar(perro):
        print("El perro: " + perro.getName() + ", está follando")

p1 = Perro("Pepe",50)
Juego.follar(p1)