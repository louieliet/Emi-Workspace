#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h> 

using namespace std;

enum MainMenu {
    printClients = 1,
    procedures,
    showRecord,
    exitProg
};

enum Procedures {
    deepCleaning=1,
    cavityFilling,
    wisdowTooth,
    exitProc
};

class Client {
    private: int id;
    int age, dc,cf,wt;
    string name;
    string date;


    public: void register_client() {
        system("cls");
        int id, age;
        string name, date;
        cout << " -Register Client- " << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Date of registry: ";
        cin >> date;

        getClient(id, age, name, date);
        system("cls");

    }

    void getClient(int _id, int _age, string _name, string _date) {
        this -> id = _id;
        this -> age = _age;
        this -> name = _name;
        this -> date = _date;
    }

    void countprocedures(int _dc, int _cf, int _wt)
    {
        this -> dc=_dc;
        this -> cf=_cf;
        this -> wt=_wt;

    }

    string set_client() {
        return "ID: " + to_string(id) + "\nName: " + name + "\nAge: " +
                to_string(age) + "\nDate of registry: " + date + "\n\n";

    }
    
    void show_record() {

    cout<<"Clients record:"<<endl;
    cout<< to_string(dc)<< " " << to_string(cf)<< " "<< to_string(wt)<<endl;

}

};

void show_procedures() {
    cout << "Procedures and Costs " << endl;
    cout << " ----------- " << endl;
    cout << "1) Deep Cleaning: $100" << endl;
    cout << "2) Cavity Filling: $200" << endl;
    cout << "3) Wisdom Tooth/Teeth Removal: $450" << endl;
    cout << "4) Exit" << endl;
    cout << "Enter an option" << endl;
    printf("\n");

}




void print_mainMenu() {
    cout << "- Main Menu -" << endl;
    cout << "1) See Patients" << endl;
    cout << "2) Procedures" << endl;
    cout << "3) Patient's Record" << endl;
    cout << "4) Exit" << endl;
    cout << "Enter an option: ";
}

int main() {
    system("cls");
    int option, opc, registern, nclients;
    bool programRunning = true;

    cout << "Number of clients: " << endl;
    cin >> nclients;
    Client * list = new Client[nclients];
    int* registerlist = new int[nclients];
    //Client* list2=(Client*)malloc((sizeof(Client*)*nclients));

    for (int i = 0; i < nclients; i++) {
        list[i].register_client();
        cout<<"Your register number is:"<<i+205<<endl; 
        registerlist[i]=i+205;
        cout<<"Save your register number, it is important for later"<<endl;
     
    }
    int dc=0, cf=0, wt=0; 
    while (programRunning) {

        print_mainMenu();
        cin >> option;
        switch (option) {
            case printClients:

                system("cls");
                for (int j = 0; j < nclients; j++) {
                    cout << list[j].set_client() << endl;
                }
                break;

            case procedures:
                system("cls");
                cout << "Enter your register number: ";
                cin>>registern;
                for (int i = 0; i < nclients; i++) 
                {                   
                    if(registern==registerlist[i])
                    {  
                        show_procedures();
                        cin >> opc;
                        switch (opc) 
                        {
                            case deepCleaning:
                            dc++;
                            list[i].countprocedures(dc,0,0);     
                            break;

                            case cavityFilling:
                            cf++;
                            list[i].countprocedures(0,cf,0); 
                            break;

                            case wisdowTooth:
                            wt++;
                            list[i].countprocedures(0,0,wt); 
                            break;

                            case exitProc:
                            break;

                            default:
                            cout << "CHOOSE A VALID OPTION." << endl;
                            break;                                       
                        }                        
                    }
                }
                break;

            case showRecord:
                system("cls");
                cout << "SHOW RECORD" << endl;
                for(int i=0;i<nclients;i++)
                {
                    cout<<"Client: "<< registerlist[i]<< endl;
                    cout<<"Number of: DeepCleaning /Cavity Filling / Wisdow Tooth\n";
                    list[i].show_record();
                }
                break;

            case exitProg:
                programRunning = false;
                system("cls");
                cout << "Exiting..." << endl;
                cout << "Goodbye!";
                break;

            default:
                system("cls");
                cout << "Enter a valid option" << endl;
                cout << endl;
                break;

        }
    }
    return 0;
}