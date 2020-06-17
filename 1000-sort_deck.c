#include "deck.h"
/**
* swap_cards - function that swaps node if necessary
* @deck: pointer to deck of cards
* @node: pointer to specific card
*
*/
void swap_cards(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}
/**
* get_card_value - function that swaps node if necessary
* @s: pointer to deck of cards
*Return: value
*/
int get_card_value(const char *s)
{
	switch (s[0])
	{
	case 'A':
		return (1);
	case '2':
		return (2);
	case '3':
		return (3);
	case '4':
		return (4);
	case '5':
		return (5);
	case '6':
		return (6);
	case '7':
		return (7);
	case '8':
		return (8);
	case '9':
		return (9);
	case '1':
		return (10);
	case 'J':
		return (11);
	case 'Q':
		return (12);
	case 'K':
		return (13);
	}
	return (0);
}
/**
* sort_deck - function that swaps node if necessary
* @deck: pointer to deck of cards
*
*/
void sort_deck(deck_node_t **deck)
{
	char swapped = 1, card, next, previous;
	deck_node_t *c;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	c = *deck;
	while (swapped != 0)
	{
		swapped = 0;
		while (c->next)
		{
			card = get_card_value(c->card->value) + 20 * c->card->kind;
			next = get_card_value(c->next->card->value) + 20 * c->next->card->kind;
			if (card > next)
			{
				swap_cards(deck, c);
			}
			if (card < next)
				c = c->next;
		}
		while (c->prev)
		{
			card = get_card_value(c->card->value) + 20 * c->card->kind;
			previous = get_card_value(c->prev->card->value) + 20 * c->prev->card->kind;
			if (card < previous)
			{
				swap_cards(deck, c->prev);
				swapped = 1;
			}
			if (card > previous)
				c = c->prev;
		}
	}
}
