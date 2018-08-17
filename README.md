This is my Algorithm and Data Structure project for the year 2017.

#1. Sorting Algorithms

Implement the following sorting algorithms:

- Insertion Sort
- Selection Sort
- Quick Sort

Each algorithm must be implemented such that it can be used on a generic type 
```T```. Algorithm implementation must permit the specification of criterium used for data sorting.

### Comparisons

File `records.csv` contains 20 millions of records to be sorted. Every record is described by 
a single line which is structured as follows:
- id: (integer type) univocally identifies a record;
- field1: (string type) contains words extracted from La Divina Commedia,
	I will assume it doesn't contain spaces nor commas.
- field2: (integer type);
- field3: (floating point type);

The file format is a standard CSV: fields are separated by commas, records are separated by a `\n`.

For every implemented algorithm, sort records inside `records.csv`file in a non-descrescent order
based on field values (so, for every algorithm, sorting must be executed three times: one for any 
field).

##2. N-ary tree implementation

N-ary Tree implementation, in which every node has a pointer to its parent, its left and right child.
Data structure must be able to manage generic types, permit to have a not previously known and arbitrary
node and child number for every node and permit the build of a tree by adding nodes.

Implement the following algorithms for the n-ary tree:
- Algorithm that returns the maximum tree node grade;
- Algorithm that verifies that the given tree is a binary tree;
- Algorithm that returns the given tree dimension (as to say the number of nodes of the tree);
- Algorithm that returns the given tree depth (as to say the length of the longest branch from the root 
	to a leaf.

- Algorithm that builds a new self-balancing binary search tree which nodes values have the same values as the input tree. Keep in mind:
  - the algorithm mst build the self-balancing BST usign the already implemented structure for the n-ary tree;
  - the algorithm must build the new tree "from scratch" and it must not modify the input tree;
  - the algorithm **must build the new self-balancing tree "on the fly"**, adding to the initially empty tree nodes in a opportune order:
	no balancing algorithms must be implemented.

Data structure and implemented algorithms must be used with given data, contained in `multywaytree_1.csv` and `multywaytree_2.csv` files.

Both `multywaytree_1.csv` and `multywaytree_2.csv` files contain a n-ary tree serialization. The format is a standard CSV: fields are 
separated by commas; records (as to say lines) are separated by `\n`. In every record, the first field represents the current node and the
fields that follow represent node childs (the first field of the first line represents the tree root), for example the following lines:

```
N:0000,N:0001,N:0002
N:0001,N:0003
```

specify that the node `N:0000` has `N:0001` and `N:0002` as childs; `N:0001` has `N:0003` as child. In other words, the following tree is codified:

```
N:0000 -- N:0001 -- N:0003
       \_ N:0002
```

##3. Max Heap implementation.

Implement an iterative and a recursive version of an algorithm that takes an array as input and verifies if it represents a Max Heap.
Array's element type is not previously known, and user can be able to specify sorting criterium.


##4. UnionFind data structure implementation

Implement the UnionFind data structure. Structure must permit to insert generic type objects and not forecast an initial
finite element set.


## Esercizio 5
Implement the direct Graph data structure so that it is optimal for sparse data.

Implement a function that returns the graph weight. Implement the Kruskal's Algorithm to find the minimum spanning tree of a graph.
The Kruskal Algorithm implementation must use the UnionFind implemented in #4.

Find the minimum spanning tree specified in file `italian_dist_graph.csv`.
The file `italian_dist_graph.csv` contains distances (expressed in meters) of some italian locations, and a town of some other nearby locations.
File format is a standard CSV: fields are separated by commas; records are separated by `\n`.

Every record contains the following data:
- location 1: (string type) name of the "source" location. String may contain spaces, but not commas.
- location 2: (string type) name of the "destination" location. String may contain spaces, but not commas.
- distanza: (float type) distance (expressed in meters) between the two locations.

*Notes:*
- informations in file lines must be represented as **non-directed edges**.
- file was created from an unaccurate dataset: data may be unexact.

### Checks

A correct implementation of the Kruskal's Algorithm on the data contained in the file `italian_dist_graph.csv`
should determine a minimum spanning tree with 18.640 nodes, 18.637 unoriented edges and a total weight of 89.939,913 Km.

