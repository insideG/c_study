#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  STACK_SIZE  100           /* ջ��ʼ������С  */ 
#define  STACKINCREMENT 10   /* �洢�ռ��������  */ 
typedef  int  ElemType; 
typedef struct sqstack
{
	ElemType* bottom;    /*  ջ������ʱֵΪNULL  */
	ElemType* top;      /*  ջ��ָ��  */
	int   stacksize;      /*  ��ǰ�ѷ���ռ䣬��Ԫ��Ϊ��λ  */
}SqStack;

SqStack  S;  /* һ�㶨��Ϊȫ�ֽṹ����� */   

SqStack* Init_Stack(void) 
{ 
	S.bottom = (ElemType*)malloc(STACK_SIZE * sizeof(ElemType)); 
	if (!S.bottom) 
		return  NULL; 
	S.top = S.bottom;    /*  ջ��ʱջ����ջ��ָ����ͬ  */ 
S.stacksize = STACK_SIZE;  return &S;
}
ElemType* push(SqStack* S, ElemType  e) 
{ 
	if (S->top - S->bottom >= S->stacksize - 1) 
	{ 
		S->bottom = (ElemType*)realloc(S->bottom ,(STACKINCREMENT + STACK_SIZE) * sizeof(ElemType));   /*  ջ����׷�Ӵ洢�ռ�  */               
		if (!S->bottom)  
			return  NULL;                
	S->top = S->bottom + S->stacksize;      
	S->stacksize += STACKINCREMENT;
	}  
	*S->top = e;    S->top++; /* ջ��ָ���1��e��Ϊ�µ�ջ�� */  
	return S->top; 
}

ElemType* pop(SqStack* S, ElemType* e)       /*����ջ��Ԫ��*/ 
{ 
	if (S->top == S->bottom)   
		return  NULL;       /*  ջ�գ�����ʧ�ܱ�־  */ 
	S->top--;  
	*e = *S->top;   
	return  S->top;
}


/*��ʾջ�е�����*/
void Dis_Stack(SqStack stack) {
	do {
		stack.top--;
		printf("%d", *stack.top);

	} while (stack.top > stack.bottom);
}
int translate(int n,int num, SqStack *S)//����ת��
{
	int a;
	while (n)
	{
		a = n % num;
		push(S, a);
		n = n / num;
	}
	return 0;
}
int main()
{
	ElemType n,hex,err_flag=0;
	printf("please enter a number\n");
	scanf_s("%d", &n);
	do
	{
		
		printf("please enter a hex\n");
		scanf_s("%d", &hex);
		if (hex < 2 || hex>16)
		{
			err_flag = 1;
			printf("enter error,please enter again\n");
		}
		else if (hex <= 16 && hex >= 2)
		{
			err_flag = 0;
		}
	} while (err_flag);
	Init_Stack();
	translate(n, hex,&S);
	Dis_Stack(S);
}

