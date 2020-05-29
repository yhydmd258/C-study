
#include <iostream>
//#include "string.h"
#include <string.h>
using namespace std;

struct teacher
{
	int id;
	char name[64];
};

int get_mem(struct teacher** tpp)
{
	struct teacher *tp = NULL;
	tp = (struct teacher*)malloc(sizeof(struct teacher));
	if (tp == NULL)
	{
		return -1;
	}
	tp->id = 100;
	strcpy(tp->name, "li4");
	*tpp = tp;
	return 0;
}
void free_teacher(struct teacher **tpp)
{
	if (tpp == NULL)
	{
		return;
	}
	if (*tpp != NULL)
	{
		free(*tpp);
		*tpp = NULL;
	}	
}
void free_teacher(struct teacher * &tpp)
{
	if (tpp != NULL)
	{ 
		free(tpp);
		tpp = NULL;
	}
}
int get_mem2(struct teacher* &p)
{
	struct teacher *tp = NULL;
	tp = (struct teacher*)malloc(sizeof(struct teacher));
	if (tp == NULL)
	{
		return -1;
	}
	tp->id = 100;
	strcpy(tp->name, "li4");
	p = tp;
	return 0;
}
int main(void)
{
	struct teacher *tp = NULL;
	get_mem2(tp);
	
	cout << tp->id << tp->name << endl;
	free(tp);
	return 0;
}