#include "../main.h"

int main()
{
	format fro;
	finit(&fro);
	printf("zero: %d\n", fro.zero);
	printf("plus: %d\n", fro.plus);
	printf("minus: %d\n", fro.minus);
	printf("space: %d\n", fro.space);
	printf("width: %d\n", fro.width);
	printf("per: %d\n", fro.per);
	return 0;
}
