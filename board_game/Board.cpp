#include "Board.h"
using namespace std;

Node::Node(string o, Node *p) {
    owner = o;
    next = p;
}

Board::Board(int slots) {
    first = new Node("None", nullptr);
    Node * ptr = first;
    for (int i = 1; i < slots; i++){
        ptr->next = new Node("None", nullptr);  //adding i-1 number of nodes to board + first node is exclusively added
        ptr = ptr->next;
        if (i == slots - 1){
            ptr->next = first;  //the board is circular, ending tile is connected to first tile
        }
    }
}

Board::~Board(){
    while (true){
        Node * ptr = first->next;  //the node to be deleted
        if (ptr == first){
            delete ptr;  //I wont delete first for the second time with "delete first;"
            ptr = nullptr;
            first = nullptr;
            break;
        }
        else{
            first->next = first->next->next;
            //first is connected to the node after ptr, so that ptr is a separate node
            //and the structure of board is not messed up
            delete ptr;
            ptr = nullptr;
        }
    }
}

void Board::display(){
    int board_length = 0;
    Node * ptr = first;
    while(true){  //counting the board length so that I can create a sufficient for loop
        board_length++;
        if (ptr->next != first){
            ptr = ptr->next;
        }
        else if (ptr->next == first){
            ptr = first;
            break;
        }
    }
    string totalchart;
    string firstline;
    string secondline = "^"; //one side of board is given, other side will be added at the end
    string thirdline = "|";
    for (int i = 0; i < board_length; i++){
        if (ptr->next == first){
            firstline += ptr->owner;
            secondline += "  |";
            thirdline += "--v";  //adding necessary shapes for each node
            totalchart += firstline;
            totalchart += "\n";
            totalchart += secondline;
            totalchart += "\n";
            totalchart += thirdline;
            break;
        }
        else{
            if (ptr->owner == "None"){
                firstline += ptr->owner + "->";  //showing the owners of tile
            }
            else{
                firstline += ptr->owner + " ->";
            }
            secondline += "      ";
            thirdline += "----<-"; //ending part
            ptr = ptr->next;
        }
    }
    cout << totalchart << endl;
}

string Board::who_owns(Node * node_ptr){
    return node_ptr->owner;  //showing the owner of the node
}

Node * Board::first_ptr(){
    return this->first;  //showing the pointer of first node/tile
}