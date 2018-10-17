#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>

using namespace std;


class Node
{
    int value;
    Node* left;
    Node* right;

public:

    Node(){value = NULL; left = NULL; right = NULL;}
    Node(int a){value = a; left = NULL; right = NULL;}
    ~Node(){delete left; delete right;}

    void setvalue(int x){value = x;}
    int getvalue(){return value;}

    void setleft(Node* LN){left = LN;}
    Node* getleft(){return left;}

    void setright(Node* RN){right = RN;}
    Node* getright(){return right;}

};

#endif // NODE_H_INCLUDED
