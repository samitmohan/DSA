#include <iostream>
#include <vector>
using namespace std;

// hash set -> unqiue elements
// unordered set
// ordered -> using BST -> nlogn

/*

Every number has a hashcode (int) -> n.
Any character/string can be converted to an unique integer (hashcode)

n % sizeof(arr) = modulo hashing
Similarily there is multiplication/addition/subtraction/different hashing techniques.

How to solve collision?
-> make array of linked list or array of vector
    -> take vector<vector<int>> array.

Now each block doesn't contain integer, it contains a linked list of integers or vector of integers.

Make array of vector.
Hash table should be related to the data.

Hashcode should be unique -> almost O(N)
Loadfactor -> 0.75 (assumption)
n/m -> load factor. (n = keys in hash table, m = hash table size)

n/m should be lesser than the loadfactor.
Elements added in size of 10 -> 1 (1/10 < 0.75), 17 (2/10 < 0.75), 17(3/10 < 0.75), 7 (4/10 < 0.75), 1 (5/10 < 0.75), 19 (6/10 < 0.75), 2 (7/10 < 0.75)
Now -> 3 (8/10 !< 0.75) -> Now problem faced, how to solve? pick a new hash table size -> 2 * m (double) [proof in notes]
Size from 10 -> 20 of hash map. Now running time -> better.


Running time (unordered_set) -> O(1 + loadfactor)
# 1 -> apply hash function & random access to slot.
# loadfactor -> search the list.

Wherever you see -> arr[i][j] -> bucket / linked list / vector<vector<int> arr

*/

class customSet
{
public:
    // we would normally do int *arr;
    // but we need to store a bucket to avoid collision -> hence use linked list / vector of array
    vector<int> *arr;
    int defaultSize = 10; // size of table
    int size;             // key (number of elements)
    // constructor
    customSet()
    {
        // arr = new int[defaultSize]
        arr = new vector<int>[defaultSize];
        // fill array
        for (int i = 0; i < defaultSize; i++)
        {
            arr[i] = vector<int>(); // every element has a vector<int>
        }
        size = 0; // by default
    }

    // hashing function
    int hashing(int data)
    {
        return data % defaultSize; // modulo method
    }

    // rehash -> when faced problem of sizing
    vector<int> *rehash()
    {
        // new hash table size
        defaultSize = defaultSize * 2;
        vector<int> *newArr = new vector<int>[defaultSize];
        // fill array
        for (int i = 0; i < defaultSize; i++)
        {
            newArr[i] = vector<int>();
        }

        // rehashing process (tricky)
        // example -> 12, 17->18, 20, , 27->31
        for (int i = 0; i < defaultSize / 2; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                // find hash code. (of 12)
                int hash = hashing(arr[i][j]);
                // find index
                int index = hash % defaultSize;
                // defaultSize = 20 (push 12)
                newArr[index].push_back(arr[i][j]);
            }
        }
        // now -> 12, 17, 18, 20, 37, 31 -> reduces collision for large arrays
        return newArr;
    }

    // insert.
    void insert(int data)
    {
        // hashcode.
        int hash = hashing(data);
        int index = hash % defaultSize;
        vector<int> bucket = arr[index];
        // travel over this vector.
        // if vector[index] -> data already avail then don't insert in that bucket
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i] == data)
            {
                // already filled (set has no duplicates)
                return;
            }
        }
        // else -> empty space.
        // place data
        bucket.push_back(data);
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

    // check if key present in hash table or not
    bool contains(int data)
    {
        // same code as insert
        int hash = hashing(data);
        int index = hash % defaultSize;
        vector<int> bucket = arr[index];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i] == data)
            {
                // return true;
                return true;
            }
        }
        // else -> empty space -> return false
        return false;
    }

    // remove
    void remove(int data)
    {
        int hash = hashing(data);
        int index = hash % defaultSize;
        vector<int> bucket = arr[index];
        for (int i = 0; i < bucket.size(); i++)
        {
            // if elem present
            if (bucket[i] == data)
            {
                // erase that element (ith index from beginning)
                bucket.erase(bucket.begin() + i);
            }
        }
        arr[index] = bucket;
    }

    // display
    void display()
    {
        for (int i = 0; i < defaultSize; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
};

int main()
{
    // unordered set -> gives random order not sorted.
    customSet cs1;

    // duplicates
    cs1.insert(10);
    cs1.insert(3);
    cs1.insert(4);
    // inserting elements (duplicates also)
    for (int i = 1; i <= 10; i++)
    {
        cs1.insert(i);
    }
    // should print unique elements
    cs1.display();
    cout << endl;
    cout << cs1.contains(10) << "\n"; // true (1)
    cout << cs1.contains(15) << "\n"; // false (0)
    cs1.remove(4);

    return 0;
}
