#include <ctime>
#include <iostream>
#include "./include/Person.hpp"

using namespace std;

void printTransaction(bool success, string who, string what, string action) {
    cout << who << " " << action << " " << what << " " << (success ? "success" : "failed") << endl;
}

int main()
{
    std::time_t result = std::time(NULL);
    cout << std::asctime(std::localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int releaseDate1 = tm_local->tm_year + 1899; // 1 jaar geleden
    int releaseDate2 = tm_local->tm_year + 1898; // 2 jaar geleden
    
    Game g1("Just Cause 3", releaseDate1 , 49.98);
    Game g2("Need for Speed: Rivals", releaseDate2 , 45.99);
    Game g3("Need for Speed: Rivals", releaseDate2 , 45.99);
    
    Person p1("Eric", 200);
    Person p2("Hans", 55);
    Person p3("Arno", 185);
    
    // Druk de volgende transacties af (pas de code aan)
    printTransaction(p1.buy(g1), "p1", "g1", "buys");
    printTransaction(p1.buy(g2), "p1", "g2", "buys");
    printTransaction(p1.buy(g3), "p1", "g3", "buys");
    printTransaction(p2.buy(g2), "p2", "g2", "buys");
    printTransaction(p2.buy(g1), "p2", "g1", "buys");
    printTransaction(p3.buy(g3), "p3", "g3", "buys");
    
    // Druk personen p1, p2 en p3 nu af naar de console
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    
    // Druk de volgende transacties af (pas de code aan)
    
    printTransaction(p1.sell(g1, p3), "p1", "g1 to p3", "sells");
    printTransaction(p2.sell(g2, p3), "p2", "g2 to p3", "sells");
    printTransaction(p2.sell(g1, p1), "p2", "g1 to p1", "sells");
    
    // Druk personen p1, p2 en p3 nu af naar de console
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    return 0;
}

