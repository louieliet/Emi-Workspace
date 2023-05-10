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

    Product getproduct(){
        return product;
    }
    int getstock(){
        return stock;
    }
    string getexpDate(){
        return expDate;
    }
    string getbrand(){
        return brand;
    }
    string getlaboratory(){
        return laboratory;
    }

    
    void setproduct(Product p){
        this->product = p;
    }
    void setstock(int s){
        this->stock = s;
    }
    void setexpDate(string d){
        this->expDate = d;
    }
    void setbrand(string b){
        this->brand = b;
    }
    void setlaboratory(string l){
        this->laboratory = l;
    }



    
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

        this->batch[i].setproduct(producto);
        
        cout << "Stock of the Bach: " << endl;
        int stock;
        cin >>  stock;
        this->batch[i].setstock(stock);


        cout << "Expiration Date of the Bach: " << endl;
        string date;
        cin >> date;
        this->batch[i].setexpDate(date);

        cout << "Brand of the Bach: " << endl;
        string brand;
        cin >> brand;
        this->batch[i].setbrand(brand);

        cout << "Laboratory of the Bach: " << endl;
        string lab;
        cin >> lab;
        this->batch[i].setlaboratory(lab);

        this->numberofBatches++;

    }


}


void Batch::getData(){
    cout << this->product.name << endl;
    cout << this->product.iD << endl;
    cout << this->product.price << endl;
    cout << this->product.sku << endl;
    cout << this->stock << endl;
    cout << this->expDate << endl;
    cout << this->brand << endl;
    cout << this->laboratory << endl;

}


void InventoryManagment::searchFunctionality(){
    
    int option;
    string search;

    do
    {

        cout << "\n1.Name \n2.SKU/UPC \n3.Brand \n4.Laboratory\n5.Exit" << endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout << "Give me the name of the product: " << endl;
                cin >> search;

                for(int i = 0; i < this->numberofBatches; i++){
                    Product producto = this->batch[i].getproduct();
                    if(search == producto.name){
                        this->batch[i].getData();
                    }
                    else{
                        cout << "\nProduct not finded" << endl;
                    }
                    
                }

                break;
            case 2:
                cout << "Give me the SKU of the product: " << endl;
                cin >> search;

                    
                for(int i = 0; i < this->numberofBatches; i++){
                    Product producto = this->batch[i].getproduct();
                    if(search == producto.sku){
                        this->batch[i].getData();
                    }
                    else{
                        cout << "\nProduct not finded" << endl;
                    }
                    
                }

                break;
            case 3:
                cout << "Give me the brand of the product: " << endl;
                cin >> search;

                for(int i = 0; i < this->numberofBatches; i++){
                    if(search == this->batch[i].getbrand()){
                        
                    }
                    else{
                        cout << "\nProduct not finded" << endl;
                    }
                    
                }
                break;
            case 4:
                cout << "Give me the laboratory of the product: " << endl;
                cin >> search;

                for(int i = 0; i < this->numberofBatches; i++){
                    if(search == this->batch[i].getlaboratory()){
                        
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