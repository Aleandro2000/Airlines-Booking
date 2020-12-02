Airlines Booking.

#Structura fisierelor#

airlines.csv:

index,nume_zbor,loc_plecare,loc_sosire


booking.csv:

username,numar_zbor


users:

username,email,parola_criptata

Toate definitiile claselor necesare sunt in airlines.hpp. Tot ce mai trebuie facut este interfata in Airlines Booking.cpp.

#Definitii de clase

class Users
{
    vector<vector<string> > array;
    vector<string> v;
    unsigned long long lines=0;
    string username,email,password;
    public:
        ~Users();
        void data_csv_read(string);
        void create_account(string,string,string);
        void login(string,string);
        void showdata();
        string getusername();
        string getemail();
        string getpassword();
        friend string crypto();
};

class Booking
{
    vector<vector<string> > array;
    vector<string> v;
    unsigned long long lines=0,index=0;
    string flying,departure,destination;
    public:
        ~Booking();
        void data_csv_read(string);
        void showdata();
        string findFlying(unsigned long long);
        string getflying();
        string getdeparture();
        string getdestination();
        unsigned long long getindex();
};

class Airlines
{
    vector<vector<string> > array;
    vector<string> v;
    unsigned long long lines=0,index=0;
    string username,flying;
    public:
        ~Airlines();
        void data_csv_read(string);
        void showdata();
        void addAirlines(string,string);
        void deleteAirlines(string, unsigned long long); //deleteAirlines("file.csv", index)
        string getusername();
        string getflying();
        unsigned long long getindex();
};