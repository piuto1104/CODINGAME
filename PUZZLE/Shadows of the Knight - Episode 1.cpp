#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int w; // width of the building.
int h; // height of the building.
int n; // maximum number of turns before game over.
int x_low =0;
int y_low =0;
int x_mid;
int y_mid;
int x_high =w;
int y_high =h;


void fn(char const &c) {
    if(c=='U'){ 
        y_high = y_mid;
        cerr << "\n include : U \n";
    } else if(c=='D'){ 
        y_low = y_mid;
        cerr << "\n include : D \n";
    } else if(c=='L'){ 
        x_high = x_mid;
        cerr << "\n include : L \n";
    } else if(c=='R'){ 
        x_low = x_mid;
        cerr << "\n include : R \n";
    }
}
 
void print(const std::string &s) {
}
 

int main()
{
    cin >> w >> h; cin.ignore();
    cin >> n; cin.ignore();
    cin >> x_mid >> y_mid; cin.ignore();

    x_low =0;
    y_low =0;
    x_high =w;
    y_high =h;
    cerr << n << "\n" ;
    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        // To debug: cerr << "Debug messages..." << endl;
        
        cerr << bomb_dir <<"\nbefore\n" ;
        cerr <<"low ("<< x_low << "," << y_low << endl;
        cerr <<"mid ("<< x_mid << " " << y_mid << endl;
        cerr <<"high ("<< x_high << " " << y_high << endl;
         
         
        for_each(bomb_dir.begin(), bomb_dir.end(), fn);  
       
       
        cerr << "\nmid\n" ;
        cerr <<"low ("<< x_low << "," << y_low << endl;
        cerr <<"mid ("<< x_mid << " " << y_mid << endl;
        cerr <<"high ("<< x_high << " " << y_high << endl;

        x_mid = (x_low + x_high)/2;
        y_mid = (y_low + y_high)/2;
        
        
        cerr << "\nafter\n" ;
        cerr <<"low ("<< x_low << "," << y_low << endl;
        cerr <<"mid ("<< x_mid << " " << y_mid << endl;
        cerr <<"high ("<< x_high << " " << y_high << endl;

        // the location of the next window Batman should jump to.
        cout << x_mid << " " << y_mid << endl;
    }
}