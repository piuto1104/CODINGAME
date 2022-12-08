#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Grab the pellets as fast as you can!
 **/

typedef struct Position{
    int x, y;
    Position(int x, int y): x(x),y(y){}
}Position;

typedef struct Pac{
    int pac_id; // pac number (unique within a team)
    Position pos;
    string type_id; // unused in wood leagues
    int speed_turns_left; // unused in wood leagues
    int ability_cooldown; // unused in wood leagues
    Pac(int pac_id, Position pos, string type_id, int speed_turns_left, int ability_cooldown)
        :pac_id(pac_id), pos(pos), type_id(type_id), speed_turns_left(speed_turns_left), ability_cooldown(ability_cooldown) {}
}Pac;


typedef struct Pellet{
    Position pos;
    int value; // amount of points this pellet is worth
    Pellet(Position pos, int value):pos(pos), value(value) {}
}Pellet;


bool CompValue(const Pellet& x, const Pellet& y){
    return x.value > y.value;
}


class PacGame{
private:
    int WIDTH, HEIGHT;
    int myScore, opponentScore;
    vector<string> map;
    vector<Pac> myPacs, enemies;
    vector<Pellet> pellets;

public:
    PacGame() {
        initMap();
    }

    void initMap() {
        cin >> WIDTH >> HEIGHT; cin.ignore();
        for (int i = 0; i < HEIGHT; i++) {
            string row;
            getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall   
            map.push_back(row);
        }
    }

    void initPac() {
        myPacs.clear();
        enemies.clear();

        int my_score;
        int opponent_score;
        cin >> my_score >> opponent_score; cin.ignore();
        int visible_pac_count; // all your pacs and enemy pacs in sight
        cin >> visible_pac_count; cin.ignore();
        for (int i = 0; i < visible_pac_count; i++) {
            int pac_id; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string type_id; // unused in wood leagues
            int speed_turns_left; // unused in wood leagues
            int ability_cooldown; // unused in wood leagues
            cin >> pac_id >> mine >> x >> y >> type_id >> speed_turns_left >> ability_cooldown; cin.ignore();

            if (mine){
                myPacs.push_back(Pac(pac_id,Position(x,y),type_id,speed_turns_left,ability_cooldown));
            }
            else {
                enemies.push_back(Pac(pac_id,Position(x,y),type_id,speed_turns_left,ability_cooldown));
            }
        }
    }

    void initPellet(){
        pellets.clear();

        int visible_pellet_count; // all pellets in sight
        cin >> visible_pellet_count; cin.ignore();
        for (int i = 0; i < visible_pellet_count; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
            if(value > 1) cerr << x <<","<<y<<","<<value<<endl;
            pellets.push_back(Pellet(Position(x,y),value));
        }
    }

    void nextMove(){
        sort(pellets.begin(), pellets.end(), CompValue);
        for(int i=0;i<myPacs.size();i++){
            cout << "MOVE "<< myPacs[i].pac_id << " "<< pellets[i].pos.x << " "<< pellets[i].pos.y << "\n";
            cerr << "pellet("<<pellets[i].pos.x<<","<<pellets[i].pos.y<<") : "<< pellets[i].value<<"\n";
        }
    }
};


int main()
{
    PacGame pacGame = PacGame();

    // game loop
    while (1) {
        pacGame.initPac();
        pacGame.initPellet();
        pacGame.nextMove();
    }
}