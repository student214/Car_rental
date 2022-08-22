#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

void login();
void registration();
void forgot();

int main(){
    int choice;
    cout<<"                Welcome to the car rental page              \n\n";
    cout<<"_____________________      Menu      ______________________\n\n";
    cout<<"\n        Type '1' to Login to your account.";
    cout<<"\n        Type '2' to Register for a new account.";
    cout<<"\n        Type '3' to if you have forgotten your password.";
    cout<<"\n        Type '4' to Exit.";
    cout<<"\n        Please enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice){
        case 1: (choice==1);
            login();
            break;
        
        case 2: (choice==2);
            registration();
            break;

        case 3: (choice==3);
            forgot();
            break;        
        case 4: (choice==4);
            cout<<"Thank you \n";
            break;
        default: (choice!=1,2,3,4);
            system("cls");
            cout<<"please select from the options above \n\n";
    }

}

void login(){
    int count;
    string userID,password,ID,pass;
    system("cls");
    cout<<"Please enter your username and password : ";
    cout<<"\nUsername : ";
    cin>>userID;
    cout<<"\nPassword : ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>ID>>pass){
        if(ID==userID && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1){
        int choic;
        cout<<userID<<"\nYour login was succesful.";
        cout<<"\nPlease choose which period of time you would like to rent a car.";
        cout<<"\nType '1' for days.";
        cout<<"\nType '2' for weeks.";
        cout<<"\nType '3' for Months.";
        cout<<"\nPlease enter your choice : ";
        cin>>choic;
        system("cls");
        switch (choic){
            case 1:(choic=='1');{
                int day;
                cout<<"Please enter the number of days you would like to rent a car : ";
                cin>>day;
                int total1 = day*20 + 100;
                cout<<"\nYour total including your deposit is : "<<total1;
                cout<<"\nPlease visit your nearest branch to complete your payment and to receive the car.";
                break;
            }
            case 2:(choic=='2');{
                int week;
                cout<<"Please enter the number of weeks you would like to rent a car : ";
                cin>>week;
                int total2 = week*100 + 100;
                cout<<"\nYour total including your deposit is : "<<total2;
                cout<<"\nPlease visit your nearest branch to complete your payment and to receive the car.";
                break;
            }
            case 3:(choic=='3');{
                int month;
                cout<<"Please enter the number of months you would like to rent a car : ";
                cin>>month;
                int total3 = month*500 + 100;
                cout<<"\nYour total including your deposit is : "<<total3;
                cout<<"\nPlease visit your nearest branch to complete your payment and to receive the car.";
                break;
            }
            case 4 :(choic != 'D','W','M');{
                cout<<"You have entered an invalid period please try again.";
            }
        }
    }
    else{
        cout<<"\n your username or password is incorrect; Please try again.\n";
        main();
    }
}
void registration(){
    string ruserID,rpassword,rID,rpass;
    system("cls");
    cout<<"Enter your new username : ";
    cin >> ruserID;
    cout<<"\nEnter your new password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout <<"\nRegistration was successful.\n";
    main();
}
void forgot(){
    system("cls");
    cout<<"\nYou have forgotten the password!";
    int count(0);
    string fuserID,fID,fpass;
    cout<<"\nPlease enter your username to receive your password : ";
    cin>>fuserID;

    ifstream f2("records.txt");
    while(f2>>fID>>fpass){
        if(fuserID==fID);{                    
            count=1;
        }
    }
    f2.close();
    if(count==1){
        cout<<"\nYour account has been found! ";
        cout<<"\nYour password is : " <<fpass<<endl;
        main();
    }else{
        cout<<"\nsorry your username is invalid. \n";
    }   
}