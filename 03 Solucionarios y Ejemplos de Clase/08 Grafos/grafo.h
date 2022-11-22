#include <stdio.h>
#include <stdlib.h>

typedef int TGraNode;

struct SEdgeNode {
	TGraNode node_value;
	double weight;
	struct SEdgeNode *next_edge;
};

typedef struct SEdgeNode TEdgeNode;

struct SVertexNode{
	TGraNode node_value;
	TEdgeNode *edge_list;
	struct SVertexNode *next_vertex;
};

typedef struct SVertexNode TVertexNode;

TVertexNode* create_graph();
int exist_edges(TVertexNode * ptr_vertex_list);
TVertexNode* exists_vertex(TVertexNode * ptr_vertex_list, TGraNode vertex1);
TEdgeNode* exists_edge(TVertexNode* ptr_vertex_node_1, TGraNode vertex2);
void insert_edge(TVertexNode * ptr_vertex_list, TGraNode vertex1, TGraNode vertex2, double weight);
TVertexNode* insert_vertex(TVertexNode * ptr_vertex_list, TGraNode node_value);
void print_graph(TVertexNode *ptr_vertex_list);
void print_edges(TEdgeNode *ptr_edge_list);

