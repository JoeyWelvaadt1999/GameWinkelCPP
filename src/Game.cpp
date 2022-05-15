#include "./include/Game.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <cmath>

using namespace std;
// using namespace GW;

Game::Game(string title, int releaseDate, float originalPrice) {
    Game::setTitle(title);
    Game::setReleaseDate(releaseDate);
    Game::setOriginalPrice(originalPrice);

}

float Game::calculateCurrentPrice() {
    time_t now = time(0);
    tm *localNow = localtime(&now);
    int currentYear =  1900 + localNow->tm_year;
    int yearDifference = abs(currentYear - Game::getReleaseDate());

    float result = Game::getOriginalPrice();

    for (int i = 0; i < yearDifference; i++) {
        result -= result * 0.3;
    }
    return result;
}

string Game::getTitle() {
    return Game::title;
}

int Game::getReleaseDate() {
    return Game::releaseDate;
}

float Game::getOriginalPrice() {
    return Game::originalPrice;
}

void Game::setTitle(string title) {
    Game::title = title;
}

void Game::setReleaseDate(int releaseDate) {
    Game::releaseDate = releaseDate;
}

void Game::setOriginalPrice(float originalPrice) {
    Game::originalPrice = originalPrice;
}

bool Game::operator ==(const Game& val) {;
    if(Game::getTitle() == val.title && Game::getReleaseDate() == val.releaseDate && Game::getOriginalPrice() == val.originalPrice) {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& os, Game g) {
    
    os << g.getTitle() << ", released " << g.getReleaseDate() << "; original price: $" << g.getOriginalPrice() << " now: $" << (floor(g.calculateCurrentPrice() * 100.0) / 100.0);
    return os;
}

