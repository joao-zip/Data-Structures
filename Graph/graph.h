#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int data;
}Data;

typedef struct q_node {
    int data;
    struct q_node *next;
}QData;

typedef struct s_node {
    unsigned int vertex;
    struct s_node *next;
}Stack;

typedef struct {
    QData* first,
         * last;
}Queue;

// Adjacency List
typedef struct {
    unsigned int vertex,
                 edges;
    Data** adj;
}Graph;

// Functions

Graph* graph_create(unsigned int, unsigned int);
void graph_add(Graph*, unsigned int, unsigned int);
void graph_remove(Graph*, unsigned int, unsigned int);
void graph_delete(Graph*);

// Searching Algorithms

void bfs(Graph*, unsigned int);
void dfs_iter(Graph*, unsigned int);
void dfs_recursive(Graph*, unsigned int);
void dfs_rec_aux(Graph *, unsigned int, unsigned int*);

// Internals

Data** graph_create_matrix(unsigned int);
Data** graph_delete_matrix(Data**, unsigned int);
unsigned int* graph_vertex_neighbours(Graph*, unsigned int);


// Internal Queue

Queue* q_create();
Queue* q_insert(Queue*, unsigned int);
Queue* q_remove(Queue*, unsigned int*);
Queue* q_delete(Queue*);

// Internal Stack

Stack* s_create();
Stack* s_push(Stack*, unsigned int);
Stack* s_pop(Stack*, unsigned int*);
Stack* s_delete(Stack*);

#endif
