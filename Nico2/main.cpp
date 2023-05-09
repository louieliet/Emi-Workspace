#include "header.h"

// Main Program
int main() 
{

	int option,option1;
	do
	{
		
		cout<<"\nWelcome to Pharmacy\n";
		cout<<"\n1.Sale\n2.Sale Search ID\n3.Sales Reports\n4.Add Product\n5.Search Product\n6.Restock\n7.Exit\nChoose an option:";
		cin>> option;
		switch (option)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6: 
				break;
			case 7:
				cout<<"\nThanks :)\n";
				break;
			default:
				cout<<"\nChoose a valid option";
				system("Pause");
				break;

		}

	}while(option=!7);


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
