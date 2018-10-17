#include <iostream>

using namespace std;

class Node {
    int value;
    Node* NextNode;
    Node* PreviousNode;

public:
    void setvalue(int x){value = x;}
    int getvalue(){return value;}
    void setNextNode(Node* NN) {NextNode=NN;}
    Node* getNextNode() {return NextNode;}
    void setPreviousNode(Node* PN) {PreviousNode=PN;}
    Node* getPreviousNode() {return PreviousNode;}

};

class DLN{
    Node* HeadNode;
    Node* CurrentNode;
    int Sz;

public:
    DLN();
    ~DLN();
    void add(int Value);
    void Insert(int value,int pos);
    void Remove (int x);
    void PrintAllValues();
    void PrintValuesInReverse();
    int GetRecentValue();
    int Size();
};


DLN::DLN()
{
    HeadNode = new Node;
    HeadNode->setvalue(0);
    HeadNode->setPreviousNode(NULL);
    HeadNode->setNextNode(NULL);
    CurrentNode = HeadNode;
    Sz=0;
}
DLN::~DLN()
{
    delete CurrentNode;
    delete HeadNode;
}

void DLN :: add(int Value)
{
    Node* NewNode = new Node;
    NewNode->setvalue(Value);
    NewNode->setPreviousNode(CurrentNode);
    NewNode->setNextNode(NULL);
	CurrentNode->setNextNode(NewNode);
    CurrentNode=NewNode;
    Sz++;
}
void DLN :: Insert(int value,int pos)
{
    Node* item = HeadNode->getNextNode();
    while(item->getvalue() != pos)
    {
        item = item->getNextNode();
    }
    if(item->getvalue() == pos)
    {
        //cout << "jnfkln";
        Node* NewNode = new Node;
        NewNode->setvalue(value);
        NewNode->setPreviousNode(item->getPreviousNode());
        NewNode->setNextNode(item);
        (item->getPreviousNode())->setNextNode(NewNode);
        item->setPreviousNode(NewNode);
        Sz++;
    }
}
void DLN :: Remove (int x)
{
    if (Sz>0)
    {
        Node* item = CurrentNode;

        while (item != HeadNode)
        {
            if(item->getvalue() == x)
            {
                Node* PN = item->getPreviousNode();
				Node* NN = item->getNextNode();

                PN->setNextNode(NN);

                if(item == CurrentNode)
                {
                    CurrentNode = PN;
                }
                else
                {
                    NN->setPreviousNode(PN);
				}

                Sz--;
                delete item;
                break;

            }
			else
				item=item->getPreviousNode();

        }
    }
}


/*void DLN :: PrintAllValues()
{
if (Sz>0)
    {
        Node* item = HeadNode->getNextNode();
        while (item!=CurrentNode)
        {
            cout << item->getvalue() << "\t";
            item = item->getNextNode();

        }
        cout << CurrentNode->getvalue()<<endl;

    }

}*/

void DLN :: PrintValuesInReverse()
{
    if (Sz>0)
    {
        Node* item = CurrentNode;
        while (item!=HeadNode)
        {
            cout << item->getvalue() << "\t";
            item = item->getPreviousNode();

        }
        cout << endl;

    }

}

int DLN :: GetRecentValue()
{
    if(Sz>0)
    {
        return CurrentNode->getvalue();
    }
    else
        return -1;

}

int DLN :: Size()
{
    return Sz;

}


int main()
{
    DLN ob;

    ob.add(15);
    ob.add(30);
    ob.add(75);
    ob.add(80);
    ob.PrintValuesInReverse();
    cout << ob.Size() << endl;
    ob.Remove(30);
    ob.Insert(78,75);
    ob.PrintValuesInReverse();
    cout << ob.Size() << endl;
    return 0;
}

