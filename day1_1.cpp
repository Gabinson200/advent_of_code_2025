#include <iostream>
#include <fstream> 
#include <string> // Include string for getline
#include <cmath>  // Include cmath just in case

using namespace std;

int main()
{
    string myText;
    ifstream MyReadFile("filename.txt"); 
    
    int pos = 50;
    int count = 0;

    while (getline(MyReadFile, myText)) {
        // cout << "Read: " << myText << " : "; 
        if (myText.at(0) == 'L') {
            pos -= std::stoi(myText.substr(1));
        } else if (myText.at(0) == 'R') {
            pos += std::stoi(myText.substr(1));
        }
        
        pos = ((pos % 100) + 100) % 100;
        if (pos == 0) count++;
        // cout << pos << '\n';
    }

    MyReadFile.close(); 

    cout << "Count: " << count << endl;

    return 0;
}