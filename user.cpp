#include <iostream>
#include "user.h"
#include <string>
using namespace std;


 User::User(){
     entereduser = " ";
     enteredpassword = " ";
 }

 User::User(string username,string password){
     entereduser = username;
     enteredpassword = password;
     bool status = isCorrect(enteredpassword);

     while (status==0){
      std::cout<< "Please enter your password again: ";
       cin >> enteredpassword;
      status = isCorrect(enteredpassword);
       cout << endl;
     }
 }

  void User::setusername(string username){
   entereduser = username;
  }

  void User::setpassword(string password){
   enteredpassword = password;
  }

 bool User::isCorrect(string password){
   int min = 8;
    int max = 16;
    int len = password.length();
   if (len< min){
       cout << "Invalid Password. Not enough characters." << endl;
       return 0;
    }
    else if(len > max){
       cout << "Invalid Password. Too many characters." << endl;
       return 0;
    }
    return 1;
 }

 string User::getusername(){
    return entereduser;
 }

 string User::getpassword(){
    return enteredpassword;
 }

 User::~User(){
 }
