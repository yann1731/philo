#include "philosopher.h"

void	checkargsnum(int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(STDERR_FILENO, "Not the right number of arguments", 33);
		exit(1);
	}
}
