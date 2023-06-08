#include <iostream>
using namespace std;
#include "Node.h"

int main() {
    Node *node = new Node(5);
    Node::add(node,1);
    Node::add(node,10);
    Node::insertNode(node,0,1);
    Node::insertNode(node,1,3);
    Node::insertNode(node,3,6);
    Node::insertNode(node,10,9);
    Node::removeNode(node,0);
    bool isFind = Node::findNode(node,6);
    if(isFind){
        cout << "find it" << endl;
    }else{
        cout << "not find" << endl;
    }
    while(node != nullptr){
        cout << node->date << " ";
        node = node->next;
    }
    delete node;
    return 0;
}
