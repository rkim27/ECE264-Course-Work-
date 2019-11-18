// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
TreeNode * build(int in[], int post[], int start, int end, int *pIndex);
TreeNode * new(int value);
int find(int a[], int start, int end, int value);

Tree * buildTree(int * inArray, int * postArray, int size)
{
	int pIndex = size - 1;
	TreeNode * no = build(inArray, postArray, 0, size - 1, &pIndex);
	Tree * trees = malloc(sizeof(Tree));
	trees->root = no;
	return trees;
}

TreeNode * build(int in[], int post[], int start, int end, int *pIndex)
{
	if (start > end)
	{
		return NULL;
	}
	TreeNode * node = new(post[*pIndex]); //Last number of post print is root
	(*pIndex)--;
	
	if (start == end) //No children?
	{
		return node;
	}
	int iInd = find(in, start, end, node->value); //Find inex of this node in inorder print
	node -> right = build(in, post, iInd +1, end, pIndex);
	node -> left = build(in, post, start, iInd -1, pIndex);
	return node;
}
TreeNode * new(int value)
{
	TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
	node -> value = value;
	node -> left = NULL;
	node -> right = NULL;
	return(node);
}
int find(int a[], int start, int end, int value)
{
	int i;
	for (i = start; i<= end; i++)
	{
		if (a[i] == value)
			break;
	}
	return i;
}
#endif

#ifdef TEST_PRINTPATH
void printPath(Tree * tr, int val)
{
	int arr[3] = {0};
	int i = 0;
	int it;
	TreeNode * tn = tr->root;
	do
	{
		arr[i] = tn->value;
		tn = tn->left;
		i++;
	}while(tn->left != NULL);
	
	arr[i] = tn->value;
	
	for (it = i; it >= 0; it--)
	{
		
		printf("%d\n", arr[it]);
	}
	return;
}
#endif
