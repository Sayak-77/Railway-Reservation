#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <ios>
#include <iomanip>
using namespace std;
const int maxrow=10;
string Tname[maxrow]={};
int Tno[maxrow]={0};
string Tavail[maxrow]={};
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
void addRecord()
{
    int num,i;
    string avail;
    char name[50];
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
void displayRecord()
{
    cout<<"Current Record(s)"<<endl;
    cout<<"============================================================================"<<endl;
    int count=8;
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
int main()
{
    openfile();
    displayRecord();
    return 0;
}