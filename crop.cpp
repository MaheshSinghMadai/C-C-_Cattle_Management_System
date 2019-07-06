#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Crop{
    public:
        char cropName[50];
        char location[50];
        int cropAmount;
        char weather[50];
        char season[40];
        char plantTypes[40];
        char sowTime[40];
        char yieldTime[40];

        void fieldInput(){
            cout<<"Enter the Location of the field: ";
            cin>>location;
            cout<<"Enter the name of the crop grown: ";
            cin>>cropName;
        }
        void fieldDisplay(){
            cout<<setw(5)<<"Location: "<<setw(5)<<location<<endl;
            cout<<setw(5)<<"Crop Name: "<<setw(5)<<cropName<<endl;
        }
        void cropInput(){
            cout<<"Enter the name of the crop: ";
            cin>>cropName;
            cout<<"Enter the Amount of the Crop: ";
            cin>>cropAmount;
            cout<<"Weather Suitable: ";
            cin>>weather;
            cout<<"Seasons preferrable: ";
            cin>>season;
            cout<<"Other Types of "<<cropName<<":";
            cin>>plantTypes;
            cout<<"Sowing Month: ";
            cin>>sowTime;
            cout<<"Yield Month: ";
            cin>>yieldTime;
    }
    void cropDisplay(){
            cout<<setw(5)<<"Crop Amount: "<<setw(5)<<cropAmount<<endl;
            cout<<setw(5)<<"Weather: "<<setw(5)<<weather<<endl;
            cout<<setw(5)<<"Seasons: "<<setw(5)<<season<<endl;
            cout<<setw(5)<<"Types: "<<setw(5)<<plantTypes<<endl;
            cout<<setw(5)<<"Sowing month: "<<setw(5)<<sowTime<<endl;
            cout<<setw(5)<<"Yield Month: "<<setw(5)<<yieldTime<<endl;
    }
    void write_crop(){
            ofstream outfile;
            outfile.open("Crop.txt", ios::binary|ios::app);
            cropInput();
            outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            outfile.close();
    }
    void read_crop(){
            ifstream infile;
            infile.open("Crop.txt", ios::binary);
            if(!infile)
            {
                cout<<"Error in Opening! File Not Found!!"<<endl;
                return;
            }
            cout<<"\n";
            while(!infile.eof())
            {
                if(infile.read(reinterpret_cast<char *>(this), sizeof(*this)))
                {
                    cropDisplay();
                }
            }
            infile.close();
        }

        void delete_crop(){
            int n;
            ifstream infile;
            infile.open("Crop.txt", ios::binary);

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
            tmpfile.open("cropTemp.txt", ios::out|ios::binary);
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

            remove("Crop.txt");
            rename("CropTemp.txt", "Crop.txt");
        }
        void edit_crop()
        {
            int n;
            fstream iofile;
            iofile.open("Crop.txt", ios::in|ios::binary);
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
            cropDisplay();
            iofile.close();

            iofile.open("Crop.txt", ios::out|ios::in|ios::binary);
            iofile.seekp((n-1)*sizeof(*this));
            cout<<"\nEnter data to Modify "<<endl;
            cropInput();
            iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
};
