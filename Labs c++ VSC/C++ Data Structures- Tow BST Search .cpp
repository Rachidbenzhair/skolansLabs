#include <iostream>
using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST
{
private:
    Node* root;

public:
    BST() { root = nullptr; }
    Node* getRoot() { return root; }
    void Insert(int key);
    Node* iSearch(int key);
    Node* rSearch(Node* p, int key);

};
void BST::Insert(int key)
{
    Node* t = root;
    Node* p;
    Node* r = nullptr;

    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }

    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;


    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }

}
Node* BST::iSearch(int key)
{
    Node* t = root;
    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return nullptr;
}
Node* BST::rSearch(Node* p, int key)
{
    if (p == nullptr)
        return nullptr;

    if (key == p->data)
    {
        return p;
    }
    else if (key < p->data)
    {
        return rSearch(p->lchild, key);
    }
    else
    {
        return rSearch(p->rchild, key);
    }
}


//int main()
//{
//    BST bst;
//    //Iterative insert
//    bst.Insert(55);
//    bst.Insert(6);
//    bst.Insert(99);
//    bst.Insert(4);
//    bst.Insert(39);
//
//    //Iterative search
//    Node* temp = bst.iSearch(55);
//    if (temp != nullptr)
//    {
//        cout << temp->data << endl;
//    }
//    else
//    {
//        cout << "element not found";
//    }
//
//    //Recursive Search
//    temp = bst.rSearch(bst.getRoot(), 4);
//    if (temp != nullptr)
//    {
//        cout << temp->data << endl;
//    }
//    else
//    {
//        cout << "Element not found" << endl;
//    }
//
//
//    return 0;
//}