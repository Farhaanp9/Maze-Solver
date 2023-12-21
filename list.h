

# ifndef LIST_H
# define LIST_H

typedef struct list LIST;

extern LIST *createList(void);

extern void destroyList(LIST *lp);

extern int numItems(LIST *lp);

extern void addFirst(LIST *lp, void *item);

extern void addLast(LIST *lp, void *item);

extern void *removeFirst(LIST *lp);

extern void *removeLast(LIST *lp);

extern void *getFirst(LIST *lp);

extern void *getLast(LIST *lp);

extern void *getItem(LIST *lp, int index);

extern void setItem(LIST *lp, int index, void *item);

# endif /* LIST_H */
