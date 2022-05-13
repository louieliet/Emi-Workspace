
class Dependiente:

    def __init__(self, nombre, sexo):
        self.nombre = nombre
        self.sexo = sexo
    
    def llenarID(self,_id):
        self.__iDEmpleado = _id
    
    def setAge(self, edad):
        try:
            self.edad = int(edad)
            if self.edad<18:
                self.edad = 18
            else:
                self.edad = edad
        except ValueError:
            print("Introduzca una edad válida")

    def cobrar(self,precio,pago):
        if (precio-pago) < 0:
            print("No es suficiente lo cobrado para pagar el producto")
        else:
            print("El cliente pagó: "+str(pago)+", y hay que devolverle: "+str(precio-pago))
    
    def darRecibo(self):
        print("Se entregó el recibo")
    
    def mostrarDatos(self):
        print(vars(self))

class Vendedor(Dependiente):

    def __init__(self, nombre, sexo,dinero_ventas):
        super().__init__(nombre, sexo)
        self.dinero_ventas = dinero_ventas  
    
    def cobrar(self, precio, pago):
        return super().cobrar(precio, pago)
        self.total += pago

class Emisor_de_Facturas(Dependiente):

    def __init__(self, nombre, sexo, pago_factura):
        super().__init__(nombre, sexo)
        self.pago_factura = pago_factura
    
    def cobrar(self, precio, pago):
        return super().cobrar(precio, pago)
        self.total += pago+(pago*0.16)

class Vendedor_que_factura(Vendedor,Emisor_de_Facturas):
    def __init__(self, nombre, sexo, dinero_ventas):
        self.nombre = nombre
        self.sexo = sexo
        self.dinero_ventas = dinero_ventas
        self.pago_factura = 1000
    
    def cobrar(self, precio, pago):
        return super().cobrar(precio,pago)
    
    def facturas_especiales(self,facturacion_especial,pago_extra):
        pago_extra = 0
        while True:
            facturacion_especial = float(input("Ingrese la facturación especial:"))
            if(facturacion_especial<100000 or facturacion_especial>20000):
                print("Error, eliga una cantidad válida")
                float(input("Ingrese la facturación especial:"))
                break
            else:
                break

        print("La facturación especial de: "+str(self.nombre)+", es: "+str(facturacion_especial + pago_extra))

    def __del__(self):
        print("Este vendedor que factura fue eliminado")


p1 = Vendedor("Vicky","F",100)
p2 = Emisor_de_Facturas("Quintero","M",200)
p3 = Vendedor_que_factura("Erendira","F",300)


p1.llenarID("2222")
p1.setAge(25)

p1.cobrar(100,100)
p1.darRecibo()
p1.mostrarDatos()


p2.llenarID("3333")
p2.setAge(6)

p2.cobrar(100,200)
p2.darRecibo()
p2.mostrarDatos()


p3.llenarID("4444")
p3.setAge(25)

p3.cobrar(100,200)
p3.darRecibo()
p3.facturas_especiales(50000,8)
p3.mostrarDatos()