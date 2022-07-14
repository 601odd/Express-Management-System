#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_NAME 10
#define SIZE_ID 20

int Record = 0;

typedef struct
{
    char name[SIZE_NAME];
    char id[SIZE_ID];
    int a, b, c;
    int ava;
} pInfo;

typedef struct node
{
    pInfo people;
    struct node *next;
} linkList;

int menu();
int create(linkList *head);
int display(linkList *head);
int search(linkList *head, char *info);
int modify(linkList *head, char *pid);
int add2(linkList *head, char *pid);
int delt(linkList *head, char *info);
int compare(int ava1, int ava2);
int sort(linkList *head, int boolean); // 1升序 0降序

int main()
{
    linkList head, *p;
    char info[SIZE_ID];
    int temp, chus, i;
    head.next = NULL;

    while (1)
    {
        switch (menu())
        {
        case 1:
            create(&head);
            break;
        case 2:
            display(&head);
            break;
        case 3:
            printf("请输入需要查询的学号或姓名: ");
            scanf("%s", info);
            p = &head;
            p = p->next;
            for (i = 0; i < search(&head, info); i++)
            {
                p = p->next;
            }
            printf("搜索到:\n");
            printf("\t\t\t\t学生信息\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("\t\t学号\t\t姓名\t\t\t平均成绩\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("%20s\t", p->people.id);
            printf("%10s\t", p->people.name);
            printf("%20d\n", p->people.ava);
            break;
        case 4:
            printf("请输入需要修改的学号: ");
            scanf("%s", info);
            modify(&head, info);
            break;
        case 5:
            printf("请输入需要添加的学号: ");
            scanf("%s", info);
            add2(&head, info);
            break;
        case 6:
            printf("请输入需要删除的学号或姓名: ");
            scanf("%s", info);
            delt(&head, info);
            break;
        case 7:
            printf("请输入1或0:\n\t1:升序\n\t0:降序\n");
            scanf("%d", &temp);
            sort(&head, temp);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("输错了，再来一次\n");
        }
        // system("pause");
        system("clear");
    }
    system("pause");
    return 0;
}

int menu()
{
    int chus;
    printf("\t学生信息\n\n");
    printf("请输入(1 -- 8):\n");
    printf("\t1.创建学生信息\n");
    printf("\t2.显示学生信息\n");
    printf("\t3.查询学生信息\n");
    printf("\t4.修改学生信息\n");
    printf("\t5.添加学生信息\n");
    printf("\t6.删除学生信息\n");
    printf("\t7.排序学生成绩\n");
    printf("\t8.退出\n");
    scanf("%d", &chus);
    return chus;
}

int create(linkList *head)
{
    linkList *s, *p;
    p = head;
    printf("请输入学号 姓名 三科成绩,输入end结束\n");
    while (1)
    {
        s = (linkList *)malloc(sizeof(linkList));
        scanf("%s", s->people.id);
        if (!strcmp(s->people.id, "end"))
        {
            return 0;
        }
        scanf("%s", s->people.name);
        scanf("%d", &s->people.a);
        scanf("%d", &s->people.b);
        scanf("%d", &s->people.c);
        s->people.ava = (s->people.a + s->people.b + s->people.c) / 3;

        s->next = p->next;
        p->next = s;
        p = s;
        Record++;
    }
    return 0;
}

int display(linkList *head)
{
    int i;
    linkList *p;
    p = head;
    p = p->next;
    printf("\t\t\t\t学生信息\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\t\t学号\t\t姓名\t\t\t平均成绩\n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < Record; i++, p = p->next)
    {
        printf("%20s\t", p->people.id);
        printf("%10s\t", p->people.name);
        printf("%20d\n", p->people.ava);
    }

    return 0;
}

int search(linkList *head, char *info)
{
    int i;
    linkList *p;
    p = head;
    p = p->next;
    for (i = 0; i < Record; i++, p = p->next)
    {
        if ((!strcmp(p->people.id, info)) || (!strcmp(info, p->people.name)))
        {
            return i;
        }
    }
    return -1;
}

int modify(linkList *head, char *pid)
{
    int i;
    linkList *p;
    p = head;
    p = p->next;
    for (i = 0; i < search(head, pid); i++)
    {
        p = p->next;
    }
    printf("请输入新信息:\n");
    scanf("%s", p->people.id);
    scanf("%s", p->people.name);
    scanf("%d", &p->people.a);
    scanf("%d", &p->people.b);
    scanf("%d", &p->people.c);
    p->people.ava = (p->people.a + p->people.b + p->people.c) / 3;
    return 0;
}

int add2(linkList *head, char *pid)
{
    int i;
    linkList *p, *s;
    p = head;
    p = p->next;
    s = (linkList *)malloc(sizeof(linkList));
    while (p->next != NULL)
    {
        p = p->next;
    }
    printf("请输入需要添加的姓名和成绩:\n");
    strcpy(s->people.id, pid);
    scanf("%s", s->people.name);
    scanf("%d", &s->people.a);
    scanf("%d", &s->people.b);
    scanf("%d", &s->people.c);
    s->people.ava = (s->people.a + s->people.b + s->people.c) / 3;
    if (search(head, s->people.id) == -1)
    {
        s->next = p->next;
        p->next = s;
        Record++;
    }
    else
    {
        printf("学号重复了\n");
    }
    sort(head, 0);
    return 0;
}

int delt(linkList *head, char *info)
{
    int i, n;
    linkList *p, *s;
    p = head;
    n = search(head, info);
    if (-1 == n)
    {
        printf("没有找到\n");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        p = p->next;
    }
    p->next = p->next->next;
    Record--;
    return 0;
}
int compare(int ava1, int ava2)
{
    if (ava1 < ava2)
    {
        return 1;
    }
    return 0;
}

int sort(linkList *head, int boolean)
{
    linkList *p, *pre;
    pInfo temp;
    if (boolean)
    {
        for (p = head->next; p != NULL; p = p->next)
        {
            for (pre = p->next; pre != NULL; pre = pre->next)
            {
                if (0 == compare(p->people.ava, pre->people.ava))
                {
                    temp = p->people;
                    p->people = pre->people;
                    pre->people = temp;
                }
            }
        }
    }
    else
    {
        for (p = head->next; p != NULL; p = p->next)
        {
            for (pre = p->next; pre != NULL; pre = pre->next)
            {
                if (1 == compare(p->people.ava, pre->people.ava))
                {
                    temp = p->people;
                    p->people = pre->people;
                    pre->people = temp;
                }
            }
        }
    }
    return 0;
}