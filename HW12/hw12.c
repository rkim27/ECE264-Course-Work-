// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
void create(ListNode ** head, int i);
void create(ListNode ** head, int i)
{
	ListNode * node = NULL;
	node = malloc(sizeof(ListNode));
	node -> next = (*head);
	node -> value = i;
	(*head) = node;
	
}
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
	int i;
	ListNode * head = NULL;
	head = malloc(sizeof(ListNode));
	head -> value = valn - 1;
	head -> next = NULL;
	for (i = valn-2; i >= 0; i--)
	{
		create(&head, i);
	}
	return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
	int count;
	ListNode * ptr = head;
	do //Ends when all are deleted
	{
		count = 1;
		while (count < valk)
		{
			//count++;
			//if (count == valk)
			//{
				//count = 0;
				//ListNode * p = ptr;
				//ptr = ptr -> next; //seg fault, at end of list it cannot go to next since there is nothing there
				if (ptr->next == NULL) //Reach end of list, start over
				{
					ptr = head;
				}
				else
				{
					ptr = ptr->next;
				}
				count++;
				//head = deleteNode(head, p);
			//}
			//else
			//{				
				//if (ptr->next == NULL) //Reach end of list, start over
				//{
					//ptr = head;
				//}
				//else 
				//{
					//ptr = ptr -> next; //Go to next node if havnt reached the count
				//}
			//}
			
		}
		#ifdef DEBUG
		// this #ifdef ... #endif should be inside the condition *BEFORE* a
		// node' value is printed and it is deleted
		ListNode * todelete = ptr;
		if (head->next != NULL) //Dont print if only 1 node left
		{
		printListNode (todelete); 
		printf("%d\n", todelete->value);
		}
		#endif
		head = deleteNode(head, todelete);
		if (ptr->next == NULL)
		{
			ptr = head;
		}
		else
		{
			ptr= ptr->next;
		}
			
	}while (head->next != NULL);
	printf("%d\n", head->value);
	//#ifdef DEBUG
	// this #ifdef ... #endif should be inside the condition *BEFORE* a
	// node' value is printed and it is deleted
	//ListNode * todelete = p;
	//if (ptr != NULL) //Dont print if only 1 node left
	//{
	//printListNode (todelete); 
	//}
	//#endif

}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
	ListNode * ptr = head;
	ListNode * prev = head;
	if (head == NULL)
	{
		return NULL;
	}
	if (todelete == NULL)
	{
		return head;
	}
	
	while(ptr != todelete)
	{
		prev = ptr;
		if (ptr->next == NULL)
		{
			ptr = head;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	if (ptr->next == NULL)
	{
		prev->next = NULL;
		
	}
	else
	{
		prev->next = ptr->next;
	}
	if (head == todelete)
	{
		free(ptr);
		ptr = prev->next;
		return ptr;
	}
	free(ptr);
	ptr = prev->next;
	return head;
}
#endif


