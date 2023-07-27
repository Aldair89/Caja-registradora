#include <iostream>
#include <string>

const int MAX_PRODUCTOS = 100; // Máximo número de productos que se pueden ingresar

struct Producto {
    std::string nombre;
    double precio;
};

void imprimirBanner() {
    std::cout << R"(
  _______ _        _______           _______         
 |__   __| |      |__   __|         |__   __|        
    | |  | |__  _ __ _| |_ __ ___     _| |_ __ __ _  
    | |  | '_ \| '__| | | '__/ _ \   | | | '__/ _` | 
    | |  | | | | |  | | | | |  __/   | | | | | (_| | 
    |_|  |_| |_|_|  |_|_|  \___|   _| |_|_|  \__,_| 
                                |__   __|            
                                   | | ___   ___    
                                   | |/ _ \ / _ \   
                                   | | (_) |  __/   
                                   |_|\___/ \___|   
)" << std::endl;
}

int main() {
    imprimirBanner();

    Producto productos[MAX_PRODUCTOS]; // Arreglo de productos
    int numProductos = 0; // Número actual de productos ingresados

    // Ingresar los datos de los productos
    std::cout << "Ingrese los datos de los productos (nombre, precio):\n";
    std::string nombre;
    double precio;
    char opcion;

    do {
        std::cout << "Nombre del producto: ";
        std::cin >> nombre;
        std::cout << "Precio del producto: ";
        std::cin >> precio;

        productos[numProductos].nombre = nombre;
        productos[numProductos].precio = precio;

        numProductos++;

        std::cout << "¿Desea ingresar otro producto? (S/N): ";
        std::cin >> opcion;
    } while (opcion == 'S' || opcion == 's');

    // Calcular el total de la compra (incluyendo el IVA)
    double subtotal = 0.0;
    for (int i = 0; i < numProductos; i++) {
        subtotal += productos[i].precio;
    }

    const double IVA = 0.16;
    double total = subtotal * (1 + IVA);

    // Solicitar la cantidad entregada por el cliente
    double cantidadEntregada;
    std::cout << "\nTotal a pagar (incluyendo IVA): $" << total << std::endl;
    std::cout << "Ingrese la cantidad entregada por el cliente: $";
    std::cin >> cantidadEntregada;

    // Verificar si la cantidad entregada es suficiente
    if (cantidadEntregada >= total) {
        // Calcular el cambio
        double cambio = cantidadEntregada - total;
        std::cout << "Cambio: $" << cambio << std::endl;
    } else {
        // Calcular la cantidad faltante
        double falta = total - cantidadEntregada;
        std::cout << "Cantidad faltante: $" << falta << std::endl;
    }

    // Mostrar los detalles de la compra
    std::cout << "\nDetalles de la compra:\n";
    for (int i = 0; i < numProductos; i++) {
        std::cout << "Producto " << i + 1 << ": " << productos[i].nombre << ", Precio: $" << productos[i].precio << std::endl;
    }

    std::cout << "Subtotal: $" << subtotal << std::endl;
    std::cout << "Total (incluyendo IVA): $" << total << std::endl;

    return 0;
}
