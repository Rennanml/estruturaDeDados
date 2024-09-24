#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef int t_elem;

// implementacao com vetor estatico e circular
typedef struct {
    int begin;
    int end;
    int size;
    int max;
    t_elem* items;

} t_queue;


t_queue* create_queue(int n);
void destroy(t_queue *q);
int is_empty(t_queue *q);
int is_full(t_queue *q);
int size(t_queue *q);
int in(t_queue *q, t_elem x);
int out(t_queue *q, t_elem *x);
void clear(t_queue *q);
void print(t_queue *q);

#endif /* QUEUE_H*/