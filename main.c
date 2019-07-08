#include <stdio.h>
int main()
{
	int x = 55;
	int *y = &x;
	printf("Location of x is%p\n",y);
    printf("Value of x is: %d\n",*y);
	return 0;
}