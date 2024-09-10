#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int max;
	int n;
	int* items;
	
}t_list;

t_list * create_list(int max){
	t_list* list = (t_list*) malloc(sizeof(t_list));
	list->max = max;
	list->n = 0;
	list->items = (int*) malloc(sizeof(int)*max);
	return list;
}

int destroy_list(t_list* list){
	free(list->items);
	free(list);
	return 1;
}

int len(t_list* list){	
	return list->n;
}

int is_full(t_list* list){
	return list->n == list->max;
}

int append(t_list* list, int element) {
	if (! is_full(list))
	{
		list->items[list->n] = element;
		list->n++;
		return 1;
	}
	return 0;
}

void print_list(t_list* list){
	for (int i = 0; i < list->n; i++)
	{
		printf("%d ", list->items[i]);
	}
}

int main(int argc, char **argv)
{
	t_list* list;
	
	list = create_list(10);
	append(list, 10);
	append(list, 23);
	append(list, 2);
	
	print_list(list);
	destroy_list(list);
	return 0;
}
