import tkinter as tk
class Persona:
    def __init__(self, nombre):
        self.nombre = nombre
    def name(self):
        print(self.nombre)
    def eyacular(self):
        print("OHHHHHHHHH")


class Pene(Persona):
    def __init__(self, nombre, color):
        super().__init__(nombre)
        self.color = color
    
    def __del__(self):
        print("ME MOCHARON EL PENE WEE")



pene1 = Pene("Pepe","Negro")

win = tk.Tk()

win.geometry("500x500")
win.title("PENES GIGANTES")

welcome = tk.Label(text="INGRESE PENE")
welcome.pack()


juan = pene1.name()
pene1.eyacular()
pene1.__del__()

penedelapersona = tk.Label(text=juan)
penedelapersona.pack()

win.mainloop()