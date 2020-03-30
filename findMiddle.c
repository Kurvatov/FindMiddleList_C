/*
	Author: Stéphane Mesquita Monteiro
	Student Number: 16842
*/

#include <stdio.h>
#include <stdlib.h>

/*Single Structure do store info in the node*/
typedef struct Info
{
	int test;
}INFO;
/*Structure of the node*/
typedef struct no
{
	INFO *info; //Pointer to previous structure INFO
	struct no *next; //node that points to next element in the list
}NO;
/*Structure of the List*/
typedef struct list
{
	NO *begin; //NOde that points that represents the beggining of the list
	int NEL; //Number of elements of the list, in this exercise is useless
}LIST;

/*Allocate memory for the lsir*/
LIST *CreateList()
{
	LIST *ls = (LIST *)malloc(sizeof(LIST));
	if (!ls) return NULL;
	/*Initialization of the list*/
	ls->begin = NULL;
	ls->NEL = 0;
	return ls;
}
/*Allocate memory to store the info*/
INFO *CreateInfo(int an)
{
	INFO *X = (INFO *)malloc(sizeof(INFO));
	X->test = an; //add info to the structure
	return X;
}
void AddBegin(LIST *L, INFO *X)
{
	if (!L) return;
	NO *node = (NO *)malloc(sizeof(NO));
	/*Creation of the node*/
	node->info = X;
	node->next = L->begin;
	
	L->begin = node; //Add node to the list
	L->NEL++; //Increment number of elements
}


NO *ReturnMiddle(LIST *L)
{
	/*Creation of two nodes*/
    NO *slowNode = L->begin;  
    NO *fastNode = L->begin;  

	/*If list not empty then search*/
    if (L->begin!=NULL)  
    {  
		/*LOGIC:
		
		With the use of two pointers we can reach the middle node with only one loop.
		The fast node jumps to nodes in each interaction while the jump node only jumps one.
		When the fast node reaches the end the slow node is exactly and the middle of the list beacause fast node does twice the jumps of the slow node  
		

		*/
        while (fastNode != NULL && fastNode->next != NULL)  
        {  
            fastNode = fastNode->next->next; /* jumps twice */
            slowNode = slowNode->next;  /* jumps once */
        }  
        return slowNode;  /*when fast node reaches the end of the list it returns the slow node (middle node)*/
    }  
}


int main(){
    LIST *LV = CreateList();
    INFO *X;
	for (int i = 0; i < 3; i++)
	{
		X = CreateInfo(i);
		AddBegin(LV, X);
	}
    NO *aux = ReturnMiddle(LV);
    printf("The middle value is %d",aux->info->test);
    return 0;
}
