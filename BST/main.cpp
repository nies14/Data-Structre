#include "BST.h"

int main()
{
    BST ob;

    ob.insert(10);
    ob.insert(20);
    ob.insert(5);
    ob.insert(3);
    ob.insert(2);
    ob.insert(21);
    ob.insert(16);
    ob.insert(19);

    ob.Inorder(ob.getroot());


    cout << "\nAfter deleting" << endl;
    ob.Delete(ob.getroot(),5);

    ob.Inorder(ob.getroot());
    return 0;
}
