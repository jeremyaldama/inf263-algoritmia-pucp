#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	double weight;
	double profit;
	double profit_density;
} item;

double knapsack(double * weights, double * profits, int n, double capacity, int **max_knapsack);
void knapsack_recur(item *items, int n, double capacity, int *current_knapsack, double *current_weight, 
					double *current_profit, int *max_knapsack, double *max_profit, int level);
int compare_items(item *item1, item *item2);
double profit_addition(item *items, int n, double capacity, double current_weight, 
		double current_profit, int	level);

int main(){
	int i, n = 5;
	double weights[] = { 5, 4, 3, 2, 1};
	double profits[] = { 6, 8, 9, 7, 12};

	double capacity = 8;
	int *max_knapsack;
	double max_profit = knapsack(weights, profits, n, capacity, &max_knapsack);

	printf("Beneficio: %.2lf\n", max_profit);
	for (i=0; i<n; i++){
		if (max_knapsack[i] == 1)
			printf("Objeto %d: Beneficio - %.2lf, Peso - %.2lf\n", 
				i, profits[i], weights[i]);
	}
	free(max_knapsack);
	return 0;
}

double knapsack(double * weights, double * profits, int n, double capacity, int **max_knapsack){
	int i;
	item *items = (item *)malloc(n * sizeof(item));
	*max_knapsack = (int *)malloc(n * sizeof(int));
	int *current_knapsack = (int *) malloc(n * sizeof(int));
	double current_weight = 0.0;
	double current_profit = 0.0;
	double max_profit = 0.0;

	for (i=0; i<n; i++){
		items[i].id = i;
		items[i].weight = weights[i];
		items[i].profit = profits[i];
		items[i].profit_density = profits[i] / weights[i];
	}

	qsort(items, n, sizeof(item),  (int (*)(const void *, const void *))compare_items);

	knapsack_recur(items, n, capacity, current_knapsack, &current_weight, 
		&current_profit, *max_knapsack, &max_profit, 0);

	return max_profit;
}

void knapsack_recur(item *items, int n, double capacity, int *current_knapsack, 
		double *current_weight, double *current_profit, int *max_knapsack, 
		double *max_profit, int level){
	if (level == n){
		*max_profit = *current_profit;
		memcpy(max_knapsack, current_knapsack, n* sizeof(int));
		return;
	}
	if (*current_weight + items[level].weight <= capacity){
		*current_weight += items[level].weight;
		*current_profit += items[level].profit;
		current_knapsack[items[level].id] = 1;
		knapsack_recur(items, n, capacity, current_knapsack, current_weight, 
			current_profit, max_knapsack, max_profit, level+1);
		*current_weight -= items[level].weight;
		*current_profit -= items[level].profit;
		current_knapsack[items[level].id] = 0;
	}
	double profit_add = profit_addition(items, n, capacity, *current_weight, *current_profit,level+1);

	if ( profit_add> *max_profit){
		knapsack_recur(items, n, capacity, current_knapsack, current_weight,
			current_profit, max_knapsack, max_profit, level+1);
	}
}

double profit_addition(item *items, int n, double capacity, double current_weight, 
		double current_profit, int	level){
	double result=current_profit;
    double remaining_capacity = capacity - current_weight;
    int lvl = level;
    while (lvl < n && items[lvl].weight <= remaining_capacity) {
        remaining_capacity -= items[lvl].weight;
        result += items[lvl].profit;
        lvl++;
    }
	return result;
}

int compare_items(item *item1, item *item2)
{
    if (item1->profit_density > item2->profit_density) {
        return -1;
    }
    if (item1->profit_density < item2->profit_density) {
        return 1;
    }
    return 0;
}
