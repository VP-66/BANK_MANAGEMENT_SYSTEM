#include <iostream>
#include "user.h"
#include <string>

using namespace std;

int main(){

    User test("Janet", "yatalaprisons");
    if(test.getusername() != "Janet"){
        cout << "Test is Unuccesful01" << endl;
    }

    if(test.getpassword() != "yatalaprisons"){
        cout << "Test is Unsccesful02" << endl;
    }

    test.setusername("Lawrence");
    if(test.getusername() != "Lawrence"){
        cout << "Test is Unsuccesful03" << endl;
    }

    test.setpassword("jamesnashhouse");
    if(test.getpassword() != "jamesnashhouse"){
        cout << "Test is Unsuccesful04" << endl;
    }


    test.setusername("Vidit Patel");
    if(test.getusername() != "Vidit Patel"){
        cout << "Test is Unsuccesful05" << endl;
    }

    test.setpassword("TraceyHopps");
    if(test.getpassword() != "TraceyHopps"){
        cout << "Test is Unsuccesful06" << endl;
    }

    return 0;
}