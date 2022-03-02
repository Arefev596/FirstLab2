#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


class Player {
public:
    Player() {}

    Player(string m_name) : name(m_name) {}
    string getName() {
        return name;
    }
    int getScore() {
        return score;
    }
    vector <string> Players = { "Master", "Beginner" };

private:
    string name;
    int score;
};

class Print : public Player {
public:

    Print() {}

    void print() {
        cout << "Игроки: ";
        for (vector<string>::iterator it = Players.begin(); it != Players.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};


class Add : public Player {
public:
    Add() {}

    void addPlayer(string player) {
        Players.push_back(player);
        cout << player << " добавлен в список! \n";
    }

};

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));
    Print pr;
    Add add;

    add.addPlayer("Master");
    add.addPlayer("Beginner");
    pr.print();


    return 0;
}