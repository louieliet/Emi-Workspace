#include <iostream>
#include <string>
using namespace std;


enum ProductType
{
	Medicine = 1,
	Beauty = 2,
	Hygiene = 3,
	Other = 4
};


struct Product{
    int iD;
    double price;
    string name;
    string sku;

};

class Batch{
public:
    void getData();

    
private:
    Product product;
    int stock;
    string expDate;
    string brand;
    string laboratory;
};

class InventoryManagment{

public:
    InventoryManagment();
    void searchFunctionality();
    void getData();


private:
    Batch* batch;
    int numberofBatches;

};

class SalesManagement{
public:
    void searchSaleID();

private:
};


InventoryManagment::InventoryManagment(){
    int n;

    cout << "\nNumber of products: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        
        Product producto;

        cout << "\nName product: " << endl;
        cin >> producto.name;
        cout << "ID product: " << endl;
        cin >> producto.iD;
        cout << "Price product: " << endl;
        cin >> producto.price;
        cout << "SKU product: " << endl;
        cin >> producto.sku;

        this->batch[i].product = producto;
        
        cout << "Stock of the Bach: " << endl;
        cin >> this->batch[i].stock;

        cout << "Expiration Date of the Bach: " << endl;
        cin >> this->batch[i].expDate;

        cout << "Brand of the Bach: " << endl;
        cin >> this->batch[i].brand;

        cout << "Laboratory of the Bach: " << endl;
        cin >> this->batch[i].laboratory;

        this->numberofBatches++;

    }


}


void Batch::getData(){
    cout << this->product.name << endl;
    cout << this->product.name << endl;
    cout << this->product.name << endl;
    cout << this->product.name << endl;
    cout << this->product.name << endl;
    cout << this->product.name << endl;
    cout << this->product.name << endl;
    cout << this->product.name << endl;
}


void InventoryManagment::searchFunctionality(){
    
    int option;
    string name;
    
    do
    {

        cout << "\n1.Name \n2.SKU/UPC \n3.Brand \n4.Laboratory\n5.Exit" << endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout << "Give me the name of the product: " << endl;
                cin >> name;

                for(int i = 0; i < this->numberofBatches; i++){
                    if(name == this->batch[i].product.name){
                        this->batch[i].getData();
                    }
                    else{
                        cout << "\nProduct not finded" << endl;
                    }
                    
                }

                break;
            case 2:
                cout << "Give me the SKU of the product: " << endl;
                cin >> name;

                for(int i = 0; i < this->numberofBatches; i++){
                    if(name == this->batch[i].product.sku){
                        
                    }
                    else{
                        cout << "\nProduct not finded" << endl;
                    }
                    
                }
                break;
            case 3:
                cout << "Give me the brand of the product: " << endl;
                cin >> name;

                for(int i = 0; i < this->numberofBatches; i++){
                    if(name == this->batch[i].brand){
                        
                    }
                    else{
                        cout << "\nProduct not finded" << endl;
                    }
                    
                }
                break;
            case 4:
                cout << "Give me the laboratory of the product: " << endl;
                cin >> name;

                for(int i = 0; i < this->numberofBatches; i++){
                    if(name == this->batch[i].laboratory){
                        
                    }
                    else{
                        cout << "\nProduct not finded" << endl;
                    }
                    
                }
                break;
            case 5:
                break;
            default:
                cout<<"\nChoose a valid option";
                system("cls");
                break;

        }

    }while(option!=5);
    


}