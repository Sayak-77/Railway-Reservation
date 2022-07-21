#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <ios>
#include <iomanip>
#include "myheader.h"
using namespace std;
#define MEGA "Techno India College: Project"
#define username "admin"
#define pass "roothost"
const int maxrow=10;
string Tname[maxrow]={};
int Tno[maxrow]={0};
string Tavail[maxrow]={};

bool check(char c)
{
    string adm,p;
    int k=0,f=0;
    if(c=='Y' || c=='y')
    {
        while(k!=3){
        cout<<"Enter the Username: ";
        cin>>adm;
        if(adm==username)
        {
            cout<<"Enter the Password: ";
            cin>>p;
            if(p==pass)
            {
                cout<<"\n\n~:: Welcome to the Admin Control ::~\n\n";
                break;
            }
            else
            {
                ++f;
                cout<<"\nWRONG PASSORD!"<<"  "<<(3-f)<<" attempt(s) remaining.\n";
                if(f==3)
                {
                    cout<<"SYSTEM EXIT..";
                    exit(0);
                }
                else
                continue;
            }
        }
        else
        {
            ++k;
            cout<<"\nWRONG CREDENTAILS!"<<"  "<<(3-k)<<" attempt(s) remaining.\n";
            if(k==3)
            {
                cout<<"SYSTEM EXIT..";
                exit(0);
            }
            else
            continue;
        }
    }
    }
    else if(c=='N' || c=='n')
    {
        cout<<"\n\n~:: Welcome to Techno Railway Reservation ::~\n\n";
    }
}
void addRecord()
{
    int num,i;
    string avail;
    char name[50];
    cin.ignore();
    cout<<"Train Number: ";
    cin>>num;
    cin.ignore();
    cout<<"Train Description: ";
    cin.getline(name,50);
    cout<<"Seating Available: ";
    cin>>avail;
    for(i=0;i<maxrow;i++)
    {
        if(Tno[i] == 0)
        {
            Tno[i]=num;
            Tname[i]=name;
            Tavail[i]=avail;
            break;
        }
    }
}
void updateRecord(int a)
{
    char name[50];
    string avail;
    int count=0;
    char chr;
    for(int i=0;i<maxrow;i++)
    {
        if(Tno[i]==a)
        {
            count++;
            cin.ignore();
            cout<<"Enter new Train Description: ";
            cin.getline(name,50);
            Tname[i]=name;
            cout<<"Enter new Seating Availability: ";
            cin>>avail;
            Tavail[i]=avail;
            cout<<"\n~:: UPDATE SUCCESSFULL ::~\n";
             cout<<"Do you want to continue?(y/n): ";
             cin>>chr;
             if(chr=='Y' || chr=='y')
             break;
             else
             exit(0);
        }
    }
    if(count==0)
    {
        cout<<"Train Number does not exist!"<<endl;
    }
}
void displayRecord()
{
    system("CLS");
    cout<<"Current Record(s)"<<endl;
    cout<<"============================================================================"<<endl;
    int count=0;
    cout<<" SL.No. | Train Number  |      Train Description      | Seating Availability"<<endl<<"----------------------------------------------------------------------------\n";
    for(int i=0;i<maxrow;i++)
    {
        if(Tno[i]!=0)
        {
            count++;
            cout<<setw(4)<<count<<setw(14)
                <<Tno[i]<<setw(32)<<Tname[i]<<setw(17)<<Tavail[i]<<endl;
        }
    }
    if(count==0)
    {
        cout<<"No Record Exists..!!"<<endl;
    }
    cout<<"============================================================================"<<endl;
}
void deleteRecord(int b)
{
    int count=0;
    char chr;
    for(int i=0;i<maxrow;i++)
    {
        if(Tno[i]==b)
        {
            count++;
            Tno[i]={0};
            Tname[i]="";
            Tavail[i]="";
            cout<<"\n~:: DELETION SUCCESSFULL ::~\n";
            cout<<"Do you want to continue?(y/n): ";
            cin>>chr;
            if(chr=='Y' || chr=='y')
            break;
            else
            exit(0);
        }
    }
    if(count==0)
    {
        cout<<"Train Number does not exist!"<<endl;
    }
}
void openfile()
{
    string line,word,word2,word3;
    stringstream iss;
    ifstream myfile;
    myfile.open("Train_Details.txt");
    if(myfile.is_open())
    {
        int i=0;
        while(!myfile.eof())
        {
            getline(myfile,line);
            int l=line.length();
            word=line.substr(0,5);
            Tno[i]=stoi(word);
            Tname[i]=line.substr(6,l-10);
            Tavail[i]=line.substr(l-3,l);
            ++i;
        }
    }
    else
    {
        cout<<"Unable to open the File! "<<endl;
    }
}
void savefile()
{
    ofstream myfile;
    myfile.open("Train_Details.txt", ofstream::app);
    int i;
    for(i=0;i<maxrow;i++)
    {
        if(Tno[i]!=0)
        myfile<<"\n"<<Tno[i]<<" "<<Tname[i]<<" "<<Tavail[i];
        else
        break;
    }
}