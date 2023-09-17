#include <stdio.h>
#include "main.h"

int main(void)
{
	char *a = "A %% \\character.\n";

	_printf("%s\n", a);
	return (0);
}
