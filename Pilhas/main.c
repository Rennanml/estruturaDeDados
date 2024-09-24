#include "stack.c"

int main(int argc, char const *argv[])
{
    int n = 6;
    t_stack* stack = create_stack(n);

    push(stack, 3);
    push(stack, 7);
    push(stack, 5);
    push(stack, 10);
    push(stack, 19);
    push(stack, 89);

    t_elem x;
    pop(stack, &x);
    printf("Item pop -> %d\n", x);

    top(stack, &x);
    printf("Stack top -> %d\n", x);

    print(stack);
    destroy(stack);
    return 0;
}
