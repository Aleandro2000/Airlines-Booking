//Realized by Aleandro2000 on GitHub

#include "airlines.hpp"

bool Email_check(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}

int main()
{
    Users users;
    Booking booking;
    Airlines airlines;
    char options;
    string username,email,password,flying,departure,destination,admin,adminPassword;
    bool open=true;
    users.data_csv_read("./data/users.csv");
    booking.data_csv_read("./data/booking.csv");
    airlines.data_csv_read("./data/airlines.csv");
    while(open)
    {
        cout<<"#Airlines Booking#\n\n";
        cout<<"1->Create Account\n";
        cout<<"2->Login Account\n";
        cout<<"3->Manage Booking\n";
        cout<<"4->Admin Manager\n";
        cout<<"5->Show Users\n";
        cout<<"6->Show Booking\n";
        cout<<"7->Show Airlines\n";
        cout<<"8->Exit\n\n";
        cout<<"Option: ";
        cin>>options;
        switch(options)
        {
            case '1':
                system("@cls||clear");
                cout<<"Username: ";
                cin>>username;
                Email:
                cout<<"Email: ";
                cin>>email;
                try
                {
                    if(!Email_check(email))
                        throw email;
                }
                catch(string email)
                {
                    cout<<"Email GRESIT!\n";
                    goto Email;
                }
                Password:
                cout<<"Password: ";
                cin>>password;
                try
                {
                    if(password.length()<8)
                        throw password;
                }
                catch(string password)
                {
                    cout<<"Parola SLABA!\n";
                    goto Password;
                }
                users.create_account("./data/users.csv",username,email,password);
                break;
            case '2':
                system("@cls||clear");
                cout<<"Email: ";
                cin>>email;
                try
                {
                    if(!Email_check(email))
                        throw email;
                }
                catch(string email)
                {
                    goto Email;
                }
                cout<<"Password: ";
                cin>>password;
                users.login(email,password);
                break;
            case '3':
                system("@cls||clear");
                if(users.getusername()!="")
                {
                    Booking:
                    cout<<"Airlines: ";
                    cin>>flying;
                    cout<<"Departure: ";
                    cin>>departure;
                    cout<<"Destination: ";
                    cin>>destination;
                    booking.findFlying(flying,departure,destination);
                    try
                    {
                        if(booking.getflying()==""&&booking.getdeparture()==""&&booking.getdestination()=="")
                            throw flying;
                    }
                    catch(string flying)
                    {
                        cout<<"Zbor NEGASIT!\n";
                        goto Booking;
                    }
                    airlines.addAirlines("./data/airlines.csv",users.getusername(),flying,departure,destination);
                }
                break;
            case '4':
                system("@cls||clear");
                cout<<"Admin's name: ";
                cin>>admin;
                cout<<"Password: ";
                cin>>adminPassword;
                try
                {
                    if(admin!="admin"||adminPassword!="1234")
                        throw admin;
                    else
                    {
                        system("@cls||clear");
                        cout<<"1->Add airlines\n";
                        cout<<"2->Delete Airlines\n";
                        cout<<"Default key->Exit\n\n";
                        cout<<"Option: ";
                        cin>>options;
                        if(options=='1')
                        {
                            system("@cls||clear");
                            cout<<"Username: ";
                            cin>>username;
                            cout<<"Airlines: ";
                            cin>>flying;
                            cout<<"Departure: ";
                            cin>>departure;
                            cout<<"Destination: ";
                            cin>>destination;
                            airlines.addAirlines("./data/airlines.csv",username,flying,departure,destination);
                        }
                        else if(options=='2')
                        {
                            system("@cls||clear");
                            cout<<"Username: ";
                            cin>>username;
                            cout<<"Airlines: ";
                            cin>>flying;
                            cout<<"Departure: ";
                            cin>>departure;
                            cout<<"Destination: ";
                            cin>>destination;
                            airlines.deleteAirlines("./data/airlines.csv",username,flying,departure,destination);
                        }
                    }
                }
                catch(string admin)
                {
                    break;
                }
                break;
            case '5':
                system("@cls||clear");
                cout<<"Users:\n\n";
                users.showdata();
                cin.get();
                cin.get();
                break;
            case '6':
                system("@cls||clear");
                cout<<"Booking:\n\n";
                booking.showdata();
                cin.get();
                cin.get();
                break;
            case '7':
                system("@cls||clear");
                cout<<"Airlines:\n\n";
                airlines.showdata();
                cin.get();
                cin.get();
                break;
            case '8':
                open=false;
                break;
            default:
                break;
        }
        system("@cls||clear");
    }
    return 0;
}