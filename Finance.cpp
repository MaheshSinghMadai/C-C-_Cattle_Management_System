#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Sales{

    public:
        char cropName[40];
        int quantity;
        int salesPrice;
        int totalSales=0;

        void salesInput(){

            cout<<"Enter the name of the crop: "<<endl;
            cin>>cropName;
            cout<<"Enter the quantity sold: "<<endl;
            cin>>quantity;
            cout<<"Enter the selling price: "<<endl;
            cin>>salesPrice;
        }
         void salesDisplay(){
            cout<<"Crop Name: "<<cropName<<endl;
            cout<<"Quantity: "<<quantity<<"Kg"<<endl;
            cout<<"Rate: "<<salesPrice<<endl;
            cout<<"\n";
        }
        void write_sales()
        {
            ofstream outfile;
            outfile.open("Sales.txt", ios::binary|ios::app);
            salesInput();
            outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            outfile.close();
        }
        void read_sales()
        {
            ifstream infile;
            infile.open("Sales.txt", ios::binary);
            if(!infile)
            {
                cout<<"Error in Opening! File Not Found!!"<<endl;
                return;
            }
            cout<<"\n****Data from file****"<<endl;
            while(!infile.eof())
            {
                if(infile.read(reinterpret_cast<char *>(this), sizeof(*this)))
                {
                    salesDisplay();
                }
            }
            infile.close();
        }
        void delete_sales()
        {
            int n;
            ifstream infile;
            infile.open("Sales.txt", ios::binary);
            if(!infile)
            {
                cout<<"\nError in opening! File Not Found!!"<<endl;
                return;
            }
            infile.seekg(0,ios::end);
            int count = infile.tellg()/sizeof(*this);
            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to Delete: ";
            cin>>n;

            fstream tmpfile;
            tmpfile.open("SalesTemp.txt", ios::out|ios::binary);
            infile.seekg(0);
            for(int i=0; i<count; i++)
            {
                infile.read(reinterpret_cast<char *>(this),sizeof(*this));
                if(i==(n-1))
                    continue;
                tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            }
            infile.close();
            tmpfile.close();
            remove("Sales.txt");
            rename("SalesTemp.txt", "Sales.txt");
        }
        void edit_sales()
        {
            int n;
            fstream iofile;
            iofile.open("Sales.txt", ios::in|ios::binary);
            if(!iofile)
            {
                cout<<"\nError in opening! File Not Found!!"<<endl;
                return;
            }

            iofile.seekg(0, ios::end);

            int count = iofile.tellg()/sizeof(*this);

            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to edit: ";
            cin>>n;

            iofile.seekg((n-1)*sizeof(*this));
            iofile.read(reinterpret_cast<char*>(this), sizeof(*this));

            cout<<"Record "<<n<<" has following data"<<endl;
            salesDisplay();
            iofile.close();

            iofile.open("Sales.txt", ios::out|ios::in|ios::binary);
            iofile.seekp((n-1)*sizeof(*this));
            cout<<"\nEnter data to Modify "<<endl;
            salesInput();
            iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
};
class Expense{

    public:
        int pesticides,fertilizers,machinery, storehouse;
        int totalExpense=0;

        void expenseInput(){
            cout<<"Pesticides Expense: ";
            cin>>pesticides;
            cout<<"Fertilizer Expense: ";
            cin>>fertilizers;
            cout<<"Machinery Expense: ";
            cin>>machinery;
            cout<<"Store House Expenses: ";
            cin>>storehouse;
        }

        void expenseDisplay(){
            cout<<"Expenses "<<setw(5)<<"Amount"<<endl;
            cout<<"Pesticides: "<<setw(5)<<pesticides<<endl;
            cout<<"Fertilizers: "<<setw(5)<<fertilizers<<endl;
            cout<<"Machinery: "<<setw(5)<<machinery<<endl;
            cout<<"Store House: "<<setw(5)<<storehouse<<endl;

            int totalExpense = pesticides + fertilizers+ machinery + storehouse;

            cout<<" \n"<<"Total Expense: "<<totalExpense<<endl;
        }

        void write_expense()
        {
            ofstream outfile;
            outfile.open("Expense.txt", ios::binary|ios::app);
            expenseInput();
            outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            outfile.close();
        }

