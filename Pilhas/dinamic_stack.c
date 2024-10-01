#include <stdio.h>
#include <stdlib.h>

typedef struct t_elem{
    int item;
    struct t_elem* prox;
}t_elem;

typedef struct t_stack{
    int qtde;
    int max;
    t_elem* item;
}t_stack;

t_stack* create_stack(int n){
    t_stack* stack = (t_stack*) malloc(sizeof(t_stack));
    stack->max = n;
    stack->qtde = 0;
    stack->item = NULL;
    
    return stack;
}

int is_empty(t_stack* stack){
    return stack->qtde == 0;
}

int is_full(t_stack* stack){
    return stack->qtde == stack->max;
}

int push(t_stack* stack, int x){
    if (!is_full(stack))
    {
        t_elem* aux = (t_elem*) malloc(sizeof(t_elem));
        aux->item = x;
        aux->prox = stack->item;
        stack->item = aux;
        stack->qtde++;

        return 1;
    }
    return 0;
}

int pop(t_stack* stack, int* popped){
    if (!is_empty(stack))
    {
        *popped = stack->item->item;
        stack->item = stack->item->prox;
        stack->qtde--;
        return 1;
    }
    return 0;
}

void print_stack(t_stack* stack){
    t_elem* aux;
    aux = stack->item;
    for (int i = 0; i < stack->qtde; i++)
    {
        printf("%d\t", aux->item);
        aux = aux->prox;
    }
    
}

int main(int argc, char const *argv[])
{
    t_stack* stack = create_stack(5);
    push(stack, 10);
    push(stack, 1);
    push(stack, 9);
    push(stack, 19);
    int popped;
    pop(stack, &popped);
    print_stack(stack);
    return 0;
}