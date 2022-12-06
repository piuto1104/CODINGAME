#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int result = 0xfffff;
    int isNegative = false;
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        cerr << t <<" ";

        if(t>0){
            if(result >= t) {
                result = t;
                isNegative = false;
            }
        } else {
            if(result > -t) {
                result = -t;
                isNegative = true;
            }
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if(result == 0xfffff) cout << "0";
    else if(isNegative)  cout << -result << endl;
    else  cout << result << endl;
}