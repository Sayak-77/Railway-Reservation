#include <iostream>
#include <string.h>
#include <fstream>
#include "myheader.h"
using namespace std;
int main()
{
    char c;
    int tnum;
    cout<<"Enter Y if you are an admin and N if you are a passenger: ";
    cin>>c;
    check(c);   
    if(c=='Y' || c=='y')
    {
        int option;
        do
        {
            cout<<"1: CREATE Details "<<endl;
            cout<<"2: UPDATE Details "<<endl;
            cout<<"3: DELETE Details "<<endl;
            cout<<"4: DISPLAY Details "<<endl;
            cout<<"5: EXIT and save to Textfile "<<endl;
            cout<<"============================="<<endl;
            cout<<"Select Option >>";
            cin>>option;
            switch(option)
            {
                case 1:
                addRecord();
                system("CLS");
                break;
                case 2:
                cin.ignore();
                cout<<"Enter the Train Number: ";
                cin>>tnum;
                updateRecord(tnum);
                system("CLS");
                break;
                case 3:
                cin.ignore();
                cout<<"Enter the Train Number: ";
                cin>>tnum;
                deleteRecord(tnum);
                system("CLS");
                break;
                case 4:
                displayRecord();
                break;
                case 5:
                savefile();
                cout<<"\n~:: SYSTEM EXIT....saving to file ::~"<<endl;
                break;
                default:
                cout<<"Wrong Choice..!!";
                break;
            }
        }while(option!=5);
    }
    else
    {
        int opt;
        openfile();
        do
        {
            cout<<"1: DISPLAY Train Details "<<endl;
            cout<<"2: BOOK A TICKET "<<endl;
            cout<<"3: RENDER TICKET "<<endl;
            cout<<"============================="<<endl;
            cout<<"Select Option >>";
            cin>>opt;
            switch(opt)
            {
                case 1:
                displayRecord();
                break;
                case 2:
                cin.ignore();
                cout<<"Enter the Train Number: ";
                cin>>tnum;
                bookticket(tnum);
                break;
                case 3:
                Render();
                break;
                default:
                cout<<"Wrong Choice..!!";
                break;
            }
        }while(opt!=3);
    }
}