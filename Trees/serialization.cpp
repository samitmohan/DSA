// Problem link -> https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Serialization : Basically convert binary tree diagram and store numbers in a string
// Deserialization : Convert the string to binary tree diagram

// Time complexity -> O(N) preorder
// Space complexity -> O(N)

// Here, makestring(...) method constructs a string with nodes present in it in preordered manner. Also, makeTree(...) method constructs a binary tree from the vector res which stores node values in preordered manner and 0 for NULL nodes

class Codec
{
public:
    string res;
    vector<int> nums;
    int index;
    // preorder traversal
    // constructs string with nodes present in it in preorder manner
    void makestring(TreeNode *root)
    {
        // base case
        if (!root)
        {
            res.push_back('0'); // I've used 0 for nullptr
            res.push_back(','); // comma is the separator
            return;
        }
        // recursive case
        string num = to_string(root->val); // convert to string
        res.append(num);                   // add
        res.push_back(',');                // comma is the separator
        // do the same for left and right
        makestring(root->left);
        makestring(root->right);
        return;
    }

    // constructs a binary tree from vector res which stores node values in preorder manner and 0 for null
    TreeNode *makeTree()
    {
        // base case
        if (!nums[index])
        {
            index++;
            return NULL;
        }

        // recursive case
        TreeNode *node = new TreeNode(nums[index]); // decoding the value of the node
        index++;
        node->left = makeTree();
        node->right = makeTree();
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";    // base case
        makestring(root); // else
        res.pop_back();   // for the extra comma at the end
        return res;
    }
    /*
        string -> 1, 2, 13, 0, 0 , 4, 5, 0, 0, 0, 0 (serialise)

             1
            / \
           2   13
              / \
              4  5

        deserialise process :
        pick up first guy, put it in queue, at the same time make a root node
        1's left and right :
            left -> put it in queue, make node 2
            right -> 13, put it in queue, make node 13
        2's left and right -> 0 and 0, pop 2 (finished with 2)
        13's left and right  -> 4 and 5. make nodes and add in queue and so on
    */
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // special case
        if (!data.size())
            return NULL;

        // using stringstream to extract numbers from data string
        stringstream s(data); // allows strings to be iterated over like objects.
        char ch;              // select ch (1, then 2, then 13, then 4, then 5 and so on...)
        int temp;
        while (s >> temp)
        {
            nums.push_back(temp);
            s >> ch; // keep doing this till you reach end of the string
        }

        // make tree
        index = 0;
        TreeNode *root = makeTree();
        return root;
    }
};