# Interviews
> Maintainer - [Samit Mohan.](https://github.com/samitmohan)

## Table of Contents
- [Online Judges](#online-judges)
- [Live Coding Practice](#live-coding-practice)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Greedy Algorithms](#greedy-algorithms)
- [Bitmasks](#bitmasks)
- [Runtime Analysis](#runtime-analysis)
- [Video Lectures](#video-lectures)
- [Interview Books](#interview-books)
- [Directory Tree](#directory-tree)

## Online Judges
* [LeetCode](https://leetcode.com/)
* [HackerRank](https://www.hackerrank.com/)
* [CodeFights](https://codefights.com/)
* [HackerEarth](https://www.hackerearth.com)
* [Code Forces](http://codeforces.com/)
* [Code Chef](https://www.codechef.com/)
* [Sphere Online Judge - SPOJ](http://www.spoj.com/)
* [InterviewBit](https://www.interviewbit.com/)

## Live Coding Practice
* [Pramp](https://www.pramp.com/ref/gt4)
* [Gainlo](http://www.gainlo.co/#!/)
* [Refdash](https://refdash.com/)
* [Interviewing.io](https://www.interviewing.io/)

## Data Structures
### Linked List
 * A *Linked List* is a linear collection of data elements, called nodes, each
   pointing to the next node by means of a pointer. It is a data structure
   consisting of a group of nodes which together represent a sequence.
 * **Singly-linked list**: linked list in which each node points to the next node and the last node points to null
 * **Doubly-linked list**: linked list in which each node has two pointers, p and n, such that p points to the previous node and n points to the next node; the last node's n pointer points to null
 * **Circular-linked list**: linked list in which each node points to the next node and the last node points back to the first node
 * Time Complexity:
   * Access: `O(n)`
   * Search: `O(n)`
   * Insert: `O(1)`
   * Remove: `O(1)`

### Stack
 * A *Stack* is a collection of elements, with two principle operations: *push*, which adds to the collection, and
   *pop*, which removes the most recently added element
 * **Last in, first out data structure (LIFO)**: the most recently added object is the first to be removed
 * Time Complexity:
   * Access: `O(n)`
   * Search: `O(n)`
   * Insert: `O(1)`
   * Remove: `O(1)`

### Queue
 * A *Queue* is a collection of elements, supporting two principle operations: *enqueue*, which inserts an element
   into the queue, and *dequeue*, which removes an element from the queue
 * **First in, first out data structure (FIFO)**: the oldest added object is the first to be removed
 * Time Complexity:
   * Access: `O(n)`
   * Search: `O(n)`
   * Insert: `O(1)`
   * Remove: `O(1)`

### Tree
 * A *Tree* is an undirected, connected, acyclic graph

### Binary Tree
 * A *Binary Tree* is a tree data structure in which each node has at most two children, which are referred to as
   the *left child* and *right child*
 * **Full Tree**: a tree in which every node has either 0 or 2 children
 * **Perfect Binary Tree**: a binary tree in which all interior nodes have two children and all leave have the same depth
 * **Complete Tree**: a binary tree in which every level *except possibly the last* is full and all nodes in the last
   level are as far left as possible

### Binary Search Tree
 * A binary search tree, sometimes called BST, is a type of binary tree which maintains the property that the value in each
   node must be greater than or equal to any value stored in the left sub-tree, and less than or equal to any value stored
   in the right sub-tree
 * Time Complexity:
   * Access: `O(log(n))`
   * Search: `O(log(n))`
   * Insert: `O(log(n))`
   * Remove: `O(log(n))`

<img src="/images/BST.png?raw=true" alt="Binary Search Tree" width="400" height="500">

### Trie
* A trie, sometimes called a radix or prefix tree, is a kind of search tree that is used to store a dynamic set or associative
  array where the keys are usually Strings. No node in the tree stores the key associated with that node; instead, its position 
  in the tree defines the key with which it is associated. All the descendants of a node have a common prefix of the String associated 
  with that node, and the root is associated with the empty String.

![Alt text](/images/trie.png?raw=true "Trie")

### Fenwick Tree
* A Fenwick tree, sometimes called a binary indexed tree, is a tree in concept, but in practice is implemented as an implicit data
  structure using an array. Given an index in the array representing a vertex, the index of a vertex's parent or child is calculated
  through bitwise operations on the binary representation of its index. Each element of the array contains the pre-calculated sum of
  a range of values, and by combining that sum with additional ranges encountered during an upward traversal to the root, the prefix
  sum is calculated
* Time Complexity:
  * Range Sum: `O(log(n))`
  * Update: `O(log(n))`

![Alt text](/images/fenwickTree.png?raw=true "Fenwick Tree")

### Segment Tree
* A Segment tree, is a tree data structure for storing intervals, or segments. It allows querying which of the stored segments contain
  a given point
* Time Complexity:
  * Range Query: `O(log(n))`
  * Update: `O(log(n))`

![Alt text](/images/segmentTree.png?raw=true "Segment Tree")

### Heap
* A *Heap* is a specialized tree based structure data structure that satisfies the *heap* property: if A is a parent node of
B, then the key (the value) of node A is ordered with respect to the key of node B with the same ordering applying across the entire heap.
A heap can be classified further as either a "max heap" or a "min heap". In a max heap, the keys of parent nodes are always greater
than or equal to those of the children and the highest key is in the root node. In a min heap, the keys of parent nodes are less than
or equal to those of the children and the lowest key is in the root node
* Time Complexity:
  * Access Max / Min: `O(1)`
  * Insert: `O(log(n))`
  * Remove Max / Min: `O(log(n))`

<img src="/images/heap.png?raw=true" alt="Max Heap" width="400" height="500">


### Hashing
* *Hashing* is used to map data of an arbitrary size to data of a fixed size. The values returned by a hash
  function are called hash values, hash codes, or simply hashes. If two keys map to the same value, a collision occurs
* **Hash Map**: a *hash map* is a structure that can map keys to values. A hash map uses a hash function to compute
  an index into an array of buckets or slots, from which the desired value can be found.
* Collision Resolution
 * **Separate Chaining**: in *separate chaining*, each bucket is independent, and contains a list of entries for each index. The
 time for hash map operations is the time to find the bucket (constant time), plus the time to iterate through the list
 * **Open Addressing**: in *open addressing*, when a new entry is inserted, the buckets are examined, starting with the
 hashed-to-slot and proceeding in some sequence, until an unoccupied slot is found. The name open addressing refers to
 the fact that the location of an item is not always determined by its hash value


![Alt text](/images/hash.png?raw=true "Hashing")

### Graph
* A *Graph* is an ordered pair of G = (V, E) comprising a set V of vertices or nodes together with a set E of edges or arcs,
  which are 2-element subsets of V (i.e. an edge is associated with two vertices, and that association takes the form of the
  unordered pair comprising those two vertices)
 * **Undirected Graph**: a graph in which the adjacency relation is symmetric. So if there exists an edge from node u to node
 v (u -> v), then it is also the case that there exists an edge from node v to node u (v -> u)
 * **Directed Graph**: a graph in which the adjacency relation is not symmetric. So if there exists an edge from node u to node v
 (u -> v), this does *not* imply that there exists an edge from node v to node u (v -> u)


<img src="/images/graph.png?raw=true" alt="Graph" width="400" height="500">

## Algorithms

### Sorting

#### Quicksort
* Stable: `No`
* Time Complexity:
  * Best Case: `O(nlog(n))`
  * Worst Case: `O(n^2)`
  * Average Case: `O(nlog(n))`

![Alt text](/images/quicksort.gif?raw=true "Quicksort")

#### Mergesort
* *Mergesort* is also a divide and conquer algorithm. It continuously divides an array into two halves, recurses on both the
  left subarray and right subarray and then merges the two sorted halves
* Stable: `Yes`
* Time Complexity:
  * Best Case: `O(nlog(n))`
  * Worst Case: `O(nlog(n))`
  * Average Case: `O(nlog(n))`

![Alt text](/images/mergesort.gif?raw=true "Mergesort")

#### Bucket Sort
* *Bucket Sort* is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Each bucket
  is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm
* Time Complexity:
  * Best Case: `Ω(n + k)`
  * Worst Case: `O(n^2)`
  * Average Case:`Θ(n + k)`

![Alt text](/images/bucketsort.png?raw=true "Bucket Sort")

#### Radix Sort
* *Radix Sort* is a sorting algorithm that like bucket sort, distributes elements of an array into a number of buckets. However, radix
  sort differs from bucket sort by 're-bucketing' the array after the initial pass as opposed to sorting each bucket and merging
* Time Complexity:
  * Best Case: `Ω(nk)`
  * Worst Case: `O(nk)`
  * Average Case: `Θ(nk)`

### Graph Algorithms

#### Depth First Search
* *Depth First Search* is a graph traversal algorithm which explores as far as possible along each branch before backtracking
* Time Complexity: `O(|V| + |E|)`

![Alt text](/images/dfsbfs.gif?raw=true "DFS / BFS Traversal")

#### Breadth First Search
* *Breadth First Search* is a graph traversal algorithm which explores the neighbor nodes first, before moving to the next
  level neighbors
* Time Complexity: `O(|V| + |E|)`

![Alt text](/images/dfsbfs.gif?raw=true "DFS / BFS Traversal")

#### Topological Sort
* *Topological Sort* is the linear ordering of a directed graph's nodes such that for every edge from node u to node v, u
  comes before v in the ordering
* Time Complexity: `O(|V| + |E|)`

#### Dijkstra's Algorithm
* *Dijkstra's Algorithm* is an algorithm for finding the shortest path between nodes in a graph
* Time Complexity: `O(|V|^2)`

![Alt text](/images/dijkstra.gif?raw=true "Dijkstra's")

#### Bellman-Ford Algorithm
* *Bellman-Ford Algorithm* is an algorithm that computes the shortest paths from a single source node to all other nodes in a weighted graph
* Although it is slower than Dijkstra's, it is more versatile, as it is capable of handling graphs in which some of the edge weights are
  negative numbers
* Time Complexity:
  * Best Case: `O(|E|)`
  * Worst Case: `O(|V||E|)`

![Alt text](/images/bellman-ford.gif?raw=true "Bellman-Ford")

#### Floyd-Warshall Algorithm
* *Floyd-Warshall Algorithm* is an algorithm for finding the shortest paths in a weighted graph with positive or negative edge weights, but
  no negative cycles
* A single execution of the algorithm will find the lengths (summed weights) of the shortest paths between *all* pairs of nodes
* Time Complexity:
  * Best Case: `O(|V|^3)`
  * Worst Case: `O(|V|^3)`
  * Average Case: `O(|V|^3)`

#### Prim's Algorithm
* *Prim's Algorithm* is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. In other words, Prim's find a
  subset of edges that forms a tree that includes every node in the graph
* Time Complexity: `O(|V|^2)`

![Alt text](/images/prim.gif?raw=true "Prim's Algorithm")

#### Kruskal's Algorithm
* *Kruskal's Algorithm* is also a greedy algorithm that finds a minimum spanning tree in a graph. However, in Kruskal's, the graph does not
  have to be connected
* Time Complexity: `O(|E|log|V|)`

![Alt text](/images/kruskal.gif?raw=true "Kruskal's Algorithm")

## Greedy Algorithms
* *Greedy Algorithms* are algorithms that make locally optimal choices at each step in the hope of eventually reaching the globally optimal solution
* Problems must exhibit two properties in order to implement a Greedy solution:
 * Optimal Substructure
    * An optimal solution to the problem contains optimal solutions to the given problem's subproblems
 * The Greedy Property
    * An optimal solution is reached by "greedily" choosing the locally optimal choice without ever reconsidering previous choices
* Example - Coin Change
    * Given a target amount V cents and a list of denominations of n coins, i.e. we have coinValue[i] (in cents) for coin types i from [0...n - 1],
      what is the minimum number of coins that we must use to represent amount V? Assume that we have an unlimited supply of coins of any type
    * Coins - Penny (1 cent), Nickel (5 cents), Dime (10 cents), Quarter (25 cents)
    * Assume V = 41. We can use the Greedy algorithm of continuously selecting the largest coin denomination less than or equal to V, subtract that
      coin's value from V, and repeat.
    * V = 41 | 0 coins used
    * V = 16 | 1 coin used (41 - 25 = 16)
    * V = 6  | 2 coins used (16 - 10 = 6)
    * V = 1  | 3 coins used (6 - 5 = 1)
    * V = 0  | 4 coins used (1 - 1 = 0)
    * Using this algorithm, we arrive at a total of 4 coins which is optimal

## Bitmasks
* Bitmasking is a technique used to perform operations at the bit level. Leveraging bitmasks often leads to faster runtime complexity and
  helps limit memory usage
* Test kth bit: `s & (1 << k);`
* Set kth bit: `s |= (1 << k);`
* Turn off kth bit: `s &= ~(1 << k);`
* Toggle kth bit: `s ^= (1 << k);`
* Multiple by 2<sup>n</sup>: `s << n;`
* Divide by 2<sup>n</sup>: `s >> n;`
* Intersection: `s & t;`
* Union: `s | t;`
* Set Subtraction: `s & ~t;`
* Extract lowest set bit: `s & (-s);`
* Extract lowest unset bit: `~s & (s + 1);`
* Swap Values:
             ```
                x ^= y;
                y ^= x;
                x ^= y;
             ```

## Runtime Analysis

#### Big O Notation
* *Big O Notation* is used to describe the upper bound of a particular algorithm. Big O is used to describe worst case scenarios

![Alt text](/images/bigO.png?raw=true "Theta Notation")

#### Little O Notation
* *Little O Notation* is also used to describe an upper bound of a particular algorithm; however, Little O provides a bound
  that is not asymptotically tight

#### Big Ω Omega Notation
* *Big Omega Notation* is used to provide an asymptotic lower bound on a particular algorithm

![Alt text](/images/bigOmega.png?raw=true "Theta Notation")

#### Little ω Omega Notation
* *Little Omega Notation* is used to provide a lower bound on a particular algorithm that is not asymptotically tight

#### Theta Θ Notation
* *Theta Notation* is used to provide a bound on a particular algorithm such that it can be "sandwiched" between
  two constants (one for an upper limit and one for a lower limit) for sufficiently large values

![Alt text](/images/theta.png?raw=true "Theta Notation")

## Video Lectures
* Data Structures
    * [UC Berkeley Data Structures](https://archive.org/details/ucberkeley-webcast?&and[]=subject%3A%22Computer%20Science%22&and[]=subject%3A%22CS%22)
    * [MIT Advanced Data Structures](https://www.youtube.com/watch?v=T0yzrZL1py0&list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf&index=1)
* Algorithms
    * [MIT Introduction to Algorithms](https://www.youtube.com/watch?v=HtSuA80QTyo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=1)
    * [MIT Advanced Algorithms](https://www.youtube.com/playlist?list=PL6ogFv-ieghdoGKGg2Bik3Gl1glBTEu8c)
    * [UC Berkeley Algorithms](https://archive.org/details/ucberkeley-webcast?&and[]=subject%3A%22Computer%20Science%22&and[]=subject%3A%22CS%22)

## Interview Books
* [Cracking The Coding Interview - Gayle Laakmann McDowell](https://www.amazon.com/Cracking-Coding-Interview-Programming-Questions/dp/0984782850/ref=sr_1_1?s=books&ie=UTF8)
* [Introduction to Algorithms -  Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest & Clifford Stein](https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844/ref=sr_1_1?ie=UTF8&qid=1490295989&sr=8-1&keywords=Introduction+to+Algorithms)

## Directory Tree

```
- __library__
   - __Array__
     - [2DArray.cpp](Array/2DArray.cpp)
     - [2sum.cpp](Array/2sum.cpp)
     - [3sum.cpp](Array/3sum.cpp)
     - [3sumMultiplicity](Array/3sumMultiplicity)
     - [3sumMultiplicity.cpp](Array/3sumMultiplicity.cpp)
     - [ants.cpp](Array/ants.cpp)
     - [array\_vectorIntro.cpp](Array/array_vectorIntro.cpp)
     - [buy\_and\_sell\_stock.cpp](Array/buy_and_sell_stock.cpp)
     - [buy\_and\_sell\_stock\_2.0.cpp](Array/buy_and_sell_stock_2.0.cpp)
     - [container\_most\_water.cpp](Array/container_most_water.cpp)
     - [exitPoint.cpp](Array/exitPoint.cpp)
     - [firstUniqueChar.cpp](Array/firstUniqueChar.cpp)
     - [good\_pairs\_intro\_vectors.cpp](Array/good_pairs_intro_vectors.cpp)
     - [kadane.cpp](Array/kadane.cpp)
     - [kidsWithCandies.cpp](Array/kidsWithCandies.cpp)
     - [majority\_element.cpp](Array/majority_element.cpp)
     - [mountain.cpp](Array/mountain.cpp)
     - [pivotWithTarget.cpp](Array/pivotWithTarget.cpp)
     - [pivotWithoutTarget.cpp](Array/pivotWithoutTarget.cpp)
     - [prefix\_sum.cpp](Array/prefix_sum.cpp)
     - [productofArray.cpp](Array/productofArray.cpp)
     - [removeDuplicatesSorted.cpp](Array/removeDuplicatesSorted.cpp)
     - [reverse\_array.cpp](Array/reverse_array.cpp)
     - [rotateImage.cpp](Array/rotateImage.cpp)
     - [rotatebyK.cpp](Array/rotatebyK.cpp)
     - [rotatingArray.cpp](Array/rotatingArray.cpp)
     - [shiftGrid.cpp](Array/shiftGrid.cpp)
     - [spiralMatrix.cpp](Array/spiralMatrix.cpp)
     - [sub\_array\_odd\_sum.cpp](Array/sub_array_odd_sum.cpp)
     - [subarraySort.cpp](Array/subarraySort.cpp)
     - [subarraySum.cpp](Array/subarraySum.cpp)
     - [subarraySum\_optimised.cpp](Array/subarraySum_optimised.cpp)
     - [subset\_question.jpg](Array/subset_question.jpg)
     - [sum\_odd\_subarray.cpp](Array/sum_odd_subarray.cpp)
     - [target\_array.cpp](Array/target_array.cpp)
     - [trappingRainWater.cpp](Array/trappingRainWater.cpp)
     - [twosumLC.cpp](Array/twosumLC.cpp)
   - __Basics__
     - [basic\_c++.cpp](Basics/basic_c%2B%2B.cpp)
     - __basics__
       - __basic concepts__
         - [Operators.png](Basics/basics/basic concepts/Operators.png)
         - [Variables.png](Basics/basics/basic concepts/Variables.png)
         - [basics.png](Basics/basics/basic concepts/basics.png)
         - [keywords.png](Basics/basics/basic concepts/keywords.png)
         - [statements\_expressions.png](Basics/basics/basic concepts/statements_expressions.png)
       - [boolean.png](Basics/basics/boolean.png)
       - [char.png](Basics/basics/char.png)
       - [float.png](Basics/basics/float.png)
       - [int\_char.png](Basics/basics/int_char.png)
       - [long long int.png](Basics/basics/long%20long%20int.png)
       - [short.png](Basics/basics/short.png)
       - [type\_casting.png](Basics/basics/type_casting.png)
     - [main.cpp](Basics/main.cpp)
     - [typeof.cpp](Basics/typeof.cpp)
   - __Bit Manipulation__
     - [Bitwise.pdf](Bit Manipulation/Bitwise.pdf)
     - [bit\_basics.cpp](Bit Manipulation/bit_basics.cpp)
     - [identify\_2\_nonDuplicates.cpp](Bit Manipulation/identify_2_nonDuplicates.cpp)
     - [identify\_nonDuplicate.cpp](Bit Manipulation/identify_nonDuplicate.cpp)
     - [magicNumber.cpp](Bit Manipulation/magicNumber.cpp)
     - [masking.cpp](Bit Manipulation/masking.cpp)
     - [nonRepeatingElement.cpp](Bit Manipulation/nonRepeatingElement.cpp)
   - __CTCI__
   - __DP__
   - __Graphs__
   - __Hashing__
     - [APcheck.cpp](Hashing/APcheck.cpp)
     - [a.out](Hashing/a.out)
     - [consistentStrings.cpp](Hashing/consistentStrings.cpp)
     - [doubledPairs.cpp](Hashing/doubledPairs.cpp)
     - [hashMap.cpp](Hashing/hashMap.cpp)
     - [hashSet.cpp](Hashing/hashSet.cpp)
     - [hashingC++.cpp](Hashing/hashingC%2B%2B.cpp)
     - [hashingI.pdf](Hashing/hashingI.pdf)
     - [hashingII.pdf](Hashing/hashingII.pdf)
     - [hashingIII.pdf](Hashing/hashingIII.pdf)
     - [repeatedNTimes.cpp](Hashing/repeatedNTimes.cpp)
     - [topKFrequent.cpp](Hashing/topKFrequent.cpp)
     - [uniqueNumberofOccurences.cpp](Hashing/uniqueNumberofOccurences.cpp)
     - [validAnagram.cpp](Hashing/validAnagram.cpp)
   - __Heaps__
     - [kthLargestinStream.cpp](Heaps/kthLargestinStream.cpp)
   - __Linked List__
     - [Design\_LC\_qn.cpp](Linked List/Design_LC_qn.cpp)
     - [addFirst.cpp](Linked List/addFirst.cpp)
     - [addLast.cpp](Linked List/addLast.cpp)
     - [basic\_LL.cpp](Linked List/basic_LL.cpp)
     - [customLinkedList.cpp](Linked List/customLinkedList.cpp)
     - [cycle\_I](Linked List/cycle_I)
     - [cycle\_I.cpp](Linked List/cycle_I.cpp)
     - [cycle\_II.cpp](Linked List/cycle_II.cpp)
     - [display.cpp](Linked List/display.cpp)
     - [intersection\_list.cpp](Linked List/intersection_list.cpp)
     - [merge\_list.cpp](Linked List/merge_list.cpp)
     - [middle\_node.cpp](Linked List/middle_node.cpp)
     - [palindrome.cpp](Linked List/palindrome.cpp)
     - [palindrome\_LC\_qn.cpp](Linked List/palindrome_LC_qn.cpp)
     - [removeDuplicatesLL.cpp](Linked List/removeDuplicatesLL.cpp)
     - [removeFirst.cpp](Linked List/removeFirst.cpp)
     - [removeLast.cpp](Linked List/removeLast.cpp)
     - [reverse\_LL.cpp](Linked List/reverse_LL.cpp)
     - [swap\_list.cpp](Linked List/swap_list.cpp)
   - __Mathematics__
     - [Mathematics.pdf](Mathematics/Mathematics.pdf)
     - [a.out](Mathematics/a.out)
     - [addBinary.cpp](Mathematics/addBinary.cpp)
     - [baseconverion.cpp](Mathematics/baseconverion.cpp)
     - [complexity.png](Mathematics/complexity.png)
     - [decimal\_roman.cpp](Mathematics/decimal_roman.cpp)
     - [evenoddjump.cpp](Mathematics/evenoddjump.cpp)
     - [inverse.cpp](Mathematics/inverse.cpp)
     - [leetcode\_reverse.cpp](Mathematics/leetcode_reverse.cpp)
     - [math.txt](Mathematics/math.txt)
     - [missingNumber.cpp](Mathematics/missingNumber.cpp)
     - [newtonsquareroot.cpp](Mathematics/newtonsquareroot.cpp)
     - [numbertheory.cpp](Mathematics/numbertheory.cpp)
     - [patterns.cpp](Mathematics/patterns.cpp)
     - [reverse.cpp](Mathematics/reverse.cpp)
     - [stringtointeger.cpp](Mathematics/stringtointeger.cpp)
     - [swapWithArithmetic.cpp](Mathematics/swapWithArithmetic.cpp)
   - [Notes.txt](Notes.txt)
   - __OOPs__
     - [OOPS\_1.pdf](OOPs/OOPS_1.pdf)
     - [OOPS\_2.pdf](OOPs/OOPS_2.pdf)
     - [OOPS\_3.pdf](OOPs/OOPS_3.pdf)
     - [OOPS\_4.pdf](OOPs/OOPS_4.pdf)
     - [abstraction.md](OOPs/abstraction.md)
     - [constructor.md](OOPs/constructor.md)
     - [incapsulation.cpp](OOPs/incapsulation.cpp)
     - [inheritance\_polymorphism.cpp](OOPs/inheritance_polymorphism.cpp)
     - [oops\_basics.cpp](OOPs/oops_basics.cpp)
   - [OSSpecifics.pdf](OSSpecifics.pdf)
   - __Pointers__
     - [array\_pointers.cpp](Pointers/array_pointers.cpp)
     - [basics.cpp](Pointers/basics.cpp)
     - [pointer2pointer.cpp](Pointers/pointer2pointer.cpp)
     - [pointers\_notes.cpp](Pointers/pointers_notes.cpp)
     - [ptr.cpp](Pointers/ptr.cpp)
     - [ptrs.pdf](Pointers/ptrs.pdf)
     - [sizeOfPointers.cpp](Pointers/sizeOfPointers.cpp)
     - [strcpy.c](Pointers/strcpy.c)
   - [README.md](README.md)
   - __Recursion__
     - __Backtracking__
       - [backtracking1.png](Recursion/Backtracking/backtracking1.png)
       - [backtracking2.png](Recursion/Backtracking/backtracking2.png)
       - [backtracking3.png](Recursion/Backtracking/backtracking3.png)
       - [backtracking4.png](Recursion/Backtracking/backtracking4.png)
       - [backtracking5.png](Recursion/Backtracking/backtracking5.png)
     - [KKnights.cpp](Recursion/KKnights.cpp)
     - [NQueens.cpp](Recursion/NQueens.cpp)
     - [bin\_conversion\_recursive.cpp](Recursion/bin_conversion_recursive.cpp)
     - [combination\_repetition.cpp](Recursion/combination_repetition.cpp)
     - [combination\_without\_repetition.cpp](Recursion/combination_without_repetition.cpp)
     - [diceCombination.cpp](Recursion/diceCombination.cpp)
     - [josephus.cpp](Recursion/josephus.cpp)
     - [mergesort.cpp](Recursion/mergesort.cpp)
     - [nokia\_keyboard.cpp](Recursion/nokia_keyboard.cpp)
     - [numberOf\_steps.cpp](Recursion/numberOf_steps.cpp)
     - [palindrome\_recursive.cpp](Recursion/palindrome_recursive.cpp)
     - [permutationI.cpp](Recursion/permutationI.cpp)
     - [permutationII.cpp](Recursion/permutationII.cpp)
     - [permutation\_repetition.cpp](Recursion/permutation_repetition.cpp)
     - [permutation\_without\_repetition.cpp](Recursion/permutation_without_repetition.cpp)
     - [quicksort.cpp](Recursion/quicksort.cpp)
     - [ratInAMaze.cpp](Recursion/ratInAMaze.cpp)
     - [ratInAMazeII.cpp](Recursion/ratInAMazeII.cpp)
     - [recur\_part1.cpp](Recursion/recur_part1.cpp)
     - [recursionIntro.cpp](Recursion/recursionIntro.cpp)
     - [staircase.cpp](Recursion/staircase.cpp)
     - [subsetII.cpp](Recursion/subsetII.cpp)
     - [subsetsI.cpp](Recursion/subsetsI.cpp)
     - [sudokusolver.cpp](Recursion/sudokusolver.cpp)
     - [towers\_of\_hanoi.cpp](Recursion/towers_of_hanoi.cpp)
   - __STL__
     - [stl.cpp](STL/stl.cpp)
     - [stl\_striver.cpp](STL/stl_striver.cpp)
   - __Searching__
     - [angryBird.cpp](Searching/angryBird.cpp)
     - [binarySearch\_2d.cpp](Searching/binarySearch_2d.cpp)
     - [binarySearch\_questions.cpp](Searching/binarySearch_questions.cpp)
     - [linearSearch\_questions.cpp](Searching/linearSearch_questions.cpp)
     - [searching\_basic.cpp](Searching/searching_basic.cpp)
     - [squareroot.cpp](Searching/squareroot.cpp)
   - __Sliding Window__
     - [anagrams.cpp](Sliding Window/anagrams.cpp)
     - [firstNegativeNumber\_SizeK.cpp](Sliding Window/firstNegativeNumber_SizeK.cpp)
     - [longestSubstringWithoutRepeat.cpp](Sliding Window/longestSubstringWithoutRepeat.cpp)
     - [maxSubArray\_SizeK.cpp](Sliding Window/maxSubArray_SizeK.cpp)
     - [slidingWindowMax.cpp](Sliding Window/slidingWindowMax.cpp)
     - [subArraysum.cpp](Sliding Window/subArraysum.cpp)
   - __Sorting__
     - [a.out](Sorting/a.out)
     - [duplicateNumber.cpp](Sorting/duplicateNumber.cpp)
     - [findAllDuplicates.cpp](Sorting/findAllDuplicates.cpp)
     - [findAllMissing.cpp](Sorting/findAllMissing.cpp)
     - [findMissingPositive.cpp](Sorting/findMissingPositive.cpp)
     - [missingNumber.cpp](Sorting/missingNumber.cpp)
     - [sort.cpp](Sorting/sort.cpp)
     - [stringsort.cpp](Sorting/stringsort.cpp)
   - __Stack & Queues__
     - [asteroidCollision.cpp](Stack & Queues/asteroidCollision.cpp)
     - [customQueue.cpp](Stack & Queues/customQueue.cpp)
     - [customStack.cpp](Stack & Queues/customStack.cpp)
     - [customTemplate\_stack.cpp](Stack & Queues/customTemplate_stack.cpp)
     - [historgram.cpp](Stack & Queues/historgram.cpp)
     - [lastStoneWeight](Stack & Queues/lastStoneWeight)
     - [lastStoneWeight.cpp](Stack & Queues/lastStoneWeight.cpp)
     - [nextGreaterElement.cpp](Stack & Queues/nextGreaterElement.cpp)
     - [nextSmallerElement.cpp](Stack & Queues/nextSmallerElement.cpp)
     - [palindromeStack.cpp](Stack & Queues/palindromeStack.cpp)
     - [previousGreaterElement.cpp](Stack & Queues/previousGreaterElement.cpp)
     - [previousSmallerElement.cpp](Stack & Queues/previousSmallerElement.cpp)
     - [queueSTL.cpp](Stack & Queues/queueSTL.cpp)
     - [queue\_question.cpp](Stack & Queues/queue_question.cpp)
     - [removeDuplicates.cpp](Stack & Queues/removeDuplicates.cpp)
     - [scoreOfParentheses.cpp](Stack & Queues/scoreOfParentheses.cpp)
     - [stackSTL.cpp](Stack & Queues/stackSTL.cpp)
     - [validParentheses.cpp](Stack & Queues/validParentheses.cpp)
   - __String__
     - [fizzBuzz.cpp](String/fizzBuzz.cpp)
     - [reverseOnlyLetter.cpp](String/reverseOnlyLetter.cpp)
     - [reverseString.cpp](String/reverseString.cpp)
     - [string.cpp](String/string.cpp)
     - [stringBalance.cpp](String/stringBalance.cpp)
     - [upper\_lower.cpp](String/upper_lower.cpp)
   - __Trees__
     - [BTFromPreorder\_Inorder.cpp](Trees/BTFromPreorder_Inorder.cpp)
     - [LCA.cpp](Trees/LCA.cpp)
     - [balancedBT.cpp](Trees/balancedBT.cpp)
     - [binary\_tree\_self.cpp](Trees/binary_tree_self.cpp)
     - [dimaterBT.cpp](Trees/dimaterBT.cpp)
     - [hasPathSum.cpp](Trees/hasPathSum.cpp)
     - [identicalTree.cpp](Trees/identicalTree.cpp)
     - [inorder.cpp](Trees/inorder.cpp)
     - [invertBinaryTree.cpp](Trees/invertBinaryTree.cpp)
     - [levelorder.cpp](Trees/levelorder.cpp)
     - [maxheight.cpp](Trees/maxheight.cpp)
     - [maximumPathSum.cpp](Trees/maximumPathSum.cpp)
     - [minheight.cpp](Trees/minheight.cpp)
     - [pathSumII.cpp](Trees/pathSumII.cpp)
     - [postorder.cpp](Trees/postorder.cpp)
     - [preorder.cpp](Trees/preorder.cpp)
     - [right:leftview.cpp](Trees/right%3Aleftview.cpp)
     - [rootToNodePath.cpp](Trees/rootToNodePath.cpp)
     - [symmetric.cpp](Trees/symmetric.cpp)
     - [topview.cpp](Trees/topview.cpp)
     - [trimBT.cpp](Trees/trimBT.cpp)
     - [verticaltraversal.cpp](Trees/verticaltraversal.cpp)
   - __practice__
     - [a.cpp](practice/a.cpp)
   - [problem\_solving.md](problem_solving.md)
   - [template.cpp](template.cpp)
   - __theorytopics__
     - __Computer Networks__
       - [data\_communication\_computer\_network\_tutorial.pdf](theorytopics/Computer Networks/data_communication_computer_network_tutorial.pdf)
     - __DBMS__
       - [dbms.md](theorytopics/DBMS/dbms.md)
       - [dbms\_tutorial.pdf](theorytopics/DBMS/dbms_tutorial.pdf)
     - __OOPS__
       - [Scan 2 Aug 2020.pdf](theorytopics/OOPS/Scan%202%20Aug%202020.pdf)
       - [cpp\_tutorial (1).pdf](theorytopics/OOPS/cpp_tutorial%20(1).pdf)
     - __OS__
       - [os ninjas.pdf](theorytopics/OS/os%20ninjas.pdf)
     - [theory\_questions.jpg](theorytopics/theory_questions.jpg)

```
