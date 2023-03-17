#include <bits/stdc++.h>
using namespace std;

// Complexity of insertion/searching : O(logN) (perfect BST), generally speaking -> O(height)
// Inorder (L N R) of BST is sorted. (observation)
// Complxity of deleteion :

class binarySearchTree
{
public:
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;
        Node(int val)
        {
            this->value = val;
            left = nullptr;
            right = nullptr;
        }
    };

private:
    Node *root = nullptr; // initially
    Node *insert(Node *myNode, int value)
    {
        if (myNode == nullptr)
        {
            Node *baseCase = new Node(value); // create empty node
            return baseCase;
        }
        // else nodes exist, apply BST rule, root->val < val(curr) = right side.
        if (myNode->value <= value)
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
            cout << myNode->left->value << " -> ";
        }
        else
        {
            cout << " -> ";
        }
        // value
        cout << myNode->value;

        // right
        if (myNode->right != nullptr)
        {
            cout << " <- " << myNode->right->value;
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
    bool find(int target, Node *myNode)
    {
        if (myNode == nullptr)
        {
            return false;
        }
        if (myNode->value == target)
        {
            return true;
        }
        if (myNode->value < target)
        {
            return find(target, myNode->right);
        }
        else
        {
            return find(target, myNode->left);
        }
    }

    Node *minVal(Node *myNode)
    {
        Node *temp = myNode;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp; // min
    }

    Node *maxVal(Node *myNode)
    {
        Node *temp = myNode; // myNode = root
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp; // max
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
    bool find(int target)
    {
        return find(target, root);
    }

    void min()
    {
        minVal(root);
    }

    void max()
    {
        maxVal(root);
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
    cout << bst1.find(4) << "\n";  // true
    return 0;
}
