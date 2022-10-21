#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

TVertexNode* create_graph(){
	return NULL;
}

TVertexNode * exists_vertex(TVertexNode * ptr_vertex_list, TGraNode node_value){
	while (ptr_vertex_list){
		if (ptr_vertex_list->node_value == node_value)
			return ptr_vertex_list;
		ptr_vertex_list = ptr_vertex_list->next_vertex;
	}
	return NULL;
}

int exist_edges(TVertexNode * ptr_vertex_list){
	if (ptr_vertex_list == NULL)
		return 0;
	if (ptr_vertex_list->edge_list == NULL)
		return 0;
	return 1;
}

TEdgeNode* exists_edge(TVertexNode* ptr_vertex_node_1, TGraNode vertex2){
	if (!exist_edges(ptr_vertex_node_1))
		return NULL;
	TEdgeNode* ptrEdgeList = ptr_vertex_node_1->edge_list;
	while (ptrEdgeList){
		if (ptrEdgeList->node_value == vertex2)
			return ptrEdgeList;
		ptrEdgeList = ptrEdgeList->next_edge;
	}
	return NULL;
}

void insert_edge(TVertexNode * ptr_vertex_list, TGraNode vertex1, TGraNode vertex2, double weight){

	TVertexNode* ptr_vertex_node_1 = exists_vertex(ptr_vertex_list, vertex1);

	if (ptr_vertex_node_1 && exists_vertex(ptr_vertex_list, vertex2) &&
		!exists_edge(ptr_vertex_node_1, vertex2)){
		TEdgeNode *ptr_new, *ptr_previous, *ptr_runner;

		ptr_new = (TEdgeNode *)malloc(sizeof(TEdgeNode)); 
		ptr_new->node_value = vertex2;
		ptr_new->weight = weight;
		ptr_new->next_edge = NULL;

		ptr_previous = NULL;
		ptr_runner = ptr_vertex_node_1->edge_list;

		while (ptr_runner){
			ptr_previous = ptr_runner;
			ptr_runner = ptr_runner->next_edge;
		}
		if (ptr_previous == NULL)
			ptr_vertex_node_1->edge_list = ptr_new;
		else
			ptr_previous->next_edge = ptr_new;
	}
}

TVertexNode* insert_vertex(TVertexNode * ptr_vertex_list, TGraNode node_value){
	TVertexNode *ptr_new, *ptr_previous, *ptr_runner;

	if (!exists_vertex(ptr_vertex_list, node_value)){
		ptr_new = (TVertexNode *)malloc(sizeof(TVertexNode));
		ptr_new->node_value = node_value;
		ptr_new->edge_list = NULL;
		ptr_new->next_vertex = NULL;

		ptr_previous = NULL;
		ptr_runner = ptr_vertex_list;
		while (ptr_runner){
			ptr_previous = ptr_runner;
			ptr_runner = ptr_runner->next_vertex;
		}
		if (ptr_previous == NULL)
			ptr_vertex_list = ptr_new;
		else 
			ptr_previous->next_vertex = ptr_new;
	}
	return ptr_vertex_list;
}

void print_edges(TEdgeNode *ptr_edge_list){
    int print_comma = 0;
    while (ptr_edge_list) {
        if (print_comma)
            printf(", ");
        else
            print_comma = 1;

        printf("%c(%lf)", ptr_edge_list->node_value, ptr_edge_list->weight);
        ptr_edge_list = ptr_edge_list->next_edge;
    }	
}

void print_graph(TVertexNode *ptr_vertex_list){
    while (ptr_vertex_list) {
        printf("%c: ", ptr_vertex_list->node_value);
        if (exist_edges(ptr_vertex_list))
            print_edges(ptr_vertex_list->edge_list);
        printf("\n");
        ptr_vertex_list = ptr_vertex_list->next_vertex;
    }	
}