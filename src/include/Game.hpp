#include <iostream>

using namespace std;
class Game {
    private: 
        string title;
        int releaseDate;
        float originalPrice;

    public:
        Game(string title, int releaseDate, float originalPrice);
        string getTitle();
        void setTitle(string title);
        int getReleaseDate();
        void setReleaseDate(int releaseDate);
        float getOriginalPrice();
        void setOriginalPrice(float originalPrice);
        float calculateCurrentPrice();
        bool operator ==(const Game& val);
        friend ostream& operator<<(ostream& os, Game g);
        
};
    


