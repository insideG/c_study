#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  STACK_SIZE  100           /* 栈初始向量大小  */ 
#define  STACKINCREMENT 10   /* 存储空间分配增量  */ 
typedef  int  ElemType; 
typedef struct sqstack
{
	ElemType* bottom;    /*  栈不存在时值为NULL  */
	ElemType* top;      /*  栈顶指针  */
	int   stacksize;      /*  当前已分配空间，以元素为单位  */
}SqStack;

SqStack  S;  /* 一般定义为全局结构体变量 */   

SqStack* Init_Stack(void) 
{ 
	S.bottom = (ElemType*)malloc(STACK_SIZE * sizeof(ElemType)); 
	if (!S.bottom) 
		return  NULL; 
	S.top = S.bottom;    /*  栈空时栈顶和栈底指针相同  */ 
S.stacksize = STACK_SIZE;  return &S;
}
ElemType* push(SqStack* S, ElemType  e) 
{ 
	if (S->top - S->bottom >= S->stacksize - 1) 
	{ 
		S->bottom = (ElemType*)realloc(S->bottom ,(STACKINCREMENT + STACK_SIZE) * sizeof(ElemType));   /*  栈满，追加存储空间  */               
		if (!S->bottom)  
			return  NULL;                
	S->top = S->bottom + S->stacksize;      
	S->stacksize += STACKINCREMENT;
	}  
	*S->top = e;    S->top++; /* 栈顶指针加1，e成为新的栈顶 */  
	return S->top; 
}

ElemType* pop(SqStack* S, ElemType* e)       /*弹出栈顶元素*/ 
{ 
	if (S->top == S->bottom)   
		return  NULL;       /*  栈空，返回失败标志  */ 
	S->top--;  
	*e = *S->top;   
	return  S->top;
}


/*显示栈中的数据*/
void Dis_Stack(SqStack stack) {
	do {
		stack.top--;
		printf("%d", *stack.top);

	} while (stack.top > stack.bottom);
}
int translate(int n,int num, SqStack *S)//进制转换
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

