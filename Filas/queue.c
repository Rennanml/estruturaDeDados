#include "queue.h"

t_queue* create_queue(int n){
    t_queue* q = (t_queue*) malloc(sizeof(t_queue));

    q->max = n;
    q->begin = 0;
    q->end = 0;
    q->size = 0;
    q->items = (t_elem*) malloc(sizeof(t_elem) * n);
}

void destroy(t_queue *q);

int is_empty(t_queue *q){
    return q->begin == q->end;
}


int is_full(t_queue *q){
    return q->size == q->max;
}
int size(t_queue *q){
    return q->size;
}

int in(t_queue *q, t_elem x){
    if (! is_full(q))
    {
        q->items[q->end] = x;
        q->end = (q->end + 1) % q->max;
        q->size++;
        return 1;
    }
    return 0;
}

int out(t_queue *q, t_elem *x){
    if (! is_empty(q))
    {
        *x = q->items[q->begin];
        q->begin = (q->begin + 1) % q->max;
        q->size--;
        return 1;
    }
    return 0;
}

void clear(t_queue *q){
    q->end = q->begin;
    q->size = 0;
}
void print(t_queue *q);
