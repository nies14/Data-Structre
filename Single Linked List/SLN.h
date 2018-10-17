#ifndef SLN_H_INCLUDED
#define SLN_H_INCLUDED

#include<iostream>
#include "Node.h"

using namespace std;

class SLN
{
private:
   Node* HeadNode;
   Node* CurrentNode;
   Node* PreviousNode;
   int Sz;
public:
    SLN();
    ~SLN();
    int add(int num);
    void display();
    int search(int n);
    int insert(int x,int pos);
    int GetSize();

};


SLN :: SLN()
{
    HeadNode = new Node;
    HeadNode->SetValue(0);
    HeadNode->SetNextNode(NULL);
    CurrentNode = NULL;
    PreviousNode = NULL;
    Sz = 0;
}

SLN :: ~SLN()
{
    delete HeadNode;
    delete CurrentNode;
    delete PreviousNode;

}

int SLN :: GetSize()
{
    return Sz;
}

int SLN :: add(int num)
{
    if(GetSize() == 0)
    {
        CurrentNode = new Node;
        CurrentNode->SetNextNode(NULL);
        CurrentNode->SetValue(num);

        HeadNode ->SetNextNode(CurrentNode);
    }

    else
    {
        PreviousNode = CurrentNode;

        CurrentNode = new Node;
        CurrentNode->SetNextNode(NULL);
        CurrentNode->SetValue(num);

        PreviousNode ->SetNextNode(CurrentNode);
    }
    Sz++;
}

void SLN :: display()
{
   if(GetSize()>0)
   {
       Node* item = HeadNode->GetNextNode();

       while (item != NULL)
       {
           cout <<item->GetValue() << endl;
           item = item->GetNextNode();
       }
       cout << endl;
   }
}

int SLN :: search(int n)
{
    int f;
    if(GetSize()>0)
   {
       Node* item = HeadNode->GetNextNode();

       while (item != NULL)
       {
           if(item->GetValue() == n)
           {
               cout << "Found" << endl;
               f = 1;
               break;
           }
           else
           item = item->GetNextNode();
       }
       cout << endl;

   }
   if(f!=1)
   {
       cout << "Not Found" << endl;
   }

cout << endl;
}

/*int SLN :: insert(int x)
{
        Node* item = CurrentNode;
        PreviousNode = CurrentNode;
        CurrentNode = new Node;
        CurrentNode->SetNextNode(NULL);
        CurrentNode->SetValue(x);

        PreviousNode ->SetNextNode(CurrentNode);
        Sz++;

}*/

int SLN :: insert(int x,int pos)
{
        //Node* item = HeadNode;
        Node* item = HeadNode->GetNextNode();
        while(item->GetValue() != pos)
        {
           item = item->GetNextNode();
        }
           if(item->GetValue() == pos)
        {
            //cout << "jnfkln";
            Node* NewNode = new Node;
            NewNode->SetValue(x);
            NewNode->SetNextNode(item ->GetNextNode());

            item->SetNextNode(NewNode);
            Sz++;
        }



}




#endif // SLN_H_INCLUDED
