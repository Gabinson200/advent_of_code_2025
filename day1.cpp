#include <iostream>
#include <fstream> 
using namespace std;

// left and right combinations are in filename.txt

int main(){
    string myText;
    ifstream MyReadFile("filename.txt");
    int pos = 50;
    int count = 0;

    while (getline (MyReadFile, myText)) {
        if(myText.at(0) == 'L'){
            pos -= std::stoi(myText.substr(1,2));
            if(pos < 0) pos = 99 - (pos % 99);
        }else if(myText.at(0) == 'R'){
            pos += std::stoi(myText.substr(1,2));
            if(pos > 99) pos = (pos % 99);
        }
        
        if(pos == 0) count++;
        //std::cout << pos << '\n';
    }

    MyReadFile.close(); 

    return count;
}