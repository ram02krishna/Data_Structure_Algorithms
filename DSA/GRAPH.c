/*
Array/Linked list and stacks are Linear Data Structures
BST and AVL Trees are Non Linear Hierachical Data structure
Graph is an example of Non linear data structure
A graph is a collection of nodes connected through edges

Graph traversal are of two types that are
1. BFS (Breadth first search) -> In this QUEUE Data structure is used.
2. DFS (Depth first search) -> In this STACK Data structure is used.
*/

/*
BFS (BREADTH FIRST SEARCH)

Method - 1 :: BFS spannning tree
Level Order traversal is the BFS traversal of the graph
Level order traversal is a method used in tree data structures, particularly binary trees, to visit each node in a tree level by level, from left to right. Here's how it works:
Start with the root node.
Visit the root node.
Visit all the nodes at the next level (children of the root node), from left to right.
Repeat this process for each level of the tree, visiting nodes from left to right at each level.
Example :
      1
     / \
    2   3
   / \ / \
  4  5 6  7
  The level order traversal of this tree would be: 1, 2, 3, 4, 5, 6, 7.

Method - 2 :: BFS Traversal
write visited and exploration queue.
*/

// Code for BFS
/*
#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};


int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));

    // BFS Implementation
    int node;
    int i = 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
*/

//  Code for DFS
#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int A[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
        };

void DFS(int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1; // jo node visit kr liya he usko 1 mark krege
    for(int j =0;j<7;j++)
    {
        if(A[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation
    // DFS(0);
    // DFS(1);
    DFS(4);
    return 0;
}