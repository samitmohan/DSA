#include <iostream>
using namespace std;

// Basic definations -> https://www.interviewbit.com/courses/programming/topics/tree-data-structure/
// No default header file for tree in C++ but you don't have to create a tree everytime, work only on root node.

class binaryTree
{
public:
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;
        // constructor
        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
    };

private: // for security -> nobody should enter the settings of default tree
    // insert root node
    Node *root = nullptr; // initially.
    // 10, LR -> insert 10. posn -> Root node -> Left -> Right
    // insert function : root, index, value, direction
    Node *insert(Node *myNode, int idx, int value, string direction)
    {
        if (myNode == nullptr) // root node empty, create a new node
        {
            Node *baseCase = new Node(value);
            return baseCase; // return address (root node)
        }
        // if direction.len = index (insert 15, L) [index = 1, direction L, no need to create new node. myNode->value = value (override), return address)
        if (idx == direction.length())
        {
            myNode->value = value;
            return myNode;
        }
        // right direction
        if (direction[idx] == 'R')
        {
            // store in right, index++ (insert function)
            myNode->right = insert(myNode->right, idx + 1, value, direction);
        }
        else // left
        {
            // store in left, index++ (insert function)
            myNode->left = insert(myNode->left, idx + 1, value, direction);
        }
        return myNode;
    }

public: // can access insert function
    void insert(int value, string direction)
    {
        this->root = insert(root, 0, value, direction);
    }

private: // can't access settings of default display function
    void display(Node *myNode)
    {
        if (myNode == nullptr)
        {
            return; // empty
        }
        // check for left.
        if (myNode->left != nullptr)
        {
            cout << myNode->left->value << " -> ";
        }
        else
        {
            cout << " -> "; // no value of left (null)
        }
        cout << myNode->value; // root node

        // check for right.
        if (myNode->right != nullptr)
        {
            cout << " <- " << myNode->right->value;
        }
        else
        {
            cout << " <- "; // no value of right (null)
        }

        // recursively call for all nodes in the tree
        cout << endl;
        display(myNode->left);
        display(myNode->right);
    }

public:
    void display()
    {
        display(root);
    }
};

int main()
{
    binaryTree bt;
    bt.insert(15, "");
    bt.insert(28, "R");
    bt.insert(86, "L");
    bt.insert(21, "LR");
    bt.insert(80, "RR");
    bt.insert(72, "RL");
    bt.insert(5, "L"); // direction.len = index
    bt.display();
    // should look like this
    //      15
    //     /   \
    //     5     28
    //      \    / \
    //      21  72  80
    return 0;
}
