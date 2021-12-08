#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)

{
	int	hash[255];
	int	i;
	int	j;

	i = 0;
	while (hash[i])
		hash[i++] = 0;
	if (ac == 3)
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			while (av[1][j])
			{
				if (hash[(unsigned int)av[1][j]] == 0)
				{
					hash[(unsigned int)av[1][j]] = 1;
					write(1, &av[i][j], 1);
					hash[(unsigned int)av[1][j]] = 2;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}