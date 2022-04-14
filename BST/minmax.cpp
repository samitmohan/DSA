Node *minVal(Node root)
{
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp; // min
}

Node *maxVal(Node root)
{
    Node *temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp; // max
}

// cout << minVal(root)->data << maxVal(root)->data
