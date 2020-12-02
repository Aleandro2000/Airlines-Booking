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

void Users::create_account(string username, string email, string password)
{
    this->v.push_back(username);
    this->v.push_back(email);
    this->v.push_back(crypto(password));
    this->array.push_back(this->v);
    ++this->lines;
}

void Users::login(string email, string password)
{
    for(unsigned long long i=0;i<this->lines;++i)
        if(email==array[i][1]&&crypto(password)==array[i][2])
        {
            this->username=array[i][0];
            this->email=email;
            this->password=password;
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

string Users::getpassword()
{
    return this->password;
}

//booking
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

Booking::~Booking()
{}

string Booking::findFlying(unsigned long long index)
{
    if(index<=this->lines&&this->lines)
        return array[index][1];
    else
        return "";
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

unsigned long long Booking::getindex()
{
    return this->index;
}

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

void Airlines::addAirlines(string username, string flying)
{
    this->v.push_back(username);
    this->v.push_back(flying);
    this->array.push_back(this->v);
    ++this->lines;
}

void Airlines::deleteAirlines(string file, unsigned long long index)
{
    if(this->lines&&index<=this->lines)
    {
        array[index].pop_back();
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
        cout<<array[i][0]<<'\t'<<array[i][1]<<'\n';
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

string Airlines::getusername()
{
    return this->username;
}

string Airlines::getflying()
{
    return this->flying;
}

unsigned long long Airlines::getindex()
{
    return this->index;
}

#endif