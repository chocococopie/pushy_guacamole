#include "push_swap.h"

// sort_stack()

int	stack_size(t_stack *s)
{
	if (s)
		return (s->size);
	return (0);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
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
	// 6+ nodes:
	radix_sort(a, b);
}

void	sorting_3(t_stack **a)
{
	if ((*a)->top->index > (*a)->top->next->index
		&& (*a)->top->next->index > (*a)->top->next->next->index)
	{
		sa(*a);
		rra(*a);
	}
	else if ((*a)->top->index > (*a)->top->next->index)
		sa(*a);
	else if ((*a)->top->next->index > (*a)->top->next->next->index)
	{
		if ((*a)->top->index > (*a)->top->next->next->index)
		{
			sa(*a);
			ra(*a);
		}
		else
			ra(*a);
	}
}

// 4–5 nodes: move smallest values to b until 3 remain in a:

void	sorting_45(t_stack **a, t_stack **b)
{
	// Push elements from a to b until a has 3 elements
	while (stack_size(*a) > 3)
		pb(*a, *b);
	// Now sort the 3 remaining nodes in a
	sort_stack(a, b);
	// Push back all from b into a
	while (stack_size(*b) > 0)
		pa(*a, *b);
	// Rotate a so the node with index 0 (smallest) is on top
	while ((*a)->top->index != 0)
		rra(*a);
}