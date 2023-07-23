#include <stdio.h>
#include <stdlib.h>

typedef char TInfo;

typedef struct Node{
    TInfo info;
    struct Node *left, *right; 
} TNode;

typedef struct Tree{
    TNode * root;
} TBinaryTree;

typedef TBinaryTree* MyBinaryTree;

void create_binary_tree(MyBinaryTree *ptrMyBinaryTree);
void insert(MyBinaryTree* ptrTree, TInfo data);
int is_empty(MyBinaryTree my_tree);
int is_present(MyBinaryTree tree, TInfo value);
int height(TNode*);
int weight(TNode*);
void remove_node(MyBinaryTree* ptrTree, TInfo data);
void print_preorder(TNode * ptrNode);
void print_inorder(TNode * ptrNode);
void print_postorder(TNode * ptrNode);

TNode* search(TNode *, TInfo);
TNode* insert_rec(TNode *, TInfo);
TNode* min_value_node(TNode*);
TNode* delete_node(TNode *, TInfo);

int main(){
    MyBinaryTree my_tree;
    create_binary_tree(&my_tree);
    if (is_empty(my_tree))
        printf("El árbol está vacío!\n");
    /*
    insert(&my_tree, 'K');
    insert(&my_tree, 'E');
    insert(&my_tree, 'C');
    insert(&my_tree, 'P');
    insert(&my_tree, 'G');
    insert(&my_tree, 'F');
    insert(&my_tree, 'A');
    insert(&my_tree, 'T');
    insert(&my_tree, 'M');
    insert(&my_tree, 'U');
    insert(&my_tree, 'V');
    insert(&my_tree, 'X');
    insert(&my_tree, 'Z');
   */
    my_tree->root = insert_rec(my_tree->root, 'K');
    insert_rec(my_tree->root, 'E');
    insert_rec(my_tree->root, 'C');
    insert_rec(my_tree->root, 'P');
    insert_rec(my_tree->root, 'G');
    insert_rec(my_tree->root, 'F');
    insert_rec(my_tree->root, 'A');
    insert_rec(my_tree->root, 'T');
    insert_rec(my_tree->root, 'M');
    insert_rec(my_tree->root, 'U');
    insert_rec(my_tree->root, 'V');
    insert_rec(my_tree->root, 'X');
    insert_rec(my_tree->root, 'Z');

    TNode* node = search(my_tree->root, 'U');
    if (node != NULL) printf("Sí está el valor de %c.\n", node->info);
    else printf("El valor de U no se encuentra en el árbol.\n");

    printf("Impresión del árbol binario en preorden:\n");
    print_preorder(my_tree->root);
    printf("\nImpresión del árbol binario en orden:\n");
    print_inorder(my_tree->root);
    printf("\nImpresión del árbol binario en postorden:\n");
    print_postorder(my_tree->root);

    if (!is_empty(my_tree))
        printf("\nEl árbol no está vacío!\n");
    
    if (is_present(my_tree, 20)) 
        printf("El valor de 20 sí está presente!\n");

    insert(&my_tree, 8);
    printf("\nImpresión del árbol binario en orden:\n");
    print_inorder(my_tree->root);

    remove_node(&my_tree, 7);

    printf("Impresión del árbol binario en preorden:\n");
    print_preorder(my_tree->root);
    printf("\nImpresión del árbol binario en orden:\n");
    print_inorder(my_tree->root);
    printf("\nImpresión del árbol binario en postorden:\n");
    print_postorder(my_tree->root);

    printf("\nLa altura del árbol es %d.\n", height(my_tree->root));
    printf("\nEl peso del árbol (cantidad de nodos) es %d.\n", weight(my_tree->root));


}

void create_binary_tree(MyBinaryTree *ptrMyBinaryTree){
    *ptrMyBinaryTree = (TBinaryTree*)malloc(sizeof(TBinaryTree));
    (*ptrMyBinaryTree)->root = NULL;
}

void insert(MyBinaryTree* ptrTree, TInfo data){
    TNode* new_node = (TNode*)malloc(sizeof(TNode));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->info = data;

    TNode* aux = (*ptrTree)->root;
    TNode* father = NULL;

    while ( aux != NULL ){
        father = aux;
        if (data <= aux->info)
            aux = aux->left;
        else
            aux = aux->right;
    }

    if (father == NULL)
        (*ptrTree)->root = new_node;
    else {
        if (data <= father->info)
            father->left = new_node;
        else 
            father->right = new_node;
    }
}

