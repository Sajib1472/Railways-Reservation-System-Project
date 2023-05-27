#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int n=2; // Initial train number
int u=0; // Initial booked number of sit
int j=0; // Initial passenger number
class train
{
  public:
    int train_no,price;
    int seat;
    string d_time,a_time;
    string train_name;
    string start_pl;
    string dest_pl;
};

class passenger:public train
{
  public:
    string name, phone;
    int sitno,trainno;
    int age;

    void getdata();
    void bookticket();
    void cancelticket();
};

class admin:public passenger
{
    int train_no;
    int pass;
    int seat;
  public:
    void password();
    void startpg();
    void addtrain();
    void viewpsg();
    void outdata();
};

admin a;
train t[10];
passenger p[20];
passenger psg;

void admin:: password()
{
    system("clear");
    int passw;
    pass=1472; // login passward for admin
    cout<<"____________________________________________________________________"<<endl;
    cout<<"Login to Admin mode";
    cout<<"\nEnter Password:";
    cin >> passw;
    if(passw==pass)
    {
        cout<<"-----Login Successful !-----"<<endl;
        cout<<"\n____________________________________________________________________"<<endl;
        startpg();
    }
    else
    {
        cout<<"-----Incorrect Password !-----"<<endl;
        cout<<"----------Try Again!!---------"<<endl;
        system("pause");
        password();
    }
}

void admin:: startpg()
{
    system("clear");
    int ch;
    char ch1;
    cout<<"\n                  Welcome to the Admin mode                       "<<endl;
    cout<<"____________________________________________________________________"<<endl;
    do
    {
        cout<<"\nEnter your choice:"<<endl;
        cout<<" 1. Add Train\n 2. View Trains\n 3. View Passengers\n 4. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:addtrain();
	            break;
            case 2:outdata();
	            break;
            case 3:viewpsg();
	            break;
            case 4:exit(0);
            default:cout<<"Error!!"<<endl;
        }
        cout<<"\nDo you want to continue? (type 'y' to continue)";
        cin>>ch1;
    }
    while(ch1 == 'y'|| ch1=='Y');
}

void admin :: addtrain()
{
    int i,no;
    char ch1;
    cout<<"Scheduled Trains are:"<<endl;
    outdata();
    cout<<"\nDo you want to add more trains ?(Y/N)";
    cin>>ch1;
    if(ch1=='Y' || ch1=='y')
    {
        cout<<"\nHow many trains you want to add ?";
        cin>>no;
        for(i=n;i<n+no;i++)
        {
            cout<<"\nEnter Data for Train "<<endl;
            cout<<"\nEnter Train number:";
            cin>>t[i].train_no;
            cout<<"\nEnter Train name:";
            cin >> t[i].train_name;
            cout<<"\nEnter Boarding Place:";
            cin >> t[i].start_pl;
            cout<<"\nEnter Destination Place:";
            cin >> t[i].dest_pl;
            cout<<"\nEnter Fare:";
            cin>>t[i].price;
            cout<<"\nEnter the total number of seats:";
            cin>>t[i].seat;
            cout<<"\nEnter the departure time:";
            cin >> t[i].d_time;
            cout<<"\nEnter the arrival time:";
            cin >> t[i].a_time;
        }
        n=n+no;
    }
}

void admin:: outdata()
{
    cout<<"\n---------------------------Train Schedule-------------------------------"<<endl;
    cout<<setw(5)<<"TNo"<<setw(12)<<"Name"<<setw(15)<<"Boarding"<<setw(15)<<"Destination"<<setw(6)<<"Fare"<<setw(7)<<"Seats"<<setw(7)<<"DTime"<<setw(7)<<"Atime";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<setw(5)<<t[i].train_no<<setw(12)<<t[i].train_name<<setw(15)<<t[i].start_pl<<setw(15)<<t[i].dest_pl<<setw(6)<<t[i].price<<setw(7)<<t[i].seat<<setw(7)<<t[i].d_time<<setw(7)<<t[i].a_time<<endl;
    }
}

int main(); 

