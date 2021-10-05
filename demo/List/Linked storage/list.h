#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>
/*
* List线性表
* 链式存储
* 有链表头指针
*/

struct List{
	int term;
	int coeff;
	struct List* next;
};

typedef struct List list;
typedef struct List listItem;

list* initList(void);
void insertList(list* l, listItem* item,...);
void destroyList(list* l);
void clearList(list* l);
int listEmpty(const list* l);
int lengthList(const list* l);
listItem getElem(const list* l, int location);
int locateList(list* l, listItem value,int(*compare)(list*,listItem));
listItem preListItem(list* l, listItem value);
list* reverseList(list* L); 
