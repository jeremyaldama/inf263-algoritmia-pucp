#include <stdio.h>
#include <stdlib.h>

/* Desarrollado por Johan Baldeón */

typedef struct QueueNode {
	int elem;
	struct QueueNode *next;
	struct QueueNode *previous;
} TQueueNode;

typedef struct Queue{
	TQueueNode *head;
	TQueueNode *last;
} TQueue;

typedef TQueue* MyQueue;

/*Prototipos de funciones*/
void create_queue(MyQueue *);
void queue(MyQueue *, int);
void show_queue_elements (MyQueue);
int is_empty(MyQueue);
int dequeue_running_from_the_last(MyQueue *);
int dequeue_using_previous(MyQueue *);

int main(){
	MyQueue myQueue;
	create_queue(&myQueue);
	
	queue(&myQueue, 3);
	queue(&myQueue, 8);
	queue(&myQueue, 7);
	queue(&myQueue, 19);
	queue(&myQueue, 666);
	
	show_queue_elements(myQueue);
	if (myQueue->head != NULL)
		printf("Datos de la cabeza: %d\n", myQueue->head->elem);
	
	/* Desencolado haciendo el recorrido desde el último hacia adelante */
	int value = dequeue_running_from_the_last(&myQueue);
	printf("Valor sacado de la cola: %d\n", value);

	/* Desencolado usando el previous de head */
	value = dequeue_using_previous(&myQueue);
	printf("Valor sacado de la cola: %d\n", value);
	value = dequeue_using_previous(&myQueue);
	printf("Valor sacado de la cola: %d\n", value);
	
	show_queue_elements(myQueue);	

	if (myQueue->head != NULL)
		printf("Datos de la cabeza: %d\n", myQueue->head->elem);
	if (myQueue->last != NULL)
		printf("Datos del último de la cola: %d\n", myQueue->last->elem);
	
	printf("\n");
	
	return 0;
}

void create_queue(MyQueue *ptrQueue){
	*ptrQueue = (TQueue*)malloc (sizeof(TQueue));
	(*ptrQueue)->head = NULL;
	(*ptrQueue)->last = NULL;
}

void queue(MyQueue *ptrQueue, int value){
	TQueueNode *ptrNewNode = (TQueueNode *) malloc(sizeof(TQueueNode));
	ptrNewNode->elem = value;
	ptrNewNode->next = (*ptrQueue)->last;	
	ptrNewNode->previous = NULL;
	if ((*ptrQueue)->last != NULL)
		(*ptrQueue)->last->previous = ptrNewNode;
	(*ptrQueue)->last = ptrNewNode;
	if ((*ptrQueue)->last->next == NULL)
		(*ptrQueue)->head = (*ptrQueue)->last; 
}

void show_queue_elements (MyQueue myQueue){
	if (myQueue->last == NULL)
		printf("No hay nodos en la cola.\n");
	else {
		TQueueNode *ptr_runner = myQueue->last;
		while (ptr_runner != NULL){
			printf("Elemento: %d ", ptr_runner->elem);
			ptr_runner = ptr_runner -> next;
		}
		printf("\n");
	}
}

int is_empty(MyQueue myQueue){
	return myQueue->last == NULL;
}

int dequeue_using_previous(MyQueue *ptrQueue){	
	int value=-1;
	if (!is_empty(*ptrQueue)){
		value = (*ptrQueue)->head->elem;
		(*ptrQueue)->head = (*ptrQueue)->head->previous;
		if ((*ptrQueue)->head == NULL){
			free ((*ptrQueue)->last);	
			(*ptrQueue)->last = NULL;
		}
		else {
			free ((*ptrQueue)->head->next);	
			(*ptrQueue)->head->next = NULL;
		}		
	}
	return value;
}

int dequeue_running_from_the_last(MyQueue *ptrQueue){
	TQueueNode * ptr_runner, *ptr_last;
	int value=-1;

	if (!is_empty(*ptrQueue)){
		value = (*ptrQueue)->head->elem;
		ptr_last = NULL;
		ptr_runner = (*ptrQueue)->last;
		while (ptr_runner->next){
			ptr_last = ptr_runner;
			ptr_runner = ptr_runner->next;
		}
		if (ptr_last == NULL) {// Es verdadero cuando solo había un elemento en la cola
			(*ptrQueue)->last = NULL;
			(*ptrQueue)->head = NULL;
		}else {
			ptr_last->next = NULL;
			(*ptrQueue)->head = ptr_last;
		}
		free (ptr_runner);
	}
	return value;
}