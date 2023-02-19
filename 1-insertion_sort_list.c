#include "sort.h"

/**
 * insertion_sort_list - a function that performs an insertion sort
 * @list: the list the sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new, *sorted, *temp;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	new = (*list)->next;
	while (new != NULL)
	{
		temp = new->next;
		sorted = new->prev;
		while (sorted && new->n < sorted->n)
		{
			sorted->next = new->next;

			if (new->next != NULL)
				new->next->prev = sorted;

			new->prev = sorted->prev;

			new->next = sorted;
			if (sorted->prev != NULL)
				sorted->prev->next = new;
			else
				*list = new;

			sorted->prev = new;

			sorted = new->prev;
			print_list(*list);
		}
		new = temp;
	}
}
