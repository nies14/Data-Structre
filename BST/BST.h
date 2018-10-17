#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include "Node.h"


class BST
{
    Node* Root;

public:

    BST(){Root = NULL;}
    ~BST(){delete Root;}

    void setroot(Node* R){Root = R;}
    Node* getroot(){return Root;}

    void insert(int a);
    void Inorder(Node* RON);

    Node* Delete(Node* N, int a);
    Node* FindMin(Node* N);

    void Search(Node* N, int a);
};

Node* BST :: FindMin(Node* N)
{
    if (N == NULL) return N;
    else if (N->getleft() == NULL) return N;
	else FindMin (N->getleft());
}
 void BST :: insert(int a)
 {
     if(Root == NULL)
     {
         Node* NN = new Node(a);
         setroot(NN);
     }

     else
     {
         Node *p,*q;
         p = q = Root;

         while(p -> getvalue() != a && q != NULL)
         {
             p = q;

             if(a < p ->getvalue())
             {
                 q = p->getleft();
             }

             else
             {
                 q = p->getright();
             }
         }

         if(p->getvalue() == a)
         {
             cout << "Duplicate Value" <<endl;
         }

         else if(a < p->getvalue())
         {
             Node* NN = new Node(a);
             p->setleft(NN);
         }

         else
         {
            Node* NN = new Node(a);
            p->setright(NN);
         }
     }

 }


void BST :: Inorder(Node* RON)
{
    if(RON != NULL)
    {
        //cout << RON->getvalue() << "\t";
        Inorder(RON -> getleft());
        //cout << RON->getvalue() << "\t";
        cout << RON->getvalue() << "\t";
        Inorder(RON -> getright());
        //cout << RON->getvalue() << "\t";
    }
}


Node* BST :: Delete (Node* N, int a) {
	Node *NN;
	if (a < N->getvalue())
	{
		NN = Delete(N->getleft(), a);
		N->setleft(NN);
	}
	else if (a > N->getvalue()) {
		NN = Delete(N->getright(), a);
		N->setright(NN);
	}
	else if (N->getleft() != NULL && N->getright() != NULL)
    {
		Node* MN = FindMin (N->getright());
		N->setvalue (MN->getvalue());
		NN = Delete (N->getright(), MN->getvalue());
		N->setright(NN);
	}

	else
    {
		if (N->getright() == NULL) {
			N = N->getleft();
		}
		else if (N->getleft() == NULL) {
			N = N->getright();
		}
		else N = NULL;
	}
	return N;
}

void BST :: Search(Node* N, int a)
{

}


#endif // BST_H_INCLUDED
