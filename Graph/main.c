#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main() {
    
    Graph* g = NULL;

    int sizes, edges, v1, v2;
    printf("Quantidade de vertices: "); scanf("%d", &sizes);
    printf("Quandidade de arestas: "); scanf("%d", &edges);
    g = graph_create(sizes, edges);

    printf("Digite o número dos nos de cara aresta(x y):\n");
    for(int i = 0; i < g->edges; i++) {
        scanf("%d %d", &v1, &v2);
        graph_add(g, v1, v2);
    }

    printf("No que comecaremos a bfs: "); scanf("%d", &v1);
    bfs(g, v1);

    printf("No que comecaremos a dfs iterativa: "); scanf("%d", &v1);
    dfs_iter(g, v1);

    printf("No que comecaremos a dfs recursiva: "); scanf("%d", &v1);
    dfs_recursive(g, v1);

    graph_delete(g);

    return EXIT_SUCCESS;
}
