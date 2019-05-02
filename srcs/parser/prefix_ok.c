#include "parser.h"

int		prefix_ok(const char *s1, char **cmp)
{
	int		i;

	i = 0;
	while (cmp[i])
	{
		if (compare_prefix(s1, cmp[i]) == 1)
			return (i);
		i++;
	}
	return (-1);
}
