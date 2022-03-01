#include <iostream>
#include <vector>

using namespace std;

class Viewer;
class PlayersTruck;

class Player {
public:
    Player(string m_name) : name(m_name) {};
    friend class Viewer;
    friend class Play;
protected:
    string name;
    int score;
};

class Master : public Player {
public:
    Master() : Player("Master") {};
};

class Beginner : public Player {
public:
    Beginner() : Player("Beginner") {};
};

class Darts {
public:
    Darts() {};
    friend class PlayersTruck;
    friend class Viewer;
protected:
    vector <Player*> Players;
    int Score;
};

class PlayersTruck {
public:
    PlayersTruck() {};
    void add(Player* Player, Darts* darts) {
        darts->Players.push_back(Player);
    }
};

class Viewer {
public:
    Viewer() {};
    void print(Darts* darts) {
        for (auto Player : darts->Players) {
            cout << Player->name << endl;
        }
    }
};

class Play {
public:
    Play() {};
    void DropDart(Player* player) {
        player->score = rand() % 100;
        cout << player->score;
    }
};

int main() {
    srand(time(0));
    Darts Darts;
    PlayersTruck truck;
    Play play;

    truck.add(new Master(), &Darts);
    truck.add(new Master(), &Darts);
    truck.add(new Beginner(), &Darts);

    Viewer look;
    look.print(&Darts);
    play.DropDart(new Master());


    return 0;
}