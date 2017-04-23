// Bottom-up red-black tree header file - lab 3 spring 2017
#ifndef RB_H
#define RB_H
 // RB_H
// These will have to change if data in node is more than just an int.
typedef int Key;
typedef Key Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (key(A) == key(B))

typedef struct STnode* link;

struct STnode
{
Item item;  // Data for this node
link l, r;  // left & right links
char red;   // RB color
char tombstone; // 0 = live key, 1 = dead key
int N;      // subtree size (counts only live nodes)
};

extern Item NULLitem;

void STinit();          // Initialize tree with just a sentinel

Item STsearch(Key v);   // Find node for a key

Item STselect(int k);   // Treat tree as flattened into an ordered array

int STinvSelect(Key v); // Inverse of STselect

void extendedTraceOn(); // Full tracing of intermediate trees

void basicTraceOn();    // Just trace down and up passes for insert

void traceOff();        // Run silent

void STinsert(Item item);     // Insert an item.  No uniqueness check

void STdelete(Key v);         // Delete item for a key, if present.

int verifyRBproperties();    // Ensure that tree isn't damaged

void STprintTree();           // Dumps out tree

void cleanUpUnbalanced(link h);  // Includes subtree sizes and verifies a tree
                                 // built without balancing

int getLive(int i);  // Number of nodes in tree with active keys.

int getDead(int i);  // Number of nodes in tree with tombstone set.

int getRecycled();  // Number of elements available from last removeDead()

void removeDead(int* tomb, int* alive);  // Rebuild tree and put tombstoned elements in recycling list.

#endif
