#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (i != 0)
			printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
