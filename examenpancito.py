
from random import random
import tkinter as tk
from tkinter import *
import tkinter
from turtle import back, bgcolor
from typing import final
import random
import csv
from PIL import Image
from PIL import ImageTk
import re


class Jugador:

    def _init_(self, name, amount):
        self.name = name
        self.__amount = amount
        self.mano = []
        self.conteo = 0
        self.__apuesta = 0

    def checkname(self):
        while (len(self.name) < 3):
            if len(self.name) < 3:
                self.name = input("Escriba un nombre más largo: ")

    def checkamount(self):
        while (self.__amount <= 0):
            if self.__amount <= 0:
                self.__amount = float(input("Ingrese una cantidad mayor a 0: "))

    def count(self):
        for i in self.mano:
            if i[0] == "A":
                self.conteo += 11

            elif i[0] == "J":
                self.conteo += 10

            elif i[0] == "Q":
                self.conteo += 10

            elif i[0] == "K":
                self.conteo += 10

            elif i[0] == "1" and i[1] == "0":
                self.conteo += 10

            else:
                self.conteo += int(i[0])

    def depositarFichas(self):
        self.__amount += float(input("Ingrese la cantidad a sumar: "))

    def makeApuesta(self):
        self.__apuesta = float(input("Ingresa la cantidad a apostar: "))

        if (self.__apuesta < 0):
            while self.__apuesta < 0:
                self.__apuesta = float(input("Ingrese una cantidad mayor a 0: "))
        else:
            self._amount -= self._apuesta

        if self.__amount < 0:
            return False

    def pay(self):
        self._amount += self._apuesta

    def paydouble(self):
        self._amount += self._apuesta * 2

    def getAmount(self):
        return self.__amount

class Barajas:

    def _init_(self):
        self.mazo = []
        self.nuevaBaraja()
        self.Barajear()

    def nuevaBaraja(self):
        palos=["♥","♦","♣","♠"]
        letras=["A","J","Q","K"]
        for j in palos:
            for i in range(2,11):
                carta = str(i)+j
                self.mazo.append(carta)
            for i in letras:
                carta = str(i)+j
                self.mazo.append(carta)

    def Barajear(self):
        random.shuffle(self.mazo)

    def tomar_carta(self):
        carta=self.mazo[-1]
        self.mazo.pop()
        return carta


class Juego:

    def __init__(self) -> None:
        self.win = tk.Tk()
        self.baraja = Barajas()

    

    def mainmenu(self):

        self.starWin()

        def saveName():
            self.player = Jugador(entry1.get(),0)
        
        playername = StringVar()
        label1 = tk.Label(text="Nombre:")
        label1.pack()
        entry1 = tk.Entry(bd=4,textvariable=playername).pack()
        entry1.pack()
       
        b1 = tk.Button(text="Save",command=saveName)
        b1.pack()



        self.win.mainloop()

    def starWin(self):
        for widget in self.win.winfo_children():
            widget.destroy()

        self.win.geometry("500x500")
        self.win.title("Proyecto Programación Orientada a Objetos")


if __name__ == "__main__":
    game = Juego()
    game.mainmenu()





    


