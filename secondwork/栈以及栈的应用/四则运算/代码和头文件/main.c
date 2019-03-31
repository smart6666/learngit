#include"SZstack.h"
#include"SZstack.c"

void calu(LinkStack* s_num, LinkStack* s_opt);
char* s_gets(char* st, int n);
int Priority(char ch);
int main(void)
{
    LinkStack s_num, s_opt;
    char opt[SIZE] = {0};
    int i = 0, temp = 0;
    int ch;
    initLStack(&s_num);
    initLStack(&s_opt);
    printf("\nPlease input your arithmetic expressions: \n");
    s_gets(opt, SIZE);
    while (opt[i] != '\0')                                  /*表达式没结束*/
    {
        if(opt[i] >= '0' && opt[i] <= '9')                  /*判断表达式是否为数字，数字直接进栈*/
        {
            temp = temp * 10 + opt[i] -'0';                 /*后一个为数字时，前一个乘10，加上后一个*/
            i++;
            if(opt[i] > '9' || opt[i] < '0')                /*判断后一个是否为操作符*/
            {
                pushLStack(&s_num, temp);                   /*数字进栈*/
                temp = 0;                                   /*清零，用以记录下一个操作数*/
            }
        }
        else                                                /*若表达式为操作符*/
            {
                if((isEmptyLStack(&s_opt))                   /* 操作符栈为空 */
                    || Priority(opt[i]) > Priority(getTop(&s_opt))/* 表达式优先级大于栈顶操作符优先级 */
                    || opt[i] != ')' && getTop(&s_opt) == '(')/* 栈顶为'('并且表达式当前值不为')' */
                {
                    pushLStack(&s_opt, opt[i]);/*操作符进栈*/
                    i++;

                    continue;                   /*继续下一次循环*/
                }

                if(opt[i] == ')')
                {
                    while(getTop(&s_opt) != '(' && (!isEmptyLStack(&s_opt)))
                    {
                    calu(&s_num, &s_opt);-
                    i++;
                    }
                    popLStack(&s_opt, &ch);
                    continue;
                }

                 if(Priority(opt[i]) < Priority(getTop(&s_opt)))
                {
                     calu(&s_num, &s_opt);
                     pushLStack(&s_opt, opt[i]);
                     i++;
                     continue;
                }
                pushLStack(&s_opt, opt[i]);/*操作符进栈*/
                    i++;
            }

        }
    while(!isEmptyLStack(&s_opt))
    {
       calu(&s_num, &s_opt);
    }
    printf("\nThe result is %d.",s_num.top->data);
    free(s_num.top);
    getchar();
    return 0;

}

char* s_gets(char* st, int n)
{
    char* ret_val;
    int i=0;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

void calu(LinkStack* s_num, LinkStack* s_opt)
{
    int ch;
    popLStack(s_opt, &ch);
    int num;
    popLStack(s_num, &num);
    switch(ch)
    {
        case '*': s_num->top->data = s_num->top->data * num; break;
        case '/': s_num->top->data = s_num->top->data / num; break;
        case '+': s_num->top->data = s_num->top->data + num; break;
        case '-': s_num->top->data = s_num->top->data - num; break;
    }
}

int Priority(char ch)
{
    switch(ch)
    {
        case '(': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
