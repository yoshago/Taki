//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johan Tuillier 336104120 ################
//###################################################

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>

class Game {
private:
    std::vector<Player> players;
    bool direction;
    Player* currentPlayer;
    Card currentCard;
    bool gameOver;
public:
	void setGameOver(bool gameOver);

private:
	int turn;

public:
	//public members and functions
	void start();
	void printTurnOptions();
	void nextTurn(bool flag);

    Game();
};
#endif




