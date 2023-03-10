#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
	printf("Ejemplo de grafo:\n");
	TVertexNode *ptr_vertex_list = create_graph();
	ptr_vertex_list = insert_vertex(ptr_vertex_list, 'A');
	ptr_vertex_list = insert_vertex(ptr_vertex_list, 'B');
	ptr_vertex_list = insert_vertex(ptr_vertex_list, 'C');
	ptr_vertex_list = insert_vertex(ptr_vertex_list, 'D');
	ptr_vertex_list = insert_vertex(ptr_vertex_list, 'E');
	ptr_vertex_list = insert_vertex(ptr_vertex_list, 'F');

	insert_edge(ptr_vertex_list, 'A', 'B', 0);
	insert_edge(ptr_vertex_list, 'A', 'C', 0);
	insert_edge(ptr_vertex_list, 'A', 'D', 0);
	insert_edge(ptr_vertex_list, 'C', 'E', 0);
	insert_edge(ptr_vertex_list, 'D', 'F', 0);	

	print_graph(ptr_vertex_list);
}