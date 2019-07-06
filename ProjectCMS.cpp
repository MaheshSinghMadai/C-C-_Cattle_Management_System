//Cattle Managemnet System

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h>

int login(void)   ///login features code
{
	int h=0;
   char userid[]="cms",password[]="123",p[15],u[15];
   int n=1,a,b;
   printf("\tEnter Username & Password(3 tries only)\n");
   getch();
   while(n<=3)
   {
      
      printf("\n\n\tUSER ID: ");
      scanf("%s",u);
      printf("\n\tPASSWORD: ");
      scanf("%s",p);
      a=strcmp(u,userid);
      b=strcmp(p,password);
      if(a==0&&b==0)
      {
         printf("\n\tYou have logged in successfully!!!");
         h=1;
         break;
      }
      else
      {
         system("cls");
		 printf("\n\n\n\n\tWrong PASSWORD and/or USER ID. Now you have % d more chance/s.",3-n);
      }
      getch();
      n++;
   }
   if(n==4)
	   printf("\n\tYou can't log in.\n");
   getch();
   
   return h;
}
int main()
{
	int h;
	int login(void);
	FILE *cms, *cmsNew; /// file pointers
    char another, ch;
    char cowID[20];
	struct date
    {
        int day;
        int month;
        int year;
    };
	struct milk
    {
        int milkProduced;
        int milkSold;
        int rate;
        int sales;
    };
	struct record //defining elements for record
    {
        char ID[10];
        char name[10];
        int valuation;
        char breed[30];
        struct date dob;
        int age;
        char vaccines;
        char color[15];
        char herdType[30];
        struct milk daily;
    };
    struct record cow;
  	 h=login(); /// calling login function
  	cms = fopen("CMS.DAT","rb+");
    if(cms == NULL)
    {
        cms= fopen("CMS.DAT","wb+");
        if(cms== NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
	if (h==0)
	{
		exit(0);
	}
	else
	{
		while(1)
		{
		system("cls");
        printf("\t\t\t\t\t\tWelcome\n\t\t\t\t\t\t  To \n \t\t\t\t\tCattle Management System");
	    printf("\n=============================================================================================================");
	    printf("\n1.Entry of Record \n2.Display \n3.Edit \n4.Search  \n5.Delete the record\n");
	    printf("\nEnter your choice:");
	    scanf("%d",&ch);
	    printf("\n\n");
	    switch(ch)
        {
        case 1:  /// if user press 1
            system("cls");
            fseek(cms,0,SEEK_END); /// search the file and move cursor to end of the file
            /// here 0 indicates moving 0 distance from the end of the file
             another = 'y';
            while(another == 'y')  /// if user want to add another record
            {
            	printf("\nEnter the ID: ");
	            scanf("%s",cow.ID);
	            fflush(stdin);
	            printf("\nEnter the Name: ");
	            scanf("%[^\n]",cow.name);
	            printf("\nEnter the Valuation: ");
	            scanf("%d",&cow.valuation);
	            fflush(stdin);
	            printf("\nEnter Breed Type: ");
	            scanf("%[^\n]",cow.breed);
	            fflush(stdin);
	            printf("\nEnter the Date of Birth: ");
	            scanf("%d/%d/%d",&cow.dob.day,&cow.dob.month,&cow.dob.year);
	            fflush(stdin);
	            printf("\nEnter the Age: ");
	            scanf("%d",&cow.age);
	            fflush(stdin);
	            printf("\nVaccines Given[Y/N]: ");
	            scanf("%c",&cow.vaccines);
	            fflush(stdin);
	            printf("\nEnter the Color: ");
	            scanf("%[^\n]",cow.color);
	            fflush(stdin);
	            printf("\nEnter the Herd Type: ");
	            scanf("%[^\n]",cow.herdType);
	            printf("\nMilk Record: ");
	            printf("\n\t\tMilk Produced: ");
	            scanf("%d",&cow.daily.milkProduced);
	            printf("\n\t\tMilk Sold:");
	            scanf("%d",&cow.daily.milkSold);
	            printf("\n\t\tRate: ");
	            scanf("%d",&cow.daily.rate);
	            printf("\nSales Amount :");
	            scanf("%d",&cow.daily.sales);
	            fwrite(&cow,sizeof(struct record),1,cms);
	        	printf("\nAdd another record(y/n): ");
	        	fflush(stdin);
	            another = getche();
          		}
          		 break;
			case 2:
            system("cls");
            rewind(cms); ///this moves file cursor to start of the file
            
            while(fread(&cow,sizeof(struct record),1,cms)==1)  /// read the file and fetch the record one record per fetch
            {
          		printf("ID\tName\t\tValuation\tBreed\tDate of Birth\tAge\tVaccines\tColor\tHerd Type\n");
                printf("--------------------------------------------------------------------------------------------------------\n");
                printf("%s\t%s\t\t%d\t\t%s\t%d/%d/%d\t%d\t\t%c\t%s\t%s",cow.ID,cow.name,cow.valuation,cow.breed,cow.dob.day,cow.dob.month,cow.dob.year,cow.age,&cow.vaccines,cow.color,cow.herdType);
                printf("\n");
                printf("\n\n\nMilk Data:\n");
                printf("Milk Produced\t\tMilk Sold\t\tRate\t\tTotal Sales\n");
                printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n",cow.daily.milkProduced,cow.daily.milkSold,cow.daily.rate,cow.daily.sales);
            }
            getch();
            break;
            case 3:  /// if user press 3 then do editing existing record
	            system("cls");
	            another = 'y';
	            while(another=='y')
	            {
	                printf("\nEnter the Cow ID to modify: ");
	                scanf("%s",cowID);
	                rewind(cms);
	                while(fread(&cow,sizeof(struct record),1,cms)==1)  /// fetch all record from file
	                {
	                    if(strcmpi(cow.ID,cowID) == 0)  ///if entered name matches with that in file
	                    {
	                    	printf("\nEnter the ID: ");
				            scanf("%s",cow.ID);
				            fflush(stdin);
				            printf("\nEnter the Name: ");
				            scanf("%[^\n]",cow.name);
				            printf("\nEnter the Valuation: ");
				            scanf("%d",&cow.valuation);
				            fflush(stdin);
				            printf("\nEnter Breed Type: ");
				            scanf("%[^\n]",cow.breed);
				            fflush(stdin);
				            printf("\nEnter the Date of Birth: ");
				            scanf("%d/%d/%d",&cow.dob.day,&cow.dob.month,&cow.dob.year);
				            fflush(stdin);
				            printf("\nEnter the Age: ");
				            scanf("%d",&cow.age);
				            fflush(stdin);
				            printf("\nVaccines Given[Y/N]: ");
				            scanf("%s",cow.vaccines);
				            fflush(stdin);
				            printf("\nEnter the Color: ");
				            scanf("%[^\n]",cow.color);
				            fflush(stdin);
				            printf("\nEnter the Herd Type: ");
				            scanf("%[^\n]",cow.herdType);
				            printf("\nMilk Record: ");
				            printf("\n\t\tMilk Produced: ");
				            scanf("%d",&cow.daily.milkProduced);
				            printf("\n\t\tMilk Sold:");
				            scanf("%d",&cow.daily.milkSold);
				            printf("\n\t\tRate: ");
				            scanf("%d",&cow.daily.rate);
				            printf("\nSales Amount :");
				            scanf("%d",&cow.daily.sales);
	                		fseek(cms,-sizeof(struct record),SEEK_CUR); /// move the cursor 1 step back from current position
	                    	fwrite(&cow,sizeof(struct record),1,cms); /// override the record
	                    	break;
	                	}
						else 
	                    {
	 						printf("\nNot Found");                   	
						}
				   }
	                printf("\nModify another record(y/n)");
	                fflush(stdin);
	                another = getche();
	            }
	            break;
            case 4:
	            system("cls");
	            another = 'y';
	            while(another == 'y')
	            {
	                printf("\nEnter the Cow ID to search: ");
	                scanf("%s",cowID);
	                rewind(cms); /// move record to starting of file
	                while(fread(&cow,sizeof(struct record),1,cms) == 1)  /// read all records from file
	                {
	                    if(strcmp(cow.ID,cowID) == 0)  /// if the entered record match
	                    {
	                      	printf("ID\tName\t\tValuation\tBreed\tDate of Birth\tAge\tVaccines\tColor\tHerd Type\n");
			                printf("--------------------------------------------------------------------------------------------------------\n");
			                printf("%s\t%s\t\t%d\t\t%s\t%d/%d/%d\t%d\t\t%c\t%s\t%s",cow.ID,cow.name,cow.valuation,cow.breed,cow.dob.day,cow.dob.month,cow.dob.year,cow.age,cow.vaccines,cow.color,cow.herdType);
			                printf("\n");
			                printf("\n\n\nMilk Data:\n");
			                printf("Milk Produced\t\tMilk Sold\t\tRate\t\tTotal Sales\n");
			                printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n",cow.daily.milkProduced,cow.daily.milkSold,cow.daily.rate,cow.daily.sales);
	                    	break;
						}
						else
						{
							printf("\n Not Found");
						}
	                }
	            	printf("\n\nSearch another record(y/n):");
	               	fflush(stdin);
	               	another = getche();
	            }
	            break;
            case 5:
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter the Cow ID delete: ");
                scanf("%s",cowID);
                cmsNew = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                rewind(cms); /// move record to starting of file
                while(fread(&cow,sizeof(struct record),1,cms) == 1)  /// read all records from file
                {
                    if(strcmp(cow.ID,cowID) != 0)  /// if the entered record match
                    {
                        fwrite(&cow,sizeof(struct record),1,cmsNew); /// move all records except the one that is to be deleted to temp file
                    }
                }
                fclose(cms);
                fclose(cmsNew);
                remove("CMS.DAT"); /// remove the orginal file
                rename("Temp.dat","CMS.DAT"); /// rename the temp file to original file name
                cms = fopen("CMS.DAT", "rb+");
                printf("Delete another record(y/n):");
                fflush(stdin);
                another = getche();
            }
            break;
            default:
            	printf("\nInvalid Choice!!");
   		 	}
   		}
   	}
}
