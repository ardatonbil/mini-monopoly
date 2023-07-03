#include <iostream>
#include "Board.h"
using namespace std;

#ifndef HW5_PLAYER_H
#define HW5_PLAYER_H


class Player {
private:
    string name;
    int balance; //budget, others are self explanatory
    Node * position;
    Board &boardofplayer;
public:
    Player(Board &board, string nameofplayer, int initialcapital);
    ~Player();
    int move (int steps);
    Node * where_am_I();
    void pay_to_player(Player &otherplayer, int money);
    int get_balance();
    void deposit_money(int addition);
    void buy_slot(int slot_price);
    bool is_bankrupt();
    void display();
};



#endif //HW5_PLAYER_H