void  passenger:: getdata()
{
    int ch;
    char ch1;
    do
    {
        system("clear");
        cout<<"<=============== USER MENU ===============>\n"<<endl;
        cout<<"\t(1)View Trains \n\t(2)Book Ticket \n\t(3)Back to Main Menu\n\t(4)Exit \n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: a.outdata();
	            break;
            case 2: bookticket();
	            break;
            case 3: system("clear");
	            main();
	            break;
            case 4: exit(0);
            default: cout<<"\nPlease enter right choice: ";
        }
        cout<<"\nDo you want to continue?(type y to continue) ";
        cin>>ch1;
    }
    while( ch1=='y' || ch1=='Y');
}

void passenger:: bookticket()
{
    int seat_no;
    char c;
    int found=-1;
    char v;
    //int num;
    int train_num;
    system("clear");
    cout<<"============================================\n";
    cout<<"\n Enter the train number: ";
    cin >> train_num;
    cout << "\n A person can't buy more than one ticket. ";
    for(int i=0;i<n;i++)
    {
        if(t[i].train_no==train_num)
        {
            if(t[i].seat<=u)
            {
                cout<<"\n Not available seat";
                system("pause");
                system("clear");
                main();
            }
            else
            {
                p[j].trainno=train_num;
                seat_no=u+1;
                found=1;
                cout<<"\nEnter your name:";
                cin >> p[j].name;
                cout<<"Enter your phone number:";
                cin >> p[j].phone;
                cout<<"Enter your Age(in years): ";
                cin>>p[j].age;
                cout<<"Ticket Booked successfully !!";
                cout<<"\nDo the payments and collect your ticket.";
                cout<<" \nYour Seat number is: "<<seat_no;
                cout<<"\n(: WE WISH YOU A HAPPY JOURNEY :)"<<endl;
                p[j].sitno=seat_no;
                j++;
                u++;
            }
        }
    }
    if(found==-1)
    {
        cout<<"\nTrain not found!!";
        system("pause");
        system("clear");
        main();
    }
 
    cout<<"\n Enter '1' for main menu & press any key to exit:";
    cin>>c;
    if(c=='1')
    {
        system("clear");
        main();
    }
    else{
        exit(0);
    }
}

void admin:: viewpsg()
{
    int a,j;
    system("clear");
    cout<<"=============== Passenger Details ===============\n"<<endl;
    cout<<setw(10)<<"Train no."<<setw(15)<<"Name"<<setw(15)<<"Phone no."<<setw(7)<<"Age"<<setw(10)<<"seat no"<<endl;
    for(j=0;j<u;j++)
    {
        cout<<setw(10)<<p[j].trainno<<setw(15)<<p[j].name<<setw(15)<<p[j].phone<<setw(7)<<p[j].age<<setw(10)<<p[j].sitno<<endl;
        seat++;
    }
    cout<<"\n enter'1'for main menu & enter'0' for back:";
    cin>>a;
    if(a==1)
    {
        system("clear");
        main();
    }
    if(a==0)
    {
        system("clear");
        startpg();
    }
}

int main()
{
    // First train details as a input
    t[0].train_no = 10;
    t[0].train_name = "Kopotakho";
    t[0].start_pl = "Rajshahi";
    t[0].dest_pl = "Khulna";
    t[0].price = 580;
    t[0].seat = 600;
    t[0].d_time = "14:35";
    t[0].a_time = "18:35";
    // Second train details as a input
    t[1].train_no = 13;
    t[1].train_name = "Sundarban";
    t[1].start_pl = "Dhaka";
    t[1].dest_pl = "Khulna";
    t[1].price = 950;
    t[1].seat = 800;
    t[1].d_time = "06:35";
    t[1].a_time = "17:00";

    system("clear");
    int ch;
    cout<<"************************************************************"<<endl;
    cout<<"=============== RAILWAY  RESERVATION  SYSTEM ==============="<<endl;
    cout<<"************************************************************"<<endl;
    do
    {
        cout<<"\t MAIN  MENU:"<<endl;
        cout<<"\t 1.Admin mode \n\t 2.User mode \n\t 3.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: a.password();
	            break;
            case 2: psg.getdata();
	            break;
            case 3: exit(0);
            default: cout<<"Please enter right choice!!"<<endl;
        }
    }
    while(ch!=3);
    return(0);
}

