#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int highHeight = 0;

    // game loop
    while (1) {
        highHeight = 0;
        int mountainNum = 0;

        for (int i = 0; i < 8; i++) {
            int mountain_h; // represents the height of one mountain.
            cin >> mountain_h; cin.ignore();
            if(mountain_h > highHeight){
                highHeight = mountain_h;
                mountainNum =i;
            }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << mountainNum << endl; // The index of the mountain to fire on.
    }
}