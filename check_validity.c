#include "philosopher.h"

void	check_validity(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (argv[++i])
	{
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(2, "Must enter only positive numbers as arguments!", 46);
				exit(1);
			}
		}
		j = -1;
	}
}
