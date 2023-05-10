#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define MAX_SKU 5

enum ProductType
{
    Medicine = 1,
    Beauty = 2,
    Hygiene = 3,
    Other = 4
};

struct Product {
    int iD;
    double price;
    string name;
    string sku;

};

class Batch {
public:
    void getData();

    Product* getproduct() {
        return product;
    }
    int getstock() {
        return stock;
    }
    string getexpDate() {
        return expDate;
    }
    string getbrand() {
        return brand;
    }
    string getlaboratory() {
        return laboratory;
    }


    void setproduct(string name, double price, int stock) {
        this->stock = stock;
        this->product = new Product[stock];
        for (int i = 0; i < stock; i++) {
            product[i].iD = rand() % 100;
            product[i].sku = setsku();
            product[i].name = name;
            product[i].price = price;
        }

    }

    string setsku() {
        const char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        const int numCaracteresPermitidos = sizeof(chars) - 1;
        string sku;
        for (int i = 0; i < MAX_SKU; i++) {
            sku += chars[rand() % numCaracteresPermitidos];
        }
        return sku;
    }

    void restock() {
        int rs;
        cout << "\nHow many:" << endl;
        cin >> rs;

        Product* temp = this->product;
        this->product = new Product[stock + rs];
        for (int i = 0; i < this->stock + rs; i++)
        {
            if (i < this->stock) {
                product[i].iD = temp[i].iD;
                product[i].sku = temp[i].sku;
                product[i].name = temp[i].name;
                product[i].price = temp[i].price;

            }
            else {
                product[i].iD = rand() % 100;
                product[i].sku = setsku();
                product[i].name = product[0].name;
                product[i].price = product[0].price;

            }
        }

        this->stock += rs;

    }

    void destock(int m) {

        Product* temp = this->product;
        delete this->product;

        //Product* temp = this->product;

        this->product = new Product[stock - m];
        for (int i = 0; i <= this->stock - m; i++)
        {
            product[i].iD = temp[i].iD;
            product[i].sku = temp[i].sku;
            product[i].name = temp[i].name;
            product[i].price = temp[i].price;

        }
        delete[] temp;

        this->stock -= m;

    
    }

    void setstock(int s) {
        this->stock = s;
    }
    void setexpDate(string d) {
        this->expDate = d;
    }
    void setbrand(string b) {
        this->brand = b;
    }
    void setlaboratory(string l) {
        this->laboratory = l;
    }


private:
    Product* product;
    int stock;
    string expDate;
    string brand;
    string laboratory;
};

class InventoryManagement {

public:
    void newBatch();
    void searchFunctionality();
    void saleFunctionality();
    void SeeProducts();
    void getData();
    void restockFunctionality();


private:
    Batch* batch;
    int numberofBatches{ 0 };

};

class SalesManagement {
public:
    void searchSaleID();

private:
    InventoryManagement inventory;
};


void InventoryManagement::newBatch() {
    int n;

    cout << "\nNumber of products: " << endl;
    cin >> n;

    this->batch = new Batch[n];

    for (int i = 0; i < n; i++) {

        string name;
        int stock;
        double price;
        system("cls");
        cout << "\nName product: ";
        cin >> name;
        cout << "Stock of the Bach: ";
        cin >> stock;
        this->batch[i].setstock(stock);
        cout << "Price product: ";
        cin >> price;

        this->batch[i].setproduct(name, price, stock);

        cout << "Expiration Date of the Bach: ";
        string date;
        cin >> date;
        this->batch[i].setexpDate(date);

        cout << "Brand of the Bach: ";
        string brand;
        cin >> brand;
        this->batch[i].setbrand(brand);

        cout << "Laboratory of the Bach: ";
        string lab;
        cin >> lab;
        this->batch[i].setlaboratory(lab);

        this->numberofBatches++;

    }


}


