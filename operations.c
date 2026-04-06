#include "push_swap.h"

void	put_op(const char *op)
{
	int	i;

	i = 0;
	while (op[i])
	{
		write(1, &op[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	sa(t_stack *a)
{
	swap_first_two(a);
	put_op("sa");
}

void	sb(t_stack *b)
{
	swap_first_two(b);
	put_op("sb");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_first_two(a);
	swap_first_two(b);
	put_op("ss");
}

void	pa(t_stack *a, t_stack *b)
{
	push_top(b, a);
	put_op("pa");
}

void	pb(t_stack *a, t_stack *b)
{
	push_top(a, b);
	put_op("pb");
}

void	ra(t_stack *a)
{
	rotate_up(a);
	put_op("ra");
}

void	rb(t_stack *b)
{
	rotate_up(b);
	put_op("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	put_op("rr");
}

void	rra(t_stack *a)
{
	rotate_down(a);
	put_op("rra");
}

void	rrb(t_stack *b)
{
	rotate_down(b);
	put_op("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	put_op("rrr");
}