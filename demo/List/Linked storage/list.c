#include"list.h"

list* initList(void) {
	list* head = malloc(sizeof(list));
	head->coeff = 0;
	head->term = 0;
	head->next = NULL;
	return head;
}
void insertList(list* l, listItem* item,...) {
	if (l == NULL) {
		perror("Error,list is none");
		return -1;
	}
	va_list arg;
	va_start(arg, item);
	if (arg != NULL) {
		int temLocation = va_arg(arg, int);
		if (temLocation > lengthList(l)) {
			perror("Over list");
			exit(1);
		}
		else if (temLocation < 0) {
			perror("Wrong input");
			return -1;
		}
		else{
			for (int i = 0; i < temLocation; ++i) {
				l = l->next;
			}
			listItem* tem_item = l->next;
			l->next = item;
			item->next = tem_item;
		}
		
	}
	else{
		l->next = item;
		l->next->next = NULL;
	}
	va_end(arg);
	
}
void insertInt(list* L, int location,int term, int coeff) {
	if (L->next == NULL || L == NULL)return;
	if (location < 0) {
		printf("Invalid number");
	}
	if (location == 0);
	else{
		for (int i = 0; i < location; ++i) {
			L = L->next;
		}
	}
	list* tem = malloc(sizeof(list));
	tem->coeff = coeff;
	tem->term = term;
	tem->next = L->next;
	L->next = tem;
}
void destroyList(list* l) {
	if (l == NULL)return -1;
	list* tem;
	while (l->next != NULL) {
		tem = l;
		l = l->next;
		free(tem);
	}
		 
}

void clearList(list* l) {
	if (l == NULL)return -1;
	while (l->next != NULL) {
		l->next->coeff = 0;
		l = l->next;
	}
}

int listEmpty(const list* l) {
	if (l == NULL) { perror("Wrong"); return -1; }
	if (l->next == NULL)
		return 1;
	else return 0;
}
int lengthList(const list*l) {
	if (l == NULL) return 0;
	int count=0;
	while (l->next!=NULL) {
		l = l->next;
		count++;
	}
	return count;
}

listItem getElem(const list* l, int location) {
	if (l == NULL) { perror("Wrong,List is NULL"); return; }
	for (int i = 0; i < location; ++i) {
		l = l->next;
	}
	return *l;
}

int my_compare(const list* l, listItem item) {
	if (l == NULL) return -1;
	l = l->next;
	while(l!=NULL){
		if (l->coeff == item.coeff && l->term == item.term) return 1;
	}
	return 0;
}

int locateList(const list* l, listItem value, int(*compare)(list*, listItem)) {
	if (l == NULL) { perror("Wrong"); return -1; }
	return compare(l, value);
}

listItem preListItem(const list* l, listItem value) {
	if (l == NULL) { perror("Wrong"); return; }
	listItem pre = *l->next;
	l = pre.next;
	while (l != NULL) {
		if (value.coeff == l->coeff && value.term == l->term)
			return pre;
		l = l->next;
		pre = *pre.next;
	}
}

listItem nextListItem(const list* l, listItem value) {
	if (l == NULL) return;
	l = l->next;
	while (l != NULL) {
		if (l->next->coeff == value.coeff && l->next->term == value.term)
			return *l->next;
		l = l->next;
	}
	printf("Can't find the item");
}

void listItemDelete(list* l, int value) {
	if (l == NULL) {
		perror("Wrong,list is null");
		return -1;
	}
	l = l->next;
	while (l != NULL) {

	}
}
list* reverseList(list* L) {
	if (L == NULL || L->next == NULL)return L;
	list* beg = L, *end = L->next;
	while (end != NULL) {
		beg->next = end->next;
		end->next = beg;
		L = end->next;
		beg = end;
		end = beg;
	}
}
