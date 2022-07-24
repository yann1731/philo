#include "philosopher.h"

int	checkintlimit(t_args *args, char *argv[])
{
	if (ft_atoi(argv[1]) > INT_MAX || ft_atoi(argv[2]) > INT_MAX
		|| ft_atoi(argv[3]) > INT_MAX || ft_atoi(argv[4]) > INT_MAX || ft_atoi(argv[5]) > INT_MAX)
	{
		dprintf(STDERR_FILENO, "Argument needs to be lower than %d\n", INT_MAX);
		return (1);
	}
}