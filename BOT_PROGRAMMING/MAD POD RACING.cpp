#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Point{
    int x[100];
    int y[100];
    int size;
    
    Point(){
        size =-1;
    }
    
    void addPoint(int targetX, int targetY){
        size++;
        x[size]=targetX;
        y[size]=targetY;
        if(size >1){
            
        }
    }

    bool checkPoint(int targetX, int targetY){
        bool hasPoint = false;
        for(int i=0;i<=size;i++){
            if(x[i]==targetX && y[i] == targetY){
                hasPoint=true;
                return hasPoint;
            }
        }
        addPoint(targetX,targetY);
        return hasPoint;
    }

}P;


const double PI = 3.1415926;

int x;
int y;
int nextCheckpointX; // x position of the next check point
int nextCheckpointY; // y position of the next check point
int nextCheckpointDist; // distance to the next checkpoint
int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
int opponentX;
int opponentY;
int beforeOpponentDist = -1;
int opponentDist;
double force;
double cosVal;
bool useBoost = false;
bool useShield = false;
string thrust; 
P targets;



/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void log(){
    cerr << "nextCheckpoint x:" << nextCheckpointX << ", y:" << nextCheckpointY << "\n";
    cerr << "nextCheckpoint angle:" << nextCheckpointAngle << "\n";
    cerr << "nextCheckpointDist:" << nextCheckpointDist << "\n";
    cerr << "x:" << x << ", y:" << y << "\n";
    cerr << "opponentX:" << opponentX << ", opponentY:" << opponentY << "\n";
    cerr << "opponentDist:" << opponentDist << "\n";
    cerr << "thrust :" << thrust << "\n";
    cerr << "useBoost :" << useBoost << " useShield :" << useShield << "\n";
}

void getForce(){  
        if(nextCheckpointDist >7000){
            force =100.0;
        }
        else {
            if (nextCheckpointAngle > 90 || nextCheckpointAngle < -90)  force = 0.0;
            else if (nextCheckpointAngle > 20 || nextCheckpointAngle < -20){
                cosVal = cos(nextCheckpointAngle * PI / 180);
                cerr << "cos val :" << cosVal << "\n";
                force = 100.0*cosVal*cosVal;
            }  
            else force =100.0;
        }

        thrust = to_string((int)force);
        if(!useBoost && nextCheckpointDist > 8000 && (nextCheckpointAngle < 5 && nextCheckpointAngle > -5)) {
            thrust = "BOOST";
            useBoost= true;
        }
        if(!useShield && force < 50 && opponentDist <1000){
            thrust = "SHIELD";
            useShield = true;
        }
}
void getOpponentDist(int x, int y, int opponentX, int opponentY){
    beforeOpponentDist = opponentDist;
    opponentDist = (int)sqrt((x-opponentX)*(x-opponentX) + (y-opponentY)*(y-opponentY));
}

void init(){
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle;  cin.ignore();
        cin >> opponentX >> opponentY; cin.ignore();
        targets.checkPoint(nextCheckpointX, nextCheckpointY);
        getOpponentDist(x,y,opponentX,opponentY);
}

int main()
{
    // game loop
    while (1) {
        init();
        getForce();
        log();
        cout << nextCheckpointX << " " << nextCheckpointY << " " << thrust<<"\n";
    }
}