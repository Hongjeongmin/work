#include <stdio.h>

void Reference(int *p)
{
		printf("%d\n",p);
		//printf("%d\n",*p);
		printf("%d\n",&p);
}

int main(void)
{
	
	int *p;
	int a;
	
	a= 1;
	p = &a;
	
	Reference(p);
}
