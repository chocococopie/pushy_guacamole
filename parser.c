#include "push_swap.h"

int	fill_stack(t_stack *a, char **argv, int count)
{
	int		i;
	long	nb;
	t_node	*node;

	i = 0;
	while (i < count)
	{
		if (!argv[i] || !is_numeric(argv[i]))
			return (0);
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
		if (exists_in_stack(a, (int)nb))
			return (0);
		node = new_node((int)nb);
		if (!node)
			return (0);
		add_back(a, node);
		a->size++;
		i++;
	}
	assign_indexes(a);
	return (1);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack *a, t_node *node)
{
	t_node	*cur;

	if (!a || !node)
		return ;
	if (!a->top)
	{
		a->top = node;
		return ;
	}
	cur = a->top;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
}

int	exists_in_stack(t_stack *a, int value)
{
	t_node	*cur;

	if (!a)
		return (0);
	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long res;
	int sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}