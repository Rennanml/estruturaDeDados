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
	int i = 0;
	while (i < list->size)
	{
		printf("%d ", node_aux->item);
		node_aux = node_aux->next;
		i++;
	}
	printf("\n");
}

t_node* search(t_list* list, int item){
	t_node* node_aux = list->head;
	while (node_aux != NULL)
	{
		if (node_aux->item == item)
		{
			return node_aux;
		}
		node_aux = node_aux->next;
	}
	return NULL;
}

void remove_node(t_list* list, t_node* node_to_be_removed){
	t_node* node_aux = list->head;
	if (node_aux == node_to_be_removed)
	{
		list->head = node_aux->next;
		list->size--;
		if (list->tail == node_to_be_removed)
		{
			list->tail = NULL;
		}
		
	}else if (list->tail == node_to_be_removed)
	{
		while (node_aux->next != node_to_be_removed)
		{
			node_aux = node_aux->next;
		}
		free(list->tail);
		node_aux->next = NULL;
		list->tail = node_aux;
		list->size--;
	} else
	{
		int i = 0;
		while (i < list->size)
		{
			if (node_aux->next == node_to_be_removed)
			{
				i = list->size;
				node_aux->next = node_to_be_removed->next;
				free(node_to_be_removed);
				list->size--;
			}
			
			node_aux = node_aux->next;
			i++;
		}
		
	}
}

void reverse_node(t_list* list){
	t_node* prev = NULL;
	t_node* current = list->head;
	t_node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;

}

int main(int argc, char **argv)
{
	t_list* list;
	list = create_list();
	append(list, 2);
	append(list, 3);
	append(list, 5);
	append(list, 9);

	t_node* node_to_remove = search(list, 2);
	
	remove_node(list, node_to_remove);

	print_list(list);

	reverse_node(list);

	print_list(list);
	
	destroy_list(list);
	return 0;
}

