//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johan Tuillier 336104120 ################
//###################################################


#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include<vector>

using namespace std;
class Player {
private:
    string name;
    vector<Card> cards;
    int num_of_cards;
public:
    int getNum_of_cards() const;

private:


    void generateCards();
	//private members

public:
	//public members

	bool play(Card&);
    int checkChoice(int choice,Card& card);
    const vector<Card> &getCards() const;

    Player(const Player&);
    Player(string name, int numCards);
    friend ostream& operator<<(ostream& os, const Player& player);
    Player& operator=(const Player& other);

};
#endif



