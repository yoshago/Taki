#include "Game.h"

using namespace std;

Game::Game() {
    direction = true;
    gameOver = false;
    turn =0;
    int numPlayers, numCards;
    cout<<"How many players?\n";
    cin>>numPlayers;
    if(numPlayers<0){
        cout<<"illegal operation"<<endl;
        exit(0);
    }
    cout<<"How many cards?\n";
    cin>>numCards;
    if(numCards<0){
        cout<<"illegal operation"<<endl;
        exit(0);
    }

    for(int i=1;i<=numPlayers;i++){
        string name;
        cout<<"player number " <<i<< " name?\n";
        cin>>name;
        Player player(name, numCards);
        Game::players.push_back(player);
    }
    currentCard = Card::generate_card();
    currentPlayer = &players[turn];
}
void Game::start(){
    while(!gameOver){
        printTurnOptions();
        bool flag;
        flag = currentPlayer->play(currentCard);
        if (currentPlayer->getNum_of_cards()==0) gameOver = true;
        else nextTurn(flag);
    }
    cout<<*currentPlayer<<" wins!"<<endl;



}

void Game::printTurnOptions(){
    cout<<"current: "<<currentCard<<endl;
    cout<<*currentPlayer<<", your turn -"<<endl<<"Your cards: ";
    for(int i=0;i<currentPlayer->getCards().size();i++){
        cout<<"("<<i+1<<")"<<currentPlayer->getCards()[i]<<" ";
    }
    cout<<endl;

}


void Game::nextTurn(bool flag) {
    if (flag) {
        if (currentCard.get_sign() == sign::STOP) {
            if (direction)
                turn = (turn + 2) % players.size();
            else turn = (turn +players.size() - 2) % players.size();
        } else if (currentCard.get_sign() == sign::PLUS) { return; }
        else if (currentCard.get_sign() == sign::CD) {
            direction = !direction;
            if (direction)
                turn = (turn + 1) % players.size();
            else turn = (turn +players.size() - 1) % players.size();
        }
        else {
            if (direction)
                turn = (turn + 1) % players.size();
            else turn = (turn +players.size() - 1) % players.size();
        }
    }
    else {
        if (direction)
            turn = (turn + 1) % players.size();
        else turn = (turn +players.size() - 1) % players.size();
    }
    currentPlayer = &players[turn];

}

void Game::setGameOver(bool gameOver) {
    Game::gameOver = gameOver;
}



