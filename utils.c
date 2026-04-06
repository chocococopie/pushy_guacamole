#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int		is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}