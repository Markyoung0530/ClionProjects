#include <stdio.h>
#include <stdlib.h>
#include <mach/mach_types.h>
/** Define the data structure used below **/
typedef struct node{
    int performance;                      /** Data field:score of the student **/
    struct node *next;                    /** A pointer to the next node **/
}MyLinkedList;

/** Initialize your data structure here. **/
/** Create a head node with its data field unused and return the head pointer **/
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *p;
    p=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(p == NULL)                            /** If fail to allocate,exit **/
    {
        printf("Fail to allocate");
        exit(-1);
    }
    p->next = NULL;
    return p;
}

/** insert grades in descending order **/
void myLinkedListAdd(MyLinkedList* obj, int performance) {
    MyLinkedList *p=obj,*L;
    L=myLinkedListCreate();                     /** Create a new node **/
    L->performance=performance;
    while(p->next!=NULL)                        /** p keeps going on until it reach the end **/
    {
        if (performance>=p->next->performance)  /** performance is between p and its next
                                                 * insert L after p then **/
        {
            L->next=p->next;
            p->next=L;
            break;
        }
        p=p->next;
    }
    if(p->next==NULL)
    {
        p->next=L;
    }
}

/** search the score in the position of index **/
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *pr=obj->next;
    int i;
    if(index<=0)                              /** If index is invalid,exit and return -1 **/
    {
        return -1;
    }
    for(i=1;i<index;)                         /** Pointer pr and i keep going on when i is less than the index **/
    {
        pr=pr->next;
        i++;
        if(pr->next==NULL && i<index)         /** If i exceed the list **/
        {
           return -1;
        }
    }
    return pr->performance;
}

/** 删除第index个学生 */
void myLinkedListDelete(MyLinkedList* obj, int index) {
    MyLinkedList *pr=obj->next,*pt=pr->next;
    int i=2;
    if(index<=0)                               /** index is invalid **/
    {
        exit(-1);
    }
    if(obj->next==NULL)                        /** If it get a blank list **/
    {
        exit(-2);
    }
    else if(pr->next==NULL)                    /** If it get only 1 node,just delete it **/
    {
        if(index==1)
        {
            obj->next=NULL;
            free(obj->next);
        }
        else
        {
            exit(-1);
        }
    }
    else                                        /** If it get nodes **/
    {
        if(index==1)
        {
            obj->next=pt;
        }
        else
        {
            while(i<index && pt->next!=NULL)    /** pt,pr and i keep going on
                                                * until i catch up index or pt has reached the end **/
            {
                pt=pt->next;
                pr=pr->next;
                i++;
            }
            pr->next=pt->next;                  /** Ignore the node pt pointed to **/
            free(pt);
        }
    }
}

/** 输出该班级的成绩 */
void myLinkedListOutput(MyLinkedList* obj) {
    MyLinkedList *pr=obj->next;
        while( pr!=NULL )                     /** print the performance and pr keeps going on when pr isn't NULL **/
        {
            printf("%d\n",pr->performance);
            pr=pr->next;
        }
        printf("\n");
}


/** 将所有班级的成绩合并降序输出 */
void merge(MyLinkedList* obj[]) {
    MyLinkedList *pr=obj[0]->next,*L=NULL;
    L=myLinkedListCreate();                   /** Create a new list to store the information of all 3 class **/
    while(pr!=NULL)                           /** pr visit every node of this list **/
    {
        myLinkedListAdd(L,pr->performance);   /** every performance is inserted into a new list
                                               * trough Function Insert **/
        pr=pr->next;
    }

    pr=obj[1]->next;
    while(pr!=NULL)
    {
        myLinkedListAdd(L,pr->performance);
        pr=pr->next;
    }

    pr=obj[2]->next;
    while(pr!=NULL)
    {
        myLinkedListAdd(L,pr->performance);
        pr=pr->next;
    }
    myLinkedListOutput(L);                     /** Output entire ordered list that combines all 3 lists **/
}


int main()
{
    MyLinkedList *obj[3];
    obj[0]=myLinkedListCreate();
    obj[1]=myLinkedListCreate();
    obj[2]=myLinkedListCreate();
    while (1)
    {
        printf("1.insert 2.delete 3.search 4.output 5.merge\n");
        int op;
        scanf("%d", &op);
        int class;
        int index;
        int performance;
        switch (op)
        {
            case 1:
                do {                          /** Data form check **/
                    printf("input class\n");
                    scanf("%d", &class);
                    getchar();
                } while (class > 3 || class <= 0);
                do {
                    printf("input performance\n");
                    scanf("%d", &performance);
                    getchar();
                } while (performance < 0 || performance >= 100);
                myLinkedListAdd(obj[class - 1], performance);
                break;

            case 2:
                do {                          /** Data form check **/
                    printf("input class\n");
                    scanf("%d", &class);
                    getchar();
                } while (class > 3 || class <= 0);
                do {
                    printf("input index\n");
                    scanf("%d", &index);
                    getchar();
                } while (index<0);
                    myLinkedListDelete(obj[class - 1], index);
                    break;
            case 3:
                do {                          /** Data form check **/
                    printf("input class\n");
                    scanf("%d", &class);
                    getchar();
                } while (class > 3 || class <= 0);
                do {
                    printf("input index\n");
                    scanf("%d", &index);
                    getchar();
                } while (index<0);
                printf("%d\n", myLinkedListGet(obj[class - 1], index));
                break;
            case 4:
                myLinkedListOutput(obj[0]);
                myLinkedListOutput(obj[1]);
                myLinkedListOutput(obj[2]);
                break;
            case 5:
                merge(obj);
                break;
            default:
                return 0;
        }
    }
}
