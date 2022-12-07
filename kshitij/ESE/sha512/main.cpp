#include <iostream>
#include "sha512.h"
#include <string>
 
using std::string;
using std::cout;
using std::cin;
using std::endl;
 
int main(int argc, char *argv[])
{
    string input ;
    cout << "Please enter message: ";
    getline(cin, input);
    string output1 = sha512(input);
    
    cout << "\nsha512('"<< input << "'):" << output1 << endl;
    return 0;
}