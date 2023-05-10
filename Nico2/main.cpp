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
		cout << "\n1.Sale\n2.Sale Search ID\n3.Sales Reports\n4.Search Product\n5.Restock\n6.See Products\n7.Exit\nChoose an option:";
		cin >> option;
		switch (option)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			system("cls");
			cout << "\n-------Search Product\n";
			inventoryManagementM.searchFunctionality();
			cout << "\n";
			system("Pause");
			break;
		case 5:
			system("cls");
			cout << "\n-------Restock\n";
			inventoryManagementM.restockFunctionality();
			cout << "\n";
			system("Pause");
			break;
		case 6:
			system("cls");
			cout << "\n-------See Products\n";
			inventoryManagementM.SeeProducts();
			cout << "\n";
			system("Pause");
			break;
		case 7:
			system("cls");
			cout << "\nThanks :)\n";
			system("Pause");
			break;
		default:
			cout << "\nChoose a valid option";
			system("Pause");
			break;

		}

	} while (option != 7);


	// A placeholder variable that will only help during programming.

		//do
		//{
			//switch (option)

			//case 0:
			//	system("cls");
			 //   cout<<"\nProducts";
			 //   do
			 //   {
			 //       cout<<"\n1.Add Product\n2.Modify Product\n3.View Products\n4.Batches\n5.Exit\n->";
			 //       cin>>option1; 
			 //       switch (option1)
			 //       {
			 //       case 1:
			 //           break;
			 //       case 2:
			 //           break;
			 //       case 3:
			 //           break;
			 //       case 4:

			 //           break;
			 //       case 5:
			 //           cout<<"\nThanks :)";
			 //           break;
			 //       default:
			 //           cout<<"\nChoose a valid option"<<endl;
			 //           break;
			 //       }

			//	} while (option!=5);
			//	break;

			//case 1:
			//	system("cls");
			//	cout<<"\nSales";
			//	do
			//	{
			//		cout<<"\n1.Create a Sale\n2.Sales Report\n3.Manual Sale Search by ID\n4.Exit\n->";
			//		cin>>option1; 
			//		switch (option1)
			//		{
			//		case 1:
			//			break;
			//		case 2:
			//			break;
			//		case 3:
			//			break;
			//		case 4:
			//			cout<<"\nThanks :)";
			//			break;
			//		default:
			//			cout<<"\nChoose a valid option"<<endl;
			//			break;
			//		}

			//	} while (option!=5);
			//	break;

			//case 2:
			//	system("cls");
			//	cout<<"\nModify Product";
			//	break;

			//case 3:
			//	system("cls");
			//	cout<<"\nView Products based with their respective Batches.";
			//	cout<<"Batches";
			//	break;

			//case 4:
			//	system("cls");
			//	cout<<"\nLaboratory";
			//	break;

			//case 5:
			//	cout<<"\nThanks :)";	
			//	break;

			//default:
			//	cout<<"\nChoose a valid Option";
			//	break;
			//}

		//} while (option!=5);

}
