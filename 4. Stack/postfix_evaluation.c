// Evaluate postfix expression : 


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50

typedef struct stack { 
    char data[MAX];
    int top;
}stack;

// stack *s;

void init(stack *s){
    s->top = -1;
}

// EMPTY 
int isEmpty(stack *s){
    if(s->top == -1)
        return 1 ;
    else 
        return 0;
}

// FULL
int isFull(stack *s){
    if(s->top == (MAX-1))
        return 1;
    else    
        return 0;
}

// PUSH 
void push(stack *s, char data){
    if(!isFull(s)){
        s->top++;
        s->data[s->top] = data;
    }
    else
        printf("Stack is full !\n");
}
int peek(stack *s){
    return s->data[s->top];
}
// POP
char pop(stack *s){
    char temp = '\0';

    if(! isEmpty(s)){
        temp = s->data[s->top];
        s->top--;
    }

    return temp;
}

int operate(stack *s, int n){
    int res;
    int op2 = pop(s);
    int op1 = pop(s);

    switch (n)
    {
    case 1:
        res = op1*op2;
        break;
    case 2:
        res = op1/op2;
        break;
    case 3:
        res = op1%op2;
        break;
    case 4:
        res = op1+op2;
        break;
    case 5:
        res = op1-op2;
        break;
    
    default:
        break;
    } 

    push(s, res);
    return res;
}

int evaluate(stack *s, char *str){
    int i=0, res;

    while(*str != '\0'){
        if(*str >= 48 && *str<=57){
            push(s,*str-48);
        }
        else if(*str == '*')
            operate(s, 1);
        else if(*str == '/')
            operate(s, 2);
        else if(*str == '%')
            operate(s, 3);
        else if(*str == '+')
            operate(s, 4);
        else if(*str == '-')
            operate(s, 5);
        str++;
    }
    res = peek(s);
    return res;
}


int main(){
    stack s;
    init(&s);
    char ex[20],*str = ex;

    printf("Enter an expression : ");
    scanf("%s",ex);

    printf("Result is : %d\n" , evaluate(&s, str));

    return 0; 
}