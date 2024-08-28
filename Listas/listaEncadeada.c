#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int item;
	struct t_node* next;
}t_node;

typedef struct {
	t_node* head;
	t_node* tail;
	int size;
}t_list;

t_list * create_list(){
	
	t_list* list;
	list = (t_list*) malloc(sizeof(t_list));
	if (list == NULL)
		exit(1);
		
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	
	return list;
}

int is_empty(t_list* list){
	return list->size == 0;
}

void append(t_list* list, int item){
	t_node* node = (t_node*) malloc(sizeof(t_node));
	if (node == NULL)
		exit(1);
		
	if (is_empty(list))
	{
		list->head = node;
	}else
	{
		list->tail->next = node;
	}
	
	node->next = NULL;
	list->tail = node;
	node->item = item;
	list->size++;
}

void destroy_list(t_list* list) {
	free(list->head);
	free(list->tail);
	free(list);
}

void print_list(t_list* list){
	t_node *node_aux;
	node_aux = list->head;
	while (node_aux != NULL)
	{
		printf("%d ", node_aux->item);
		node_aux = node_aux->next;
	}
}

int main(int argc, char **argv)
{
	t_list* list;
	list = create_list();
	append(list, 2);
	append(list, 3);
	append(list, 5);
	append(list, 9);
	
	print_list(list);
	
	destroy_list(list);
	return 0;
}