void Batch::getData() {
    cout << "\n--------------------------------------------------";
    cout << "\nName:" << this->product->name;
    cout << "\nBrand:" << this->brand;
    cout << "\nStock: " << this->stock;
    cout << "\nPrice: " << this->product->price;
    cout << "\nExp Date:" << this->expDate;
    cout << "\nLaboratory:" << this->laboratory;
    cout << "\nIndividual identifier:";
    for (int i = 0; i < stock; i++) {
        cout << "\nSku:" << this->product[i].sku << "    ID:" << this->product[i].iD;
    }
    cout << "\n--------------------------------------------------\n";

}


void InventoryManagement::restockFunctionality() {

    int option, flag = 0;
    string search;
    if (this->numberofBatches != 0)
    {
        cout << "Give me the name of the product: " << endl;
        cin >> search;
        for (int i = 0; i < this->numberofBatches; i++) {
            Product* producto = this->batch[i].getproduct();
            if (search == producto->name) {
                this->batch[i].restock();
                flag = 1;
            }
        }
        if (flag == 0) cout << "\nProduct not finded" << endl;

    }
    else cout << "\nEmpty Batches";

}

void InventoryManagement::saleFunctionality() {

    int option, flag = 0, revstock, flag1 = 0;
    string search;
    if (this->numberofBatches != 0)
    {
        cout << "Give me the name of the product: " << endl;
        cin >> search;
        for (int i = 0; i < this->numberofBatches; i++) {
            Product* producto = this->batch[i].getproduct();
            if (search == producto->name) {
                cout << "\nHow many: " << endl;
                cin >> revstock;
                do
                {
                    if (this->batch->getstock() < revstock)
                    {
                        cout << "\nChoose another quantity";
                    }
                    else {
                        this->batch[i].destock(revstock);
                        flag = 1;
                    }
                } while (flag1 = !1);
                flag = 1;

            }
        }
        if (flag == 0) cout << "\nProduct not finded" << endl;

    }
    else cout << "\nEmpty Batches";

}


void InventoryManagement::searchFunctionality() {

    int option, flag = 0;
    string search;

    do
    {

        cout << "\n1.Name \n2.SKU/UPC \n3.Brand \n4.Laboratory\n5.Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            if (this->numberofBatches != 0)
            {
                cout << "Give me the name of the product: " << endl;
                cin >> search;
                for (int i = 0; i < this->numberofBatches; i++) {
                    Product* producto = this->batch[i].getproduct();
                    if (search == producto->name) {
                        this->batch[i].getData();
                        flag = 1;
                    }

                }
                if (flag == 0) cout << "\nProduct not finded" << endl;

            }
            else cout << "\nEmpty Batches";

            break;
        case 2:
            if (this->numberofBatches != 0)
            {
                cout << "Give me the SKU of the product: " << endl;
                cin >> search;

                for (int i = 0; i < this->numberofBatches; i++) {
                    Product* producto = this->batch[i].getproduct();
                    if (search == producto->sku) {
                        this->batch[i].getData();
                        flag = 1;
                    }


                }
                if (flag == 0) cout << "\nProduct not finded" << endl;

            }
            else cout << "\nEmpty Batches";

            break;
        case 3:
            if (this->numberofBatches != 0)
            {
                cout << "Give me the brand of the product: " << endl;
                cin >> search;

                for (int i = 0; i < this->numberofBatches; i++) {
                    if (search == this->batch[i].getbrand()) {
                        this->batch[i].getData();
                        flag = 1;
                    }

                }
                if (flag == 0) cout << "\nProduct not finded" << endl;
            }
            else cout << "\nEmpty Batches";
            break;
        case 4:
            if (this->numberofBatches != 0)
            {
                cout << "Give me the laboratory of the product: " << endl;
                cin >> search;

                for (int i = 0; i < this->numberofBatches; i++) {
                    if (search == this->batch[i].getlaboratory()) {
                        this->batch[i].getData();
                        flag = 1;
                    }
                }
                if (flag == 0) cout << "\nProduct not finded" << endl;

            }
            else cout << "\nEmpty Batches";
            break;
        default:
            cout << "\nChoose a valid option";
            system("cls");
            break;

        }

    } while (option != 5);

}

void InventoryManagement::SeeProducts()
{
    if (this->numberofBatches != 0)
    {
        for (int i = 0; i < this->numberofBatches; i++) {
            this->batch[i].getData();
        }
    }

}
