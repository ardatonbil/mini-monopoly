#include "Player.h"
using namespace std;

Player::Player(Board &board, string nameofplayer, int initialcapital)
    : boardofplayer(board), name(nameofplayer), balance(initialcapital)
    {
    //parametric constructor, same board shared for two players
    position = boardofplayer.first_ptr();
    }

Player::~Player(){
    //destructor, only thing altered is the position
    //since it is the only dynamically allocated part
    //also I didnt delete because it's already deleted by board destructor
    position = nullptr;
}

int Player::move(int steps) {
    int first_node_count = 0; //this function is for moving the player and checking if the first node bonus is gained
    for (int i = 0; i < steps; i++){
        position = position->next;
        if (position == boardofplayer.first_ptr()){
            first_node_count = 1;
        }
    }
    return first_node_count;
}

void Player::deposit_money(int addition) {
    balance = balance + addition;  //self explanatory
}

Node* Player::where_am_I() {
    return position; //self explanatory
}

void Player::pay_to_player(Player &otherplayer, int money){
    this->balance -= money;  //paying from lhs to rhs
    otherplayer.balance += money;
}

int Player::get_balance(){
    return balance;  //self explanatory
}

void Player::buy_slot(int slot_price){
    this->balance -= slot_price;  //money is taken and slot is given to lhs player
    this->position->owner = this->name;
}

bool Player::is_bankrupt(){
    if (balance < 0){  //checking if lhs has gone bankrupt
        return true;
    }
    else{
        return false;
    }
}

void Player::display() {
    int position_index = 0;
    Node * ptr = boardofplayer.first_ptr();
    string spaces = "";
    while (true){
        if (ptr == position){
            break;
        }
        else{
            position_index++;
            ptr = ptr->next;
            spaces += "      ";  //these spaces are to show the spot of the player
        }
    }
    cout << spaces << name << " " << balance << endl;
}


