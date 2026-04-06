#include "push_swap.h"

// stack_size()

int	stack_size(t_stack *s)
{
	if (!s)
		return (0);
	return (s->size);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->top->index > (*a)->top->next->index)
			sa(*a);
		return ;
	}
	if (size == 3)
	{
		sorting_3(a);
		return ;
	}
	if (size == 4 || size == 5)
	{
		sorting_45(a, b);
		return ;
	}
	radix_sort(a, b);
}

void	sorting_3(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->top->index;
	mid = (*a)->top->next->index;
	bot = (*a)->top->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(*a);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(*a);
		rra(*a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(*a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(*a);
		ra(*a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(*a);
}

static void	push_min_to_b(t_stack **a, t_stack **b, int min_index)
{
	t_node	*cur;
	int		pos;
	int		size;

	cur = (*a)->top;
	pos = 0;
	size = stack_size(*a);
	while (cur && cur->index != min_index)
	{
		cur = cur->next;
		pos++;
	}
	if (pos <= size / 2)
	{
		while ((*a)->top->index != min_index)
			ra(*a);
	}
	else
	{
		while ((*a)->top->index != min_index)
			rra(*a);
	}
	pb(*a, *b);
}

void	sorting_45(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 5)
		push_min_to_b(a, b, 0);
	push_min_to_b(a, b, (size == 5) ? 1 : 0);
	sorting_3(a);
	while (stack_size(*b) > 0)
		pa(*a, *b);
}
