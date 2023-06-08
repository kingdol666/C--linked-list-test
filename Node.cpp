//
// Created by kingdol on 2023/6/6.
//
#include "Node.h"
#include <cstdio>

Node::Node(int date){
    this->date = date;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::~Node() = default;

void Node::add(Node* (&node), int val) {
     Node *newNode = new Node(val);
        if(node== nullptr){
            node = newNode;
        }else{
            Node* curNode = node;
            while(curNode->next != nullptr){
                curNode = curNode->next;
            }
            newNode->prev = curNode;
            curNode->next = newNode;
        }
}

void Node::insertNode(Node *(&node),int dol, int val) {
    Node* newNode = new Node(val);
    Node* curNode = node;
    if(dol==0) {
            curNode->prev = newNode;
            newNode->next = curNode;
            node = newNode;
            return;
        }
    if(node == nullptr){
        node = newNode;
        return;
    }else{
            for (int i = 1; i <= dol; ++i) {
                if(curNode->next == nullptr){
                    newNode->prev = curNode;
                    curNode->next = newNode;
                    return;
                }
                curNode = curNode->next;
            }
            if(curNode->next != nullptr){
                newNode->next = curNode->next;
                curNode->next->prev = newNode;
                newNode->prev = curNode;
                curNode->next = newNode;
                return;
            }else{
                newNode->prev = curNode;
                curNode->next = newNode;
                return;
            }

        }
}

void Node::removeNode(Node *&node, int dol) {
    Node* curNode = node;
    if(dol == 0){
        if(curNode->prev != nullptr){
            curNode->prev->next = nullptr;
            curNode->prev = nullptr;
        }else{
            node = curNode->next;
            curNode->next->prev = nullptr;
            curNode->next = nullptr;
        }
        return;
    }
    for (int i = 1; i <= dol; ++i) {
        if(curNode->next == nullptr){
            return;
        }else{
            curNode = curNode->next;
        }
    }
    if(curNode->next== nullptr){
        curNode->prev->next = nullptr;
        curNode->prev = nullptr;
        return;
    }else{
        curNode->next->prev = curNode->prev;
        curNode->prev->next = curNode->next;
        curNode->prev = nullptr;
        curNode->next = nullptr;
        return;
    }
}

bool Node::findNode(Node *&node, int val) {
    Node* curNode = node;
    while(curNode->prev != nullptr)
        curNode = curNode->prev;
    int x = 1;
    while(curNode != nullptr){
        if(curNode->date == val){
            printf("%d\n",x);
            return true;
        }
        x ++;
        curNode = curNode->next;
    }
    return false;
}
