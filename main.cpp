#include<iostream>
#include<stdlib.h>
#include<fstream>
#include "crop.cpp"
#include "Resource.cpp"
#include "Finance.cpp"

using namespace std;

int main(){

    char choose,option,ch1,ch2,ch3,ch4,ch5,ch6,ch7;
    Crop cp;
    Sales s;
    Expense e;
    Customer c;
    Labour l;
    Field f;

    Main:
    while(1){
        cout<<"\t\tWelcome to Crop Management System\t\t";
        cout<<"\n\n\n\t1.Crop Record \n\t2.Finance Record \n\t3.Resource Record \n\t4.Exit"<<endl;
        cout<<"\t\n\tPress 1/2/3/4\n\n";
        cout<<"\tEnter what you want to do: ";
        cin>>choose;
        switch(choose)
        {
            case '1':
                system("CLS");
                cout<<"Crop Details";
                while(1){
                cout<<"\n\n\n1.Input Record \n2.Display Record \n3.Delete Record \n4.Update Record \n5.Return to Main Menu"<<endl;
                cout<<"\n\tPress 1/2/3\n\n";
                cout<<"Enter what you want to do: ";
                cin>>ch1;

                switch(ch1){
                    case '1':
                        cp.write_crop();
                         break;
                    case '2':
                        cp.read_crop();
                        break;
                    case '3':
                        cp.delete_crop();
                        break;
                    case '4':
                        cp.edit_crop();
                        break;
                    case '5':
                        system("CLS");
                        goto Main;
                    }
                    cout<<"\n";
                }
                break;
            case '2':
                system("CLS");
                Main1:
                while(1){

                cout<<"\tMenu \n\n1.Sales Record \n2.Expense Record \n3.Customer Record \n4.Return to Menu \n5.Exit"<<endl;
                cout<<"\tPress 1/2/3 \n";
                cin>>option;
                switch(option)
                {
                    case '1':
                        cout<<"\n\n\n";
                        while(1){
                        cout<<"Options \n\n1.Input Record \n2.Display Record \n3.Delete Record \n4.Update Record \n5.Return to Main Menu"<<endl;
                        cout<<"\n****Press 1/2/3****\n\n";
                        cout<<"Enter what you want to do: ";
                        cin>>ch2;
                            switch(ch2){

                                case '1':
                                    s.write_sales();
                                    break;
                                case '2':
                                    s.read_sales();
                                    break;
                                case '3':
                                    s.delete_sales();
                                    break;
                                case '4':
                                    s.edit_sales();
                                    break;
                                case '5':
                                    goto Main1;
                        }
                    }
                     break;
                    case '2':
                            cout<<"\n\n\n";
                            while(1){
                            cout<<"Options \n\n1.Input Record \n2.Display Record \n3.Delete Record \n4.Update Record \n5.Return to Main Menu"<<endl;
                            cout<<"\n****Press 1/2/3/4****\n\n";
                            cout<<"Enter what you want to do: ";
                            cin>>ch3;
                            switch(ch3){
                                case '1':
                                    e.write_expense();
                                    break;
                                case '2':
                                    e.read_expense();
                                    break;
                                case '3':
                                    e.delete_expense();
                                    break;
                                case '4':
                                    e.edit_expense();
                                    break;
                                case '5':
                                    goto Main1;
                                }
                        }
                        break;
                    case '3':
                            cout<<"\n\n\n";
                            while(1){
                            cout<<"Options \n\n1.Input Record \n2.Display Record \n3.Delete Record \n4.4.Update Record \n5.Return to Main Menu"<<endl;
                            cout<<"\n****Press 1/2/3/4****\n\n";
                            cout<<"Enter what you want to do: ";
                            cin>>ch4;
                            switch(ch4){
                                case '1':
                                    c.write_customer();
                                    break;
                                case '2':
                                    c.read_customer();
                                    break;
                                case '3':
                                    c.delete_customer();
                                    break;
                                case '4':
                                    c.edit_customer();
                                    break;
                                case '5':
                                    goto Main1;
                                }
                        }
                        break;
                    case '4':
                        system("CLS");
                        goto Main;

                    case '5':
                        return 0;
                    }
                    cout<<"\n";
                }
                break;
            case '3':
                system("CLS");
                Main2:
                while(1){

                cout<<"Main Menu \n\n1.Labour Record \n2.Field\n3.Exit"<<endl;
                cout<<"Press 1/2/3 \n";
                cin>>ch5;
                switch(ch5)
                {
                    case '1':
                        cout<<"\n\n\n";
                        while(1){
                        cout<<"Options \n\n1.Input Record \n2.Display Record \n3.Delete Record \n4.Update Record \n5.Return to Main Menu"<<endl;
                        cout<<"\n****Press 1/2/3****\n\n";
                        cout<<"Enter what you want to do: ";
                        cin>>ch6;
                            switch(ch6){

                                case '1':
                                    l.write_labour();
                                    break;
                                case '2':
                                    l.read_labour();
                                    break;
                                case '3':
                                    l.delete_labour();
                                    break;
                                case '4':
                                    l.edit_labour();
                                    break;
                                case '5':
                                    goto Main2;
                            }
                        }
                        break;
                    case '2':
                            cout<<"\n\n\n";
                            while(1){
                            cout<<"Options \n\n1.Input Record \n2.Display Record \n3.Delete Record \n4.Update Record \n5.Return to Main Menu"<<endl;
                            cout<<"\n****Press 1/2/3/4****\n\n";
                            cout<<"Enter what you want to do: ";
                            cin>>ch7;
                            switch(ch7){
                                case '1':
                                    f.write_field();
                                    break;
                                case '2':
                                    f.read_field();
                                    break;
                                case '3':
                                    f.delete_field();
                                    break;
                                case '4':
                                    f.edit_field();
                                    break;
                                case '5':
                                    goto Main2;
                                }
                        }
                        break;

                    case '3':
                        system("CLS");
                        goto Main;;
                    }
                    cout<<"\n";
                }

            }
        }
    return 0;
}
