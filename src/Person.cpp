#include "./include/Person.hpp"
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

Person::Person(string name, float budget) {
    Person::setBudget(budget);
    Person::setName(name);
}

bool Person::buy(Game game) {
    list<Game> games = Person::getGames();
    if(find(games.begin(), games.end(), game) == games.end()) {
        if(Person::getBudget() > game.calculateCurrentPrice()) {
            Person::setBudget(Person::getBudget() - game.calculateCurrentPrice());
            Person::addGame(game);
            return true;
        }
    }
    return false;
}

bool Person::sell(Game game, Person& buyer) {
    if(find(buyer.games.begin(), buyer.games.end(), game) == buyer.games.end() && find(games.begin(), games.end(), game) != games.end()) { 
        if(buyer.getBudget() > game.calculateCurrentPrice()) {
            Person::removeGame(game);
            buyer.addGame(game);
            buyer.setBudget(buyer.getBudget() - game.calculateCurrentPrice());
            Person::setBudget(Person::getBudget() + game.calculateCurrentPrice());
            return true;
        } 
    }
    return false;
}

float Person::getBudget() {
    return Person::budget;
}

void Person::setBudget(float budget) {
    Person::budget = budget;
}

list<Game> Person::getGames() {
    return Person::games;
}

void Person::setGames(list<Game> games) {
    Person::games = games;
}

void Person::addGame(Game game) {
    Person::games.push_back(game);
}

void Person::removeGame(Game game) {
    Person::games.erase(find(Person::games.begin(), Person::games.end(), game));
}

string Person::getName() {
    return Person::name;
}

void Person::setName(string name) {
    Person::name = name;
}

ostream& operator<<(ostream& os, Person& p) {
    os << p.getName() << "'s budget is $" << p.getBudget() << " and owns: \n" ;

    list<Game>::const_iterator it = p.games.cbegin();

    for(it; it != p.games.end(); ++it) {
        os << *it << '\n';
    }
    return os;
}