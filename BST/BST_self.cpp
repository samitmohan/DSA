#include <bits/stdc++.h>
using namespace std;

class binarySearchTree
{
public:
    class Node
    {
    public:
        int val;
        Node *left;
        Node *right;
        Node(int val)
        {
            this->val = val;
            left = nullptr;
            right = nullptr;
        }
    };

private:
    Node *root = nullptr;
    Node *insert(Node *myNode, int value)
    {
        if (myNode == nullptr)
        {
            Node *baseCase = new Node(value); // create empty node
            return baseCase;
        }
        // else nodes exist, apply BST rule, root->val < val(curr) = right side.
        if (myNode->val <= value)
        {
            myNode->right = insert(myNode->right, value);
        }
        else
        {
            myNode->left = insert(myNode->left, value);
        }
        return myNode;
    }

    void display(Node *myNode)
    {
        // base case

        if (myNode == nullptr)
        {
            return;
        }

        // left
        if (myNode->left != nullptr)
        {
            cout << myNode->left->val << " -> ";
        }
        else
        {
            cout << " -> ";
        }
        // value
        cout << myNode->val;

        // right
        if (myNode->right != nullptr)
        {
            cout << " <- " << myNode->right->val;
        }
        else
        {
            cout << " <- ";
        }

        cout << "\n";
        display(myNode->left);
        display(myNode->right);
    }
    // search
    bool find(int data, Node *myNode)
    {
        if (myNode == nullptr)
        {
            return false;
        }
        if (myNode->val == data)
        {
            return true;
        }
        if (myNode->val < data)
        {
            return find(data, myNode->right);
        }
        else
        {
            return find(data, myNode->left);
        }
    }

public:
    void display()
    {
        display(root);
    }
    void insert(int value)
    {
        this->root = insert(root, value);
    }
    bool find(int data)
    {
        return find(data, root);
    }
};

int main()
{
    binarySearchTree bst1;
    bst1.insert(12);
    bst1.insert(16);
    bst1.insert(18);
    bst1.insert(5);
    bst1.insert(6);
    bst1.insert(9);
    bst1.insert(11);
    bst1.insert(8);
    bst1.insert(17);
    bst1.insert(4);
    bst1.display();
    cout << bst1.find(20) << "\n"; // false
    cout << bst1.find(4) << "\n"; // true
    return 0;
}
using namespace std;
