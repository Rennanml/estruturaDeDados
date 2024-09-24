#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

t_stack* create_stack(int n){
    t_stack *p = (t_stack*) malloc(sizeof(t_stack));
    p->max = n;
    p->items = (t_elem*) malloc(sizeof(t_elem) * n);
    p->top_index = -1; //Para ficar condizente ao dar "push" na stack
    return p;
}


void destroy(t_stack *p){
    free(p->items);
    free(p);
}


int is_full(t_stack *p){
    return p->top_index == p->max - 1;
}


int is_empty(t_stack *p){
    return p->top_index == -1;
}


int push(t_stack *p, t_elem x){
    if (! is_full(p))
    {
        p->top_index++;
        p->items[p->top_index] = x;
        return 1;
    }
    return 0;
}


int pop(t_stack *p, t_elem *x){
    if (! is_empty(p))
    {
        *x = p->items[p->top_index];
        p->top_index--;
        return 1;
    }
    return 0;
}


int top(t_stack *p, t_elem *x){
    if (! is_empty(p))
    {
        *x = p->items[p->top_index];
        return 1;
    }
    return 0;
}


void clear(t_stack *p){
    p->top_index = -1;
}

void print(t_stack *p){
    for (int i = 0; i <= p->top_index; i++)
    {
        printf("%d\t", p->items[i]);
    }
    printf("\n");
}
