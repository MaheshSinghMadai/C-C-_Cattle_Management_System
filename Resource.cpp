#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;

class Labour{

    public:
        char firstName[40];
        char lastName[40];
        int salesPrice;
        char post[40];
        int salary;
        int totalSalary=0;

        void labourInput(){

            cout<<"Enter the first name: "<<endl;
            cin>>firstName;
            cout<<"Enter the last name: "<<endl;
            cin>>lastName;
            cout<<"Enter the Post: "<<endl;
            cin>>post;
            cout<<"Enter the Salary: "<<endl;
            cin>>salary;
        }
        void labourDisplay(){
            cout<<"Name: "<<setw(5)<<firstName<<" " <<lastName<<endl;
            cout<<"Post: "<<setw(5)<<post<<endl;
            cout<<"Salary: "<<setw(5)<<salary<<endl;

            totalSalary += salary;
            cout<<"Total Salary : "<<setw(5)<<totalSalary<<endl;
        }
        void write_labour()
        {
            ofstream outfile;
            outfile.open("Labour.txt", ios::binary|ios::app);
            labourInput();
            outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            outfile.close();
        }
        void read_labour()
        {
            ifstream infile;
            infile.open("Labour.txt", ios::binary);
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
                    labourDisplay();
                }
            }
            infile.close();
        }
        void delete_labour()
        {
            int n;
            ifstream infile;
            infile.open("Labour.txt", ios::binary);
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
            tmpfile.open("LabourTemp.txt", ios::out|ios::binary);
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
            remove("Labour.txt");
            rename("LabourTemp.txt", "Labour.txt");
        }
        void edit_labour()
        {
            int n;
            fstream iofile;
            iofile.open("Labour.txt", ios::in|ios::binary);
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
            labourDisplay();
            iofile.close();

            iofile.open("Labour.txt", ios::out|ios::in|ios::binary);
            iofile.seekp((n-1)*sizeof(*this));
            cout<<"\nEnter data to Modify "<<endl;
            labourInput();
            iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
};
class Field{

    public:
        string location[40],crops[40];
        int area;

        void fieldInput(){
                cout<<"Location: ";
                std::string location;
                cout<<"Area: ";
                cin>>area;
                cout<<"Crops: ";
                std::string crops;
        }

        void fieldDisplay(){
            cout<<"Location: "<<setw(5)<<location<<endl;
            cout<<"Area: "<<setw(5)<<area<<endl;
            cout<<"Crops: "<<setw(5)<<crops<<endl;
        }

        void write_field()
        {
            ofstream outfile;
            outfile.open("Field.txt", ios::binary|ios::app);
            fieldInput();
            outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            outfile.close();
        }

        void read_field()
        {
            ifstream infile;
            infile.open("Field.txt", ios::binary);
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
                    fieldDisplay();
                }
            }
            infile.close();
        }
        void delete_field()
        {
            int n;
            ifstream infile;
            infile.open("Field.txt", ios::binary);
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
            tmpfile.open("FieldTemp.txt", ios::out|ios::binary);
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
            remove("Field.txt");
            rename("FieldTemp.txt", "Field.txt");
        }
        void edit_field()
        {
            int n;
            fstream iofile;
            iofile.open("Field.txt", ios::in|ios::binary);
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
            fieldDisplay();
            iofile.close();

            iofile.open("Field.txt", ios::out|ios::in|ios::binary);
            iofile.seekp((n-1)*sizeof(*this));
            cout<<"\nEnter data to Modify "<<endl;
            fieldInput();
            iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
};
