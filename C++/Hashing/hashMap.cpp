#include <iostream>
#include <vector>
using namespace std;

// Only difference -> replace int with node (key, value)
// Instead of just value, there is frequency also.
// Same as map.
// Pair -> vector<pair<key, value>> [Keep count]
// ordered -> using BST -> nlogn

class customMap
{
public:
    // create a node class containing key value pair.
    class node
    {
    public:
        int key;
        int value;
        // constructor
        node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
        node()
        {
        }
    };

    // instead of vector<int> *arr it'll be vector<node *> *arr
    vector<node *> *arr;
    int defaultSize = 10; // size of table
    int size;             // key (number of elements)
    // constructor
    customMap()
    {
        // arr = new node[defaultSize]
        arr = new vector<node *>[defaultSize];
        // fill array
        for (int i = 0; i < defaultSize; i++)
        {
            arr[i] = vector<node *>(); // every element has a vector<int>
        }
        size = 0; // by default
    }

    // hashing function

    int hashing(int data)
    {
        return data % defaultSize; // modulo method
    }

    // rehash -> when faced problem of sizing
    vector<node *> *rehash()
    {
        // new hash table size
        defaultSize = defaultSize * 2;
        vector<node *> *newArr = new vector<node *>[defaultSize];
        // fill array
        for (int i = 0; i < defaultSize; i++)
        {
            newArr[i] = vector<node *>();
        }

        // rehashing process (tricky)
        // example -> 12, 17->18, 20, , 27->31
        for (int i = 0; i < defaultSize / 2; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                // don't pass arr[i][j]
                // hashing is always of key, not value
                // find hash code. (of 12)
                int hash = hashing(arr[i][j]->key);
                // find index
                int index = hash % defaultSize;
                // defaultSize = 20 (push 12)
                // push key value pair in the final array.
                // *ONLY CHANGE B/W SET AND MAP*
                newArr[index].push_back(new node(arr[i][j]->key, arr[i][j]->value));
            }
        }
        // now -> 12, 17, 18, 20, 37, 31 -> reduces collision for large arrays
        return newArr;
    }

    // insert.
    void insert(int key, int value)
    {
        // hashcode.
        int hash = hashing(key);
        int index = hash % defaultSize;
        vector<node *> bucket = arr[index];
        // travel over this vector.
        // if vector[index] -> data already avail then don't insert in that bucket
        for (int i = 0; i < bucket.size(); i++)
        {
            // if 8 corresponds to 12
            // now 8 corresponds to 16, it'll override
            // update
            // key -> 8->12 and bucket[i]->key -> 8->16
            // instead of bucket[i] == data check for this
            if (bucket[i]->key == key)
            {
                // already filled (set has no duplicates)
                // over ride and update it to new key->val (8->16)
                bucket[i] == new node(key, value);
                arr[index] = bucket;
                return;
            }
        }
        // else -> empty space.
        // make a new node class and insert key value
        bucket.push_back(new node(key, value));
        arr[index] = bucket;
        size++; // increment size
        // load factor (0.75 -> any number)
        double loadFactor = 0.75;
        // if n/m > lf -> problem(rehash) -> m -> 2 * m
        if (size / defaultSize > loadFactor)
        {
            // new arr = reshashed.
            arr = rehash();
        }
    }

    // check if key present in hash table or not (search)
    bool contains(int key)
    {
        // same code as insert
        int hash = hashing(key);
        int index = hash % defaultSize;
        vector<node *> bucket = arr[index];
        for (int i = 0; i < bucket.size(); i++)
        {
            // instead of bucket[i] == data check for this
            if (bucket[i]->key == key)
            {
                // return true;
                return true;
            }
        }
        // else -> empty space -> return false
        return false;
    }

    // remove
    void remove(int key)
    {
        int hash = hashing(key);
        int index = hash % defaultSize;
        vector<node *> bucket = arr[index];
        for (int i = 0; i < bucket.size(); i++)
        {
            // if elem present
            // instead of bucket[i] == data check for this
            if (bucket[i]->key == key)
            {
                // erase that element (ith index from beginning)
                bucket.erase(bucket.begin() + i);
            }
        }
        arr[index] = bucket;
    }

    // display -> unordered
    void display()
    {
        for (int i = 0; i < defaultSize; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                // print key, value
                cout << arr[i][j]->key << " " << arr[i][j]->value << endl;
            }
        }
    }

    // I want value when given a key -> dictionaries in python.
    // get

    int get(int key)
    {
        int hash = hashing(key);
        int index = hash % defaultSize;
        vector<node *> bucket = arr[index];
        for (int i = 0; i < bucket.size(); i++)
        {
            // if key given present
            if (bucket[i]->key == key)
            {
                // return it's value
                return bucket[i]->value;
            }
        }
        // if not found
        return 0;
    }
};

int main()
{
    customMap cm1;
    cm1.insert(10, 12);
    cm1.insert(15, 165);
    cm1.insert(85, 87);
    cm1.insert(15, 165);
    cm1.insert(16, 165);
    cm1.insert(65, 52);
    cm1.insert(4, 2);
    cm1.insert(15, 87);
    cm1.insert(10, 18);
    cout << cm1.get(16) << endl;      // 165
    cout << cm1.contains(10) << endl; // true
    cm1.remove(15);
    cm1.display();

    return 0;
}
