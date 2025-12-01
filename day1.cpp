/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream> 
using namespace std;


int main()
{
    string myText;
    ifstream MyReadFile("test.txt");
    int pos = 50;
    int count = 0;

    while (getline (MyReadFile, myText)) {
        std::cout << myText << " : ";
        if(myText.at(0) == 'L'){
            pos -= std::stoi(myText.substr(1,2));
            if(pos < 0) pos = 100 - abs(pos % 99);
        }else if(myText.at(0) == 'R'){
            pos += std::stoi(myText.substr(1,2));
            if(pos > 99) pos = (pos % 100);
        }
        
        if(pos == 0) count++;
        std::cout << pos << '\n';
    }

    MyReadFile.close(); 

    return count;
}