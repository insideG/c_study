#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
    int num;
    char name[11];
    struct _node* next;
}node;

node* createlist(int n);
void display(node* head);
int save(node* head, int n);


int main(void)
{
    node* head;
    int n;
    printf("please enter the number of student\n");
    scanf("%d", &n);
    head = createlist(n);
    display(head);
    save(head,n);
    return 0;
}
int save(node* head,int n)
{
    node* p = head;
    FILE* w = fopen("output.txt", "w+");
    if (w == NULL)
    {
        printf("打开文件失败!");
        return 0;
    }
    while (n--)
    {
        fprintf(w, "num:\t");
        fprintf(w, "%d ", p->num);
        fprintf(w, "\n");
        fprintf(w, "name:\t");
        fprintf(w, "%s ", p->name);
        fprintf(w, "\n");
        p = p->next;
    }
    fclose(w);
    return 1;
}
node* createlist(int n)
{
    node* head = NULL, * p, * tail = NULL;
    while (n--)//当输入不为整数时结束
    {
        p = (node*)malloc(sizeof(node));

        if (head == NULL)
            head = p;
        else
            tail->next = p;
        printf("please enter the student %d num\n",n);
        scanf("%d",&p->num);
        printf("please enter the student %d name\n",n);
        scanf("%s",p->name);
        p->next = NULL;
        tail = p;
    }
    return head;
}

void display(node* head)
{
    node* p;
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->num);
        printf("%s ", p->name);
        p = p->next;
    }
    printf("\n");
}