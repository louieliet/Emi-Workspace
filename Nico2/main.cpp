#include "header.h"

// Main Program
int main()
{

	srand(time(nullptr));

	InventoryManagement inventoryManagementM;
	SalesManagement salesManagemet(&inventoryManagementM);
	cout << "\n-------First Add Products\n";
	inventoryManagementM.newBatch();
	cout << "\n";
	system("Pause");
	int option, option1;
	do
	{
		system("cls");
		cout << "\nWelcome to Pharmacy\n";
		cout << "\n1.Sale\n2.Sales Reports\n3.Search Product\n4.Restock\n5.See Products\n6.Exit\nChoose an option:";
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			cout << "\n-------Sale\n";
			salesManagemet.Sale();
			cout << "\n";
			system("Pause");
			break;
		case 2:
			system("cls");
			cout << "\n-------Sale\n";
			salesManagemet.SalesReport();
			cout << "\n";
			system("Pause");
			break;
		case 3:
			system("cls");
			cout << "\n-------Search Product\n";
			inventoryManagementM.searchFunctionality();
			cout << "\n";
			system("Pause");
			break;
		case 4:
			system("cls");
			cout << "\n-------Restock\n";
			inventoryManagementM.restockFunctionality();
			cout << "\n";
			system("Pause");
			break;
		case 5:
			system("cls");
			cout << "\n-------See Products\n";
			inventoryManagementM.SeeProducts();
			cout << "\n";
			system("Pause");
			break;
		case 6:
			system("cls");
			cout << "\nThanks :)\n";
			exit(0);
			break;
		default:
			cout << "\nChoose a valid option";
			system("Pause");
			break;

		}

	} while (option != 7);

}
