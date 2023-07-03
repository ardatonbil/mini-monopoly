#include <iostream>
using namespace std;
#ifndef HW5_BOARD_H
#define HW5_BOARD_H

struct Node {  //each tile of the board is Node
    string owner;
    Node* next;
    Node (string o, Node * p);
};

class Board {

private:
    Node * first;

public:
    ~Board();
    Board(int slots);
    void display();
    string who_owns(Node * node_ptr);
    Node * first_ptr();
};


#endif //HW5_BOARD_H