        void read_expense()
        {
            ifstream infile;
            infile.open("Expense.txt", ios::binary);
            if(!infile)
            {
                cout<<"Error in Opening! File Not Found!!"<<endl;
                return;
            }
            cout<<"\nExpenses \n"<<endl;
            while(!infile.eof())
            {
                if(infile.read(reinterpret_cast<char *>(this), sizeof(*this)))
                {
                    expenseDisplay();
                }
            }
            infile.close();
        }
        void delete_expense()
        {
            int n;
            ifstream infile;
            infile.open("Expense.txt", ios::binary);
            if(!infile)
            {
                cout<<"\nError in opening! File Not Found!!"<<endl;
                return;
            }
            infile.seekg(0,ios::end);
            int count = infile.tellg()/sizeof(*this);
            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to Delete: ";
            cin>>n;

            fstream tmpfile;
            tmpfile.open("ExpTemp.txt", ios::out|ios::binary);
            infile.seekg(0);
            for(int i=0; i<count; i++)
            {
                infile.read(reinterpret_cast<char *>(this),sizeof(*this));
                if(i==(n-1))
                    continue;
                tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            }
            infile.close();
            tmpfile.close();
            remove("Expense.txt");
            rename("ExpTemp.txt", "Expense.txt");
        }
        void edit_expense()
        {
            int n;
            fstream iofile;
            iofile.open("Expense.txt", ios::in|ios::binary);
            if(!iofile)
            {
                cout<<"\nError in opening! File Not Found!!"<<endl;
                return;
            }

            iofile.seekg(0, ios::end);

            int count = iofile.tellg()/sizeof(*this);

            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to edit: ";
            cin>>n;

            iofile.seekg((n-1)*sizeof(*this));
            iofile.read(reinterpret_cast<char*>(this), sizeof(*this));

            cout<<"Record "<<n<<" has following data"<<endl;
            expenseDisplay();
            iofile.close();

            iofile.open("Expense.txt", ios::out|ios::in|ios::binary);
            iofile.seekp((n-1)*sizeof(*this));
            cout<<"\nEnter data to Modify "<<endl;
            expenseInput();
            iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }

};
class Customer: public Sales{

    public:
        char firstName[50];
        char lastName[50];
        long long contactNumber;
        int month;
        int day;
        int year;

        void customerInput(){
            cout<<"First Name: ";
            cin>>firstName;
            cout<<"Last Name: ";
            cin>>lastName;
            cout<<"Contact Number: ";
            cin>>contactNumber;
            cout<<"Crop Bought: ";
            cin>>cropName;
            cout<<"Quantity of "<<cropName<<" Bought: ";
            cin>>quantity;
            cout<<"Date of Transaction: ";
            cin>>year;
            cin>>month;
            cin>>day;
        }
        void customerDisplay(){
            cout<<"Name: "<<firstName<<" "<<lastName<<"\n";
            cout<<"Contact Number: "<<contactNumber<<"\n";
            cout<<"Crop Bought: "<<cropName<<"\n";
            cout<<"Quantity bought: "<<quantity<<"\n";
            cout<<"Date of Transaction: "<<year<<"/"<<month<<"/"<<day;
            cout<<"\n\n";
        }
        void write_customer()
        {
            ofstream outfile;
            outfile.open("Customer.txt", ios::binary|ios::app);
            customerInput();
            outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            outfile.close();
        }

        void read_customer()
        {
            ifstream infile;
            infile.open("Customer.txt", ios::binary);
            if(!infile)
            {
                cout<<"Error in Opening! File Not Found!!"<<endl;
                return;
            }
            cout<<"\nCustomer Record \n"<<endl;
            while(!infile.eof())
            {
                if(infile.read(reinterpret_cast<char *>(this), sizeof(*this)))
                {
                    customerDisplay();
                }
            }
            infile.close();
        }
        void delete_customer()
        {
            int n;
            ifstream infile;
            infile.open("Customer.txt", ios::binary);
            if(!infile)
            {
                cout<<"\nError in opening! File Not Found!!"<<endl;
                return;
            }
            infile.seekg(0,ios::end);
            int count = infile.tellg()/sizeof(*this);
            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to Delete: ";
            cin>>n;

            fstream tmpfile;
            tmpfile.open("CustTemp.txt", ios::out|ios::binary);
            infile.seekg(0);
            for(int i=0; i<count; i++)
            {
                infile.read(reinterpret_cast<char *>(this),sizeof(*this));
                if(i==(n-1))
                    continue;
                tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            }
            infile.close();
            tmpfile.close();
            remove("Customer.txt");
            rename("CustTmp.txt", "Customer.txt");
        }
        void edit_customer()
        {
            int n;
            fstream iofile;
            iofile.open("Customer.txt", ios::in|ios::binary);
            if(!iofile)
            {
                cout<<"\nError in opening! File Not Found!!"<<endl;
                return;
            }

            iofile.seekg(0, ios::end);

            int count = iofile.tellg()/sizeof(*this);

            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to edit: ";
            cin>>n;

            iofile.seekg((n-1)*sizeof(*this));
            iofile.read(reinterpret_cast<char*>(this), sizeof(*this));

            cout<<"Record "<<n<<" has following data"<<endl;
            customerDisplay();
            iofile.close();

            iofile.open("Customer.txt", ios::out|ios::in|ios::binary);
            iofile.seekp((n-1)*sizeof(*this));
            cout<<"\nEnter data to Modify "<<endl;
            customerInput();
            iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }

};

