#include <list>
#include <iostream>
#include "./Game.hpp"
using namespace std;

class Person {
    private:
        list<Game> games;
        float budget;
        string name;
    public:
        Person(string name, float budget);
        bool buy(Game game);
        bool sell(Game game, Person& buyer);
        float getBudget();
        void setBudget(float budget);
        list<Game> getGames();
        void setGames(list<Game> games);
        void addGame(Game game);
        void removeGame(Game game);
        string getName();
        void setName(string name);
        friend ostream& operator<<(ostream& os, Person& p);
};
