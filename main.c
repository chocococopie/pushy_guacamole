#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!init_stacks(&a, &b))
		return (error_return());
	if (!handle_args(argc, argv, a))
		return (free_stacks(a, b), error_return());
	if (is_sorted(a))
		return (free_stacks(a, b), 0);
	if (stack_size(a) > 1)
		sort_stack(&a, &b);
	free_stacks(a, b);
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || !a->top)
		return (1);
	cur = a->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// error_return() +
// sort_stack()
// free_stacks() +

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	if (!*a)
	{
		// return error ↓
		return (0);
	}
	*b = malloc(sizeof(t_stack));
	if (!*b)
	{
		free(*a);
		// return error ↓
		return (0);
	}
	(*a)->top = NULL;
	(*a)->size = 0;
	(*b)->top = NULL;
	(*b)->size = 0;
	return (1);
}

int	handle_args(int argc, char **argv, t_stack *a)
{
	char **args;
	int count;
	int i;

	args = NULL;
	count = 0;
	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);

		// instead of count_args() ↓
		while (args[count])
			count++;
		if (!fill_stack(a, args, count))
			return (free_split(args), 0);
		free_split(args);
		return (1);
	}
	while (argv[i + 1])
		i++;
	if (!fill_stack(a, argv + 1, i))
		return (0);
	return (1);
}