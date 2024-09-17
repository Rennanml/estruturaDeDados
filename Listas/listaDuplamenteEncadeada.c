#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
    int item;
    struct t_node* next;
    struct t_node* prev;
} t_node;

typedef struct {
    t_node* head;
    t_node* tail;
    int size;
} t_list;

t_list* createList(){
    t_list* list;
    list = (t_list*) malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list; 
}

void appendList(t_list* list, int itemToAdd){
    t_node* nodeToAdd;
    nodeToAdd = (t_node*) malloc(sizeof(t_node));
    nodeToAdd->item = itemToAdd;
    if (list->size == 0)
    {
        nodeToAdd->prev = NULL;
        list->head = nodeToAdd;
    } else
    {
        list->tail->next = nodeToAdd;
        nodeToAdd->prev = list->tail;
    }

    list->tail = nodeToAdd;
    nodeToAdd->next = NULL;
    list->size++;
}

void printList(t_list* list){
    t_node* auxNode;
    auxNode = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", auxNode->item);
        auxNode = auxNode->next;
    }
}

void removeItem(t_list* list, int itemToRemove) {
    t_node* auxNode;
    auxNode = list->head;

    while (auxNode != NULL)
    {
        if (auxNode->item == itemToRemove){
            if (auxNode->prev != NULL)
            {
                auxNode->prev->next = auxNode->next;
            } else{ // se o item a ser removido é o primeiro
                list->head = auxNode->next; 
            }
            if (auxNode->next != NULL)
            {
                auxNode->next->prev = auxNode->prev;
            }else{ // se o item a ser removido é o último
                list->tail = auxNode->prev;
            }
            
            free(auxNode);
            list->size--;
            return;
        }
        auxNode = auxNode->next;
    }
}
    

int main(int argc, char const *argv[])
{
    t_list* list;
    list = createList(list);
    appendList(list, 10);
    appendList(list, 8);
    appendList(list, 9);
    appendList(list, 15);
    printList(list);
    removeItem(list, 10);
    printf("\n");
    printList(list);
    return 0;
}
