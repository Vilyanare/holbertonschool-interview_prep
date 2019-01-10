#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value) {
	skiplist_t *current = list;

	while (current) {
		if (current->express) {
			printf("Value checked at index [%lu] = [%d]\n", current->express->index, current->express->n);
			if (current->express->n <= value) {
				current = current->express;
				continue;
			}
			printf("Value found between indexes [%lu] and [%lu]\n", current->index, current->express->index);
		}
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->next) {
			if (current->next->n <= value) {
				current = current->next;
				continue;
			}
		}
		if (current->n == value)
			return (current);
		current = current->express;
	}
	return (NULL);
}
