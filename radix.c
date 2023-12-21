
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "list.h"

# define r 10


int main(void)
{
    int i, x, niter, div, max, *p;
    LIST *a, *lists[r];


    max = 0;
    a = createList();

    for (i = 0; i < r; i ++)
	lists[i] = createList();


    //Read in the numbers and record the maximum as we go along. 

    while (scanf("%d", &x) == 1) {
	if (x >= 0) {
	    p = malloc(sizeof(int));
	    assert(p != NULL);
	    *p = x;

	    addLast(a, p);

	    if (x > max)
		max = x;

	} else {
	    fprintf(stderr, "Sorry, only non-negative values allowed.\n");
	    exit(EXIT_FAILURE);
	}
    }

    div = 1;
    niter = ceil(log(max + 1) / log(r));

    while (niter --) {


	//Move the numbers from the list to the buckets. 

	while (numItems(a) > 0) {
	    p = removeFirst(a);
	    addLast(lists[*p / div % r], p);
	}


	// Move the numbers from the buckets back into the list. 

	for (i = 0; i < r; i ++)
	    while (numItems(lists[i]) > 0)
		addLast(a, removeFirst(lists[i]));

	div = div * r;
    }


    // Print out the numbers.

    while (numItems(a) > 0) {
	p = removeFirst(a);
	printf("%d\n", *p);
	free(p);
    }

    exit(EXIT_SUCCESS);
}
