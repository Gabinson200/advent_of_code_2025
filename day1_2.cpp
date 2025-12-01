#include <iostream>
#include <fstream> 
#include <string> 

using namespace std;

int main()
{
    string myText;
    ifstream MyReadFile("filename.txt"); 
    
    int pos = 50;
    int count = 0;

    while (getline(MyReadFile, myText)) {

        char dir = myText.at(0);
        int change = std::stoi(myText.substr(1));

        if (dir == 'R') {
            count += (pos + change) / 100;
            pos = (pos + change) % 100;
        } 
        if (dir == 'L') {
            // If we are already at 0, the next 0 is 100 clicks away (left), not 0.
            int dist_to_zero = (pos == 0) ? 100 : pos;

            if (change >= dist_to_zero) {
                count++;
                int remaining = change - dist_to_zero;
                count += remaining / 100;
            }
            pos = pos - change;
            pos = ((pos % 100) + 100) % 100;
        }
    }

    MyReadFile.close(); 
    
    cout << "Final Password Count: " << count << endl;

    return 0;
}