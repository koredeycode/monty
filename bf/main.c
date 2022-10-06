#include <stdio.h>

void main(void)
{
	char s[] = "School";
	int i = 0;

	for (; s[i]; i++)
		printf("%d-", s[i]);
}
