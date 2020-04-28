#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char ch;
    struct Node *lchild, *rchild;
} TreeNode, *BiTree;

void CreateBiTree(BiTree *p)
{
    char ch;
    scanf(" %c",&ch);
    if(ch=='#')
    {
        *p = NULL;
    }
    else
    {
        *p=(BiTree)malloc(sizeof(TreeNode));
        (*p)->ch=ch;
        if(!*p)
        {
            exit(-1);
        }
        printf("please enter the left child of %c\n",(*p)->ch);
        CreateBiTree(&(*p)->lchild);    /** 构造左子树 **/
        printf("please enter the right child of %c\n",(*p)->ch);
        CreateBiTree(&(*p)->rchild);    /** 构造右子树 **/
    }
}

void preOrderTraverse(BiTree p)
{
    if (p!=NULL)
    {
        printf("%c", p->ch);	            //print data of node
        preOrderTraverse(p->lchild);	    //preOrderTraverse lchild
        preOrderTraverse(p->rchild);	    //preOrderTraverse rchild
    }
}

void inOrderTraverse(BiTree p)//中序遍历
{
    if(p!=NULL)
    {
        inOrderTraverse(p->lchild);	    //inOrderTraverse lchild
        printf("%c", p->ch);	        //print data of node
        inOrderTraverse(p->rchild);	    //inOrderTraverse rchild
    }
}

void postOrderTraverse(BiTree p)//后序遍历
{
    if(p!=NULL)
    {
        postOrderTraverse(p->lchild);	    //postOrderTraverse lchild
        postOrderTraverse(p->rchild);	    //postOrderTraverse rchild
        printf("%c", p->ch);	            //print data of node
    }
}

int FindRoot(char const inOrder[],char x,int in_start,int in_end)   /** Entry preOrder and its start and end and data you wanna search */
{
    int i=in_start;
    for(;i<in_end;++i)
    {
        if(inOrder[i]==x)
        {
            return i;
        }
    }
    return i;
}

void BinaryTreeFromOrderings(BiTree *p ,char inOrder[],char preOrder[], int p_start,int p_end, int in_start,int in_end)
{
//// Function：根据前序与中序序列构造二叉树
    int index=0;
    char root;
    if(p_start>p_end)
    {
        return;
    }
    root=preOrder[p_start];
    index = FindRoot(inOrder,root,in_start,in_end);
    (*p)=(BiTree)malloc(sizeof(TreeNode));
    (*p)->ch=root;
    (*p)->lchild=NULL;a
    (*p)->rchild=NULL;
    BinaryTreeFromOrderings(&(*p)->lchild,inOrder,preOrder,p_start+1,p_start+index-in_start,in_start,index-1);
    BinaryTreeFromOrderings(&(*p)->rchild,inOrder,preOrder,p_start+index-in_start+1,p_end,index+1,in_end);
}

int ChildrenSymmetrical(BiTree lchild, BiTree rchild)
{
    if(lchild==NULL && rchild==NULL)
    {
        return 1;
    }
    else if(lchild==NULL || rchild==NULL)
    {
        return 0;
    }
    else
    {
        return ChildrenSymmetrical(lchild->lchild,rchild->rchild) && ChildrenSymmetrical(lchild->rchild,rchild->lchild);
    }
}

int isSymmetrical(BiTree root)            // judge whether a BiTree is symmetrical
{
    if(root==NULL)
    {
        return 1;
    }
    else
    {
        return(ChildrenSymmetrical(root->lchild,root->rchild));
    }
}

void task1()
{
    printf("start task (1) Create Tree in PreOrder\n");
    BiTree bt;
    CreateBiTree(&bt);
    printf("preOrderTraverse\n");                       //result of preOrderTraverse
    preOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");                        //result of inOrderTraverse
    inOrderTraverse(bt);
    printf("\n");
    printf("postOrderTraverse\n");                      //result of postOrderTraverse
    postOrderTraverse(bt);
    printf("\n");
}
void task2_3()
{
    printf("start task (2) Input the preOrder and inOrder Sequence ,Then build the tree\n");
    char pr[100];
    char in[100];
    printf("please input the preorder sequence\n");         /** Entry preOrder */
    scanf("%s",pr);
    getchar();
    printf("please input the inorder seqence\n");          /** Entry inOrder */
    scanf("%s",in);
    getchar();

    BiTree bt;
    BinaryTreeFromOrderings(&bt,in,pr,0,(int)(strlen(pr)-1),0, (int)(strlen(pr)-1));

    printf("preOrderTraverse\n");
    preOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");
    inOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");
    postOrderTraverse(bt);
    printf("\n");
    printf("start task (3):whether the tree is symmetrical?\n");
    if(isSymmetrical(bt)==1)
    {
        printf("It's mirror symmetrical");
    }
    else
    {
        printf("It's not mirror symmetrical");
    }
}

int main()
{
    task1();
    task2_3();
    return 0;
}
