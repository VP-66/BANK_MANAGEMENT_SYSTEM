#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using namespace std;

class User{
    private:
    string entereduser;
    string enteredpassword;
    string username;
    string password;

    public:
    User();
    User(string username,string password);
    bool isCorrect(string password);
    void setusername(string username);
    string getusername();
    void setpassword(string password);
    string getpassword();
    ~User();

};
#endif