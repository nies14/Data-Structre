#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node
{
   int Value;
   Node* NextNode;

public:
    void SetValue(int v){Value = v;}
    int GetValue(){return Value;}
    void SetNextNode(Node* NN){NextNode = NN;}
    Node* GetNextNode(){return NextNode;}

};

#endif // NODE_H_INCLUDED
