#include "deck.h"

/**
 * sort_deck - Sort a deck of cards
 *
 * @deck: a pointer to the head of a deck_node_t doubly-linked list
 *
 * Return: nothing
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
}
