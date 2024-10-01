#include "queue.c"

int main(int argc, char const *argv[])
{
    t_queue* q = create_queue(10);
    in(q, 10);
    in(q, 12);
    in(q, 145);
    in(q, 9);
    in(q, 2);
    in(q, 3);

    t_elem x;
    out(q, &x);

    print(q);
    return 0;
}
