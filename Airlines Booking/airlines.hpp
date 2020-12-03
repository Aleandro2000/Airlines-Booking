#ifndef AIRLINES_FILE
#define AIRLINES_FILE

#include <bits/stdc++.h>

using namespace std;

string crypto(const std::string& str)
{
    unsigned long hash = 5381;
    for (size_t i = 0; i < str.size(); ++i)
        hash = 33 * hash + (unsigned char)str[i];
    return to_string(hash);
}

//users
class Users
{
    vector<vector<string> > array;
    vector<string> v;
    unsigned long long lines=0;
    string username="",email;
    public:
        ~Users();
        void data_csv_read(string);
        void create_account(string,string,string,string);
        void login(string,string);
        void showdata();
        string getusername();
        string getemail();
        friend string crypto();
};

Users::~Users()
{}

void Users::data_csv_read(string file)
{
    ifstream in(file);
    string line, field;

	this->lines=0;

    while (getline(in, line))
    {
        this->v.clear();
        stringstream ss(line);
		++this->lines;
        while (getline(ss, field, ','))
        {
            this->v.push_back(field);
        }
        this->array.push_back(this->v);
    }
	in.close();
}

void Users::showdata()
{
    for(unsigned long long i=0;i<this->lines;++i)
        cout<<array[i][0]<<'\t'<<array[i][1]<<'\n';
}

void Users::create_account(string file, string username, string email, string password)
{
    for(unsigned long long i=0;i<this->lines;++i)
        if(array[i][0]==username&&array[i][1]==email&& array[i][2]==crypto(password))
            return;
    this->v.clear();
    this->v.push_back(username);
    this->v.push_back(email);
    this->v.push_back(crypto(password));
    this->array.push_back(this->v);
    ++this->lines;
    this->username=username;
    this->email=email;
    ofstream out(file);
    for(unsigned long long i=0;i<this->lines;++i)
        out<<array[i][0]<<','<<array[i][1]<<','<<array[i][2]<<'\n';
    out.close();
}

void Users::login(string email, string password)
{
    for(unsigned long long i=0;i<this->lines;++i)
        if(email==array[i][1]&&crypto(password)==array[i][2])
        {
            this->username=array[i][0];
            this->email=email;
        }
}

string Users::getusername()
{
    return this->username;
}

string Users::getemail()
{
    return this->email;
}

//booking
class Booking
{
    vector<vector<string> > array;
    vector<string> v;
    unsigned long long lines=0;
    string flying,departure,destination;
    public:
        ~Booking();
        void data_csv_read(string);
        void showdata();
        void findFlying(string,string,string);
        string getflying();
        string getdeparture();
        string getdestination();
};

Booking::~Booking()
{}

void Booking::findFlying(string flying, string departure, string destination)
{
    this->flying=this->departure=this->destination="";
    for(unsigned long long i=0;i<this->lines;++i)
        if(array[i][0]==flying&&array[i][1]==departure&&array[i][2]==destination)
        {
            this->flying=flying;
            this->departure=departure;
            this->destination=destination;
        }
}

void Booking::showdata()
{
    for(unsigned long long i=0;i<this->lines;++i)
        cout<<array[i][0]<<'\t'<<array[i][1]<<'\t'<<array[i][2]<<'\n';
}

void Booking::data_csv_read(string file)
{
    ifstream in(file);
    string line, field;

	this->lines=0;

    while (getline(in, line))
    {
        this->v.clear();
        stringstream ss(line);
		++this->lines;
        while (getline(ss, field, ','))
        {
            this->v.push_back(field);
        }
        this->array.push_back(this->v);
    }
	in.close();
}

string Booking::getflying()
{
    return this->flying;
}

string Booking::getdeparture()
{
    return this->departure;
}

string Booking::getdestination()
{
    return this->destination;
}

class Airlines
{
    vector<vector<string> > array;
    vector<string> v;
    unsigned long long lines=0;
    public:
        ~Airlines();
        void data_csv_read(string);
        void showdata();
        void addAirlines(string,string,string,string,string);
        void deleteAirlines(string,string,string,string,string);
        string getusername();
        string getflying();
        string getdeparture();
        string getdestination();
};

void Airlines::addAirlines(string file, string username, string flying, string departure, string destination)
{
    for(unsigned long long i=0;i<this->lines;++i)
        if(array[i][0]==username&&array[i][1]==flying&&array[i][2]==departure&&array[i][3]==destination)
            return;
    this->v.clear();
    this->v.push_back(username);
    this->v.push_back(flying);
    this->v.push_back(departure);
    this->v.push_back(destination);
    this->array.push_back(this->v);
    ++this->lines;
    ofstream out(file);
    for(unsigned long long i=0;i<this->lines;++i)
        out<<array[i][0]<<','<<array[i][1]<<','<<array[i][2]<<array[i][3]<<'\n';
    out.close();
}

void Airlines::deleteAirlines(string file, string username, string flying, string departure, string destination)
{
    bool find=false;
    for(unsigned long long i=0;i<this->lines&&!find;++i)
        if(array[i][0]==username&&array[i][1]==flying&&array[i][2]==departure&&array[i][3]==destination)
        {
            array[i].pop_back();
            find=true;
        }
    if(find)
    {
        --this->lines;
        ofstream out(file);
        for(unsigned long long i=0;i<this->lines;++i)
            out<<array[i][0]<<','<<array[i][1]<<','<<array[i][2]<<'\n';
        out.close();
    }
}

Airlines::~Airlines()
{}

void Airlines::showdata()
{
    for(unsigned long long i=0;i<this->lines;++i)
        cout<<array[i][0]<<'\t'<<array[i][1]<<'\t'<<array[i][2]<<'\t'<<array[i][3]<<'\n';
}

void Airlines::data_csv_read(string file)
{
    ifstream in(file);
    string line, field;

	this->lines=0;

    while (getline(in, line))
    {
        this->v.clear();
        stringstream ss(line);
		++this->lines;
        while (getline(ss, field, ','))
        {
            this->v.push_back(field);
        }
        this->array.push_back(this->v);
    }
	in.close();
}

#endif