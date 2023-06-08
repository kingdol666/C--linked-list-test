//
// Created by kingdol on 2023/6/6.
//

#ifndef C__TEST02_NODE_H
//#define C__TEST02_NODE_H


class Node {
public:
    int date;
    Node *next;
    static void add(Node* (&node), int val);
    Node *prev;
public:
    explicit Node(int date);
    ~Node();
    static void insertNode(Node* (&node),int dol, int val);
    static void removeNode(Node* (&node),int dol);
    static bool findNode(Node* (&node), int val);
};


#endif //C__TEST02_NODE_H
