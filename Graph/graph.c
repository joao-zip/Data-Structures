#include "graph.h"
#include <stdio.h>

// Function implementations

Graph* graph_create(unsigned int vertex, unsigned int edges) {
    Graph* new = (Graph*)malloc(sizeof(Graph));
    new->vertex = vertex;
    new->edges = edges;
    new->adj = graph_create_matrix(new->vertex);

    return new;   
}

void graph_add(Graph* g, unsigned int vertex_1, unsigned int vertex_2){
    g->adj[vertex_1][vertex_2].data = 1;
    g->adj[vertex_2][vertex_1].data = 1;
}

void graph_remove(Graph *g, unsigned int vertex_1, unsigned int vertex_2) {
    g->adj[vertex_1][vertex_2].data = 0;
    g->adj[vertex_2][vertex_1].data = 0;
}

void graph_delete(Graph *g) {
    g->adj = graph_delete_matrix(g->adj, g->vertex);
    free(g);
}

// Searching Algorithms

void bfs(Graph *g, unsigned int initial_vertex) {
    
    unsigned int vertex, *neighbours;
    unsigned int marked[g->vertex];

    for(int i = 0; i < g->vertex; i++)
        marked[i] = 0;

    Queue* q = q_create();
    q_insert(q, initial_vertex);
    
    while(q->first != NULL) { // (q->first == NULL) == Empty Queue
        q_remove(q, &vertex);
        if(marked[vertex] == 0) {
            printf("%d ", vertex);
            marked[vertex] = 1;
            neighbours = graph_vertex_neighbours(g, vertex);
            for(int i = 0; i < g->vertex; i++) {
                if(neighbours[i] == 1 && marked[i] == 0)
                    q_insert(q, i);
            }
        }
    }

    putchar('\n');

    free(neighbours);
    q = q_delete(q);
}

void dfs_iter(Graph *g, unsigned int initial_vertex) {

    unsigned int vertex, *neighbours;
    unsigned int marked[g->vertex];
    for(int i = 0; i < g->vertex; i++)
        marked[i] = 0;

    Stack* s = s_create();
    s = s_push(s, initial_vertex);

    while(s != NULL) { // Stack not empty
        s = s_pop(s, &vertex);
        if(marked[vertex] == 0) {
            printf("%d ", vertex);
            marked[vertex] = 1;
            neighbours = graph_vertex_neighbours(g, vertex);
            for(int i = 0; i < g->vertex; i++)
                if(neighbours[i] == 1 && marked[i] == 0)
                    s = s_push(s, i);
        }
    }
    
    putchar('\n');

    free(neighbours);
    s = s_delete(s);
}

void dfs_recursive(Graph *g, unsigned int initial_vertex) {
    unsigned int* marked = (unsigned int*)malloc(g->vertex * sizeof(int));
    for(int i = 0; i < g->vertex; i++)
        marked[i] = 0;
    
    dfs_rec_aux(g, initial_vertex, marked);

    putchar('\n');

    free(marked);
}

void dfs_rec_aux(Graph *g, unsigned int vertex, unsigned int* marked)  {
    unsigned int *neighbours = graph_vertex_neighbours(g, vertex);

    printf("%d ", vertex);
    marked[vertex] = 1;
    for(int i = 0; i < g->vertex; i++)
        if(neighbours[i] == 1 && marked[i] == 0)
            dfs_rec_aux(g, i, marked);

}

// Internals

Data** graph_create_matrix(unsigned int vertex) {
    Data** matrix = (Data**)malloc(vertex * sizeof(Data*));

    for(int i = 0; i < vertex; i++) {
        matrix[i] = (Data*)malloc(vertex * sizeof(Data));
        for(int j = 0; j < vertex; j++)
            matrix[i][j].data = 0;
    }

    return matrix;
}

Data** graph_delete_matrix(Data** matrix, unsigned int size) {
    for(int i = 0; i < size; i++)
        free(matrix[i]);
    
    free(matrix);

    return NULL;
}

unsigned int* graph_vertex_neighbours(Graph* g, unsigned int vertex) {
    unsigned int *neighbours = (unsigned int*)malloc(g->vertex * sizeof(unsigned int));

    for(int i = 0; i < g->vertex; i++) {
        if(g->adj[vertex][i].data == 0)
            neighbours[i] = 0;
        else
            neighbours[i] = 1;
    }

    return neighbours;
}

// Internal Queue

Queue* q_create() {
    Queue* new = (Queue*)malloc(sizeof(Queue));
    new->last = new->first = NULL;

    return new;
}

Queue* q_insert(Queue* q, unsigned int vertex) {
    QData* new = (QData*)malloc(sizeof(Data));
    new->data = vertex;
    new->next = NULL;

    if(q->first == NULL) { // Empty Queue
        q->first = q->last = new;
    } else {
        q->last->next = new;
        q->last = new;
    }

    return q;
}

Queue* q_remove(Queue* q, unsigned int *vertex) {
    *vertex = q->first->data;
    
    QData* aux = q->first;
        
    q->first = q->first->next;

    if(q->first == NULL)
        q->last = NULL;

    free(aux);

    return q;
}

Queue* q_delete(Queue *q) {
    QData* aux;
    while(q->first != NULL) {
        aux = q->first;
        q->first = q->first->next;
        free(aux);   
    }
    q->last = NULL;

    free(q);
    return NULL;
}

// Internal Stack

Stack* s_create() {
    return NULL;
};

Stack* s_push(Stack* s, unsigned int vertex) {
    Stack* new = (Stack*)malloc(sizeof(Stack));
    new->vertex = vertex;
    new->next = s;

    return new;
}

Stack* s_pop(Stack* s, unsigned int* vertex) {

    Stack* aux = s;

    if(s != NULL) {
        *vertex = s->vertex;
        s = s->next;
        free(aux);
    }

    return s;
}

Stack* s_delete(Stack* s) {
    Stack* aux;
    while(s != NULL) {
        aux = s;
        s = s->next;
        free(aux);
    }

    return NULL;
}
