#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value) {
	skiplist_t *c = list;
	char *text1 = "Value checked at index [%lu] = [%d]\n";
	char *text2 = "Value found between indexes [%lu] and [%lu]\n";

	while (c) {
		if (c->express)
		{
			printf(text1, c->express->index, c->express->n);
			if (c->express->n < value)
			{
				c = c->express;
				continue;
			}
			printf(text2, c->index, c->express->index);
		}
		printf(text1, c->index, c->n);
		if (c->next) {
			if (c->next->n <= value)
			{
				c = c->next;
				continue;
			}
		}
		if (c->n == value)
			return (c);
		c = c->express;
	}
	return (NULL);
}
