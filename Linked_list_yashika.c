#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include<math.h>

typedef struct nodetype{
int info;
struct  nodetype *next;
}node;
//1
void insertatbeg(node **start ,int item)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=*start;
	*start=ptr;
}
//2
void insertatend(node**start,int item)
{
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if (*start==NULL)
	  *start=ptr;
	else 
	{
		last=*start;
		while(last->next!=NULL)
		  last=last->next;
		last->next=ptr;
	}	
}
//3
void deleteatbeg(node**start)
{
	node *ptr;
	if(*start==NULL)
	{
		printf("\n LL is empty");
		return;
	}
	ptr=*start;
	*start=ptr->next;
	printf("\n deleted value= %d",ptr->info);
	free(ptr);
}
//4
void deleteatend(node **start)
{
	node *ptr,*last;
	if(*start=NULL)
	{
		printf("\n LL is empty");
		return;
	}
	if((*start)->next==NULL)
	{
		ptr=*start;
		*start=ptr->next;
	}
	else
	{
		last=*start;
		while(last->next->next!=NULL)
		ptr=last->next;
		last->next=NULL;
	}
	printf("\n deleted value=%d",ptr->info);
	free(ptr);
}
//5
void display(node *start)
{
	if(start==NULL)
	{
		printf("\n LL is empty");
		return;
	}
	while(start!=NULL)
	{
		printf("%d ->",start->info);
		start=start->next;
	}
}
//6
void displayinrev(node *start)
{
	if(start->next!=NULL)
	{
		displayinrev(start->next);
		printf("%d ->",start->info);
	}
}
														


int main()
{
int item,choice;
node *head;
head=NULL;//create an EMPTY LINKED LIST
while(1)
{
	printf("\n.....LL  menu....\n");
	printf("\n 1 insertatbeg");
	printf("\n 2 insertatend");
	printf("\n 3 deleteatbeg");
	printf("\n 4 deleteatend");
	printf("\n 5 displayinorder");
	printf("\n 6 displayinreverse");
	printf("\n 7 EXIT");
	printf("\n Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:printf("\n Enter an item=");
			scanf("%d",&item);
			insertatbeg(&head,item);
			break;
			case 2:printf("\n Enter an item=");
			scanf("%d",&item);
			insertatend(&head,item);
			break;
			case 3:
			deleteatbeg(&head);
			break;
			case 4: deleteatend(&head);
			break;
			case 5:display(head);
			break;
			case 6:displayinrev(head);
			break;
			default:exit(1);
		}//SWITCH CLOSE
      }//WHILE CLOSE
   }//MAIN CLOSE

