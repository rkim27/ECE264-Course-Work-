// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
	memcpy(leftDeck -> cards, origDeck.cards, leftDeck -> size);
	memcpy(rightDeck -> cards, &origDeck.cards[leftDeck -> size], rightDeck -> size);
}
#endif

#ifdef TEST_INTERLEAVE
void kelp(CardDeck leftDeck, CardDeck rightDeck, CardDeck deck, int lind, int Rind);

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.
void kelp(CardDeck leftDeck, CardDeck rightDeck, CardDeck deck, int lind, int Rind)
{ 
	//print left card
	int ind = lind + Rind;
	if (lind < leftDeck.size)
	{
		deck.cards[ind] = leftDeck.cards[lind];
	//call helper with one less left card (lind + 1)
		kelp(leftDeck, rightDeck, deck, lind + 1, Rind);
	}
	if (Rind < rightDeck.size)
	{
		deck.cards[ind] = rightDeck.cards[Rind];
		kelp(leftDeck, rightDeck, deck, lind, Rind + 1);
	}
	if (ind == (deck.size - 1))
	{
	printDeck(deck);
	}
	
	//print right card
	//call interleave wiht one less right card (rind + 1)
	
}
void interleave(CardDeck leftDeck, CardDeck rightDeck)
{ //Have a string to print order into, have two sets recursive structures that start at either left or right 
	//int pos = ((n+m)!)/(n! m!); //convert to c
	CardDeck deck;
	deck.size = leftDeck.size + rightDeck.size;
	
	kelp(leftDeck, rightDeck, deck, 0, 0);
	//print order
}
#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
{
	int pos = origDeck.size - 1;
	int i;
	for(i =1; i <= pos; i++)
	{
	CardDeck * leftDeck= malloc(sizeof(CardDeck));
	CardDeck * rightDeck = malloc(sizeof(CardDeck));
	leftDeck -> size = i;
	rightDeck -> size = origDeck.size - i;
	
	
	
	
	divide(origDeck, leftDeck, rightDeck);
	
	interleave(*leftDeck, *rightDeck);
	
	
	
	
	free(leftDeck);
	free(rightDeck);
	}
}
#endif
