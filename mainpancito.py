

baraja = Barajas()
baraja.mazo

name = input("Ingrese el nombre del jugador: ")
amount = float(input("Ingrese la cantidad inicial: "))

player = Jugador(name, amount)
couprier = Jugador("Couprier", 0)

player.checkname()
player.checkamount()

while (True):

    player.mano.clear()
    couprier.mano.clear()
    baraja.Barajear()

    couprier.conteo = 0

    aposibility = player.makeApuesta()

    if aposibility == False:
        r = input("Fondos insuficientes, ¿Desea agregar más? (Y/N) : ")
        if r == "Y":
            player.depositarFichas()
        else:
            print("Fondos insuficientes, no puede jugar =( ")
            break

    player.mano.append(baraja.tomar_carta())
    couprier.mano.append(baraja.tomar_carta())
    print("Carta incial: ")
    print("Couprier: " + couprier.mano[0])
    print("Jugador: " + player.mano[0])

    while (True):

        player.conteo = 0

        if len(baraja.mazo) < 15:
            baraja.nuevaBaraja()

        answer = input("¿Tomar carta? (Y/N): ")
        if answer == "Y":
            ncards = int(input("¿Cuántas cartas desea tomar?: "))

            for x in range(ncards):
                player.mano.append(baraja.tomar_carta())

            for i in player.mano:
                print(i)

            player.count()
            print("Conteo: " + str(player.conteo))

        if answer == "N":
            for i in player.mano:
                print(i)

            player.count()
            print("Conteo: " + str(player.conteo))

            break

    while (couprier.conteo < 17):
        couprier.conteo = 0
        if couprier.conteo < 17:
            couprier.mano.append(baraja.tomar_carta())
            couprier.count()
        else:
            break

    if player.conteo >= 21:
        print("Perdiste, fin del juego.")
    elif player.conteo > 21 and couprier.conteo > 21:
        print("Perdieron ambos")
    elif player.conteo == couprier.conteo:
        print("Tablas / Empate")
    elif player.conteo == 21 and couprier.conteo > 21:
        print("Ganas doble")
        player.paydouble()
    elif player.conteo < 21 and player.conteo > couprier.conteo:
        print("Ganas lo apostado")
        player.pay()
    elif couprier.conteo <= 21 and player.conteo < couprier.conteo:
        print("Pierdes lo apostado")
    elif couprier.conteo > 21:
        print("Victoria!")
        player.pay()

    print("Mano del Couprier: ")
    for i in couprier.mano:
        print(i)
    print("Conteo del Couprier: " + str(couprier.conteo))

    print("Su mano: ")
    for i in player.mano:
        print(i)

    print("Balance: " + str(player.getAmount()))

    playagain = input("¿Volver a jugar? (Y/N): ")

    if playagain == "N":
        break
