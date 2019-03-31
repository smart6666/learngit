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
    while (opt[i] != '\0')                                  /*���ʽû����*/
    {
        if(opt[i] >= '0' && opt[i] <= '9')                  /*�жϱ��ʽ�Ƿ�Ϊ���֣�����ֱ�ӽ�ջ*/
        {
            temp = temp * 10 + opt[i] -'0';                 /*��һ��Ϊ����ʱ��ǰһ����10�����Ϻ�һ��*/
            i++;
            if(opt[i] > '9' || opt[i] < '0')                /*�жϺ�һ���Ƿ�Ϊ������*/
            {
                pushLStack(&s_num, temp);                   /*���ֽ�ջ*/
                temp = 0;                                   /*���㣬���Լ�¼��һ��������*/
            }
        }
        else                                                /*�����ʽΪ������*/
            {
                if((isEmptyLStack(&s_opt))                   /* ������ջΪ�� */
                    || Priority(opt[i]) > Priority(getTop(&s_opt))/* ���ʽ���ȼ�����ջ�����������ȼ� */
                    || opt[i] != ')' && getTop(&s_opt) == '(')/* ջ��Ϊ'('���ұ��ʽ��ǰֵ��Ϊ')' */
                {
                    pushLStack(&s_opt, opt[i]);/*��������ջ*/
                    i++;

                    continue;                   /*������һ��ѭ��*/
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
                pushLStack(&s_opt, opt[i]);/*��������ջ*/
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