int is_empty(MyBinaryTree my_tree) {
    return my_tree->root == NULL;
}

void print_preorder(TNode * ptrNode){
    if (ptrNode == NULL)
        return;
    printf("%c ", ptrNode->info);
    print_preorder(ptrNode->left);
    print_preorder(ptrNode->right);
}

void print_inorder(TNode * ptrNode){
    if (ptrNode == NULL)
        return;
    print_inorder(ptrNode->left);
    printf("%c ", ptrNode->info);
    print_inorder(ptrNode->right);
}

void print_postorder(TNode * ptrNode){
    if (ptrNode == NULL)
        return;    
    print_postorder(ptrNode->left);
    print_postorder(ptrNode->right);
    printf("%c ", ptrNode->info);
}

int is_present(MyBinaryTree tree, TInfo value){
    TNode * aux = tree->root;
    while (aux != NULL){
        if (aux->info == value)
            return 1;
        else if (value < aux->info)
            aux = aux->left;
        else
            aux = aux->right;
    }
    return 0;
}

int height(TNode* ptrNode){
    if (ptrNode == NULL) return 0;

    int left_height = height(ptrNode->left);
    int right_height = height(ptrNode->right);
    return 1 + (left_height > right_height ? left_height : right_height);

}

int weight(TNode* ptrNode){
    if (ptrNode == NULL) return 0;
    return 1 + weight(ptrNode->left) + weight(ptrNode->right);
}

void remove_node(MyBinaryTree* ptrTree, TInfo data){
    TNode* aux = (*ptrTree)->root;
    TNode* p = NULL;

    while (aux != NULL){
        if (aux->info == data) break;
        else if (data < aux->info){
            p = aux;
            aux = aux->left;
        } else {
            p = aux;
            aux = aux->right;
        }
    }
    if (aux == NULL) return;

    //En el caso que el nodo a eliminar fuese una hoja
    if (aux->left == NULL && aux->right == NULL){
        if (p == NULL)
            (*ptrTree)->root = NULL;
        else {
            if (p->left == aux)
                p->left = NULL;
            else if (p->right == aux)
                p->right = NULL;
        }
        free(aux);
        return;
    }

    //En el caso que el nodo a eliminar tenga un solo hijo por la izquierda
    if (aux->left != NULL && aux->right == NULL){
        if (p == NULL)
            (*ptrTree)->root = aux->left;
        else {
            if (p->left == aux)
                p->left = aux->left;
            if (p->right == aux)
                p->right = aux->left;
        }
        free(aux);
        return;
    }

    //En el caso que el nodo a eliminar tenga un solo hijo por la derecha
    if (aux->left == NULL && aux->right != NULL){
        if (p == NULL)
            (*ptrTree)->root = aux->right;
        else {
            if (p->left == aux)
                p->left = aux->right;
            if (p->right == aux)
                p->right = aux->right;
        }
        free(aux);
        return;
    }

    //En el caso que el nodo a eliminar tenga dos hijos
    TNode* q = aux->left;
    while (q->right != NULL)
        q = q->right;

    TInfo key = q->info;
    remove_node(ptrTree, key);

    aux->info = key;
}


TNode* search(TNode * root, TInfo data){
    if (root->info == data || root == NULL) return root;
    else 
        if (data < root->info)
            return search(root->left, data);
        else
            return search(root->right, data);
}

TNode* insert_rec(TNode *root, TInfo data){
    if (root == NULL){
        root = (TNode*)malloc(sizeof(TNode));
        root->info = data;
    } else 
        if (data < root->info)
            root->left = insert_rec(root->left, data);
        else 
            root->right = insert_rec(root->right, data);
    return root;
}

TNode* min_value_node(TNode* root){
    TNode* runner = root;
    while (runner && runner->left != NULL)
        runner = runner ->left;
    return runner;
}

TNode* delete_node(TNode *root, TInfo data){
    if (root == NULL) return root;
    if (data < root->info) 
        root->left = delete_node(root->left, data);
    else if (data > root->info)
        root->right = delete_node(root->right, data); 
    else {
        if (root->left == NULL){
            TNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            TNode* temp = root->left;
            free(root);
            return temp;
        }
        TNode* temp = min_value_node(root->right);
        root->info = temp->info;
        root->right = delete_node(root->right, temp->info);
    }
    return root;
}