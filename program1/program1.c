#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

void push(struct stack * sp, int x);
int pop(struct stack * sp);
void display(struct stack * sp);

int main(){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size*sizeof(int));

    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);

    pop(sp);
    display(sp);

}

void push(struct stack * sp, int x){
    if (sp->top == sp->size - 1){
        printf("Overflow");
        return;
    }
    sp->top++;
    sp->arr[sp->top] = x;
}

int pop(struct stack * sp){
    if(sp->top == -1){
        printf("Underflow");
    }
    else{
        // printf("The popped element is %d \n", sp->arr[sp->top]);
        int pop_element = sp->arr[sp->top];
        sp->top--;
        return pop_element;
    }
}

void display(struct stack * sp){
    printf("The elements in the stack are : \n");
    while(sp->top != -1){
        printf("%d \n",pop(sp));
    }
}
