#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int elem;
	struct QueueNode *next;
} TQueueNode;

typedef TQueueNode * TQueue;

/*Prototipos de funciones*/
void create_queue(TQueue *);
void queue(TQueue *, int);
void show_queue_elements (TQueue);
int dequeue(TQueue *);
int is_empty(TQueue);

int main(){
	TQueue ptrQueue;

	create_queue(&ptrQueue);
	queue(&ptrQueue, 3);
	queue(&ptrQueue, 8);
	queue(&ptrQueue, 7);
	queue(&ptrQueue, 19);
	queue(&ptrQueue, 666);

	show_queue_elements(ptrQueue);

	int value = dequeue(&ptrQueue);
	printf("\nValor sacado de la cola: %d\n", value);
	show_queue_elements(ptrQueue);	
	printf("\n");

	/*Tarea:
		Liberar la memoria de las variables tipo puntero que fueron reservados con malloc.
	 */

	return 0;
}

void create_queue(TQueue *ptrQueue){
	*ptrQueue = NULL;
}

void queue(TQueue *ptrQueue, int value){
	TQueueNode *ptrNewNode = (TQueueNode *) malloc(sizeof(TQueueNode));
	ptrNewNode->elem = value;
	ptrNewNode->next = *ptrQueue;
	*ptrQueue = ptrNewNode;
}

void show_queue_elements (TQueue v_queue){
	while (v_queue != NULL){
		printf("Elemento: %d ", v_queue->elem);
		v_queue = v_queue -> next;
	}
}

int is_empty(TQueue v_queue){
	return v_queue == NULL;
}

int dequeue(TQueue *ptr_queue){
	TQueueNode * ptr_runner, *ptr_last;
	int value=-1;

	if (!is_empty(*ptr_queue)){
		ptr_last = NULL;
		ptr_runner = *ptr_queue;
		while (ptr_runner->next){
			ptr_last = ptr_runner;
			ptr_runner = ptr_runner->next;
		}
		if (ptr_last == NULL) // Es verdadero cuando solo había un elemento en la cola
			*ptr_queue = NULL;
		else
			ptr_last->next = NULL;
		value = ptr_runner->elem;
		free (ptr_runner);
	}
	return value;
}