#include <iostream>
#include <string>
#include <clocale>
#include <Windows.h>
#include <exception>

using namespace std;

struct detalle {
	int linea;
	string producto;
	double cantidad;
	double precio;
	double descuento;
	double isv;
	double subTotalDetalle;
};

struct factura {
	int numero;
	string fecha;
	string cliente;
	double subTotal;
	double isv;
	double descuento;
	double totalPagar;
	detalle arregloDetalles[3];
} facturas[3];

struct detalle detalles;

int subTotalDetalles(int cantidad, int precio) {
	detalles.subTotalDetalle = detalles.cantidad * detalles.precio;
	return detalles.subTotalDetalle;
}


int main() {
	setlocale(LC_ALL, "SPANISH");
	SetConsoleCP(1252);
	double totalPagar;
	for (int i = 0; i < 3; i++)
	{
		cout << "Ingrese la fecha:" << endl;
		getline(cin, facturas[i].fecha);
		cin.ignore();
		cout << "Ingrese el Nombre del Cliente" << endl;
		getline(cin, facturas[i].cliente);
		cin.ignore();

		for (int j = 0; j < 3; j++)
		{
			cout << "Ingrese el nombre del producto: " << endl;
			getline(cin, detalles.producto);
			cin.ignore();
			cout << "Ingrese la cantidad del producto: " << endl;
			cin >> detalles.cantidad;
			cout << "Ingrese el precio del producto: " << endl;
			cin >> detalles.precio;
			cout << "Ingrese el descuento del producto: " << endl;
			cin >> detalles.descuento;
			cout << "Ingrese el isv del producto: " << endl;
			cin >> detalles.isv;
		}
	}

	detalles.subTotalDetalle;

	totalPagar = detalles.subTotalDetalle - detalles.descuento + detalles.isv;

	system("cls");

	for (int i = 0; i < 3; i++)
	{
		facturas[i].numero = i + 1;
		cout << "           Numero de factura: " << facturas[i].numero << endl;
		cout << "                 La fecha es: " << facturas[i].fecha << endl;
		cout << "        El Nombre del Cliente es: " << facturas[i].cliente << endl;
		
		for (int j = 0; j < 3; j++)
		{
			detalles.linea = j + 1;
			cout << "       El numero de linea es: " << detalles.linea << endl;
			cout << "   El nombre del producto es: " << detalles.producto << endl;
			cout << " La cantidad del producto es: " << detalles.cantidad << endl;
			cout << "   El precio del producto es: " << detalles.precio << endl;
			
			if (detalles.descuento < 1 || detalles.descuento >= 0)
			{
				detalles.descuento = detalles.descuento * 100;
			}
			cout << "El descuento del producto es: " << detalles.descuento << "%" << endl;
			if (detalles.isv < 1 || detalles.isv >= 0)
			{
				detalles.isv = detalles.isv * 100;
			}
			cout << "         El isv del producto: " << detalles.isv << "%" << endl;
			cout << " El subtotal de la compra es: " << detalles.subTotalDetalle << endl;
			cout << "         El total a pagar es: " << totalPagar << endl;
		}
	}

	system("pause");
	return 0;
}


