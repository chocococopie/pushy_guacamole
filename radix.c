#include "push_swap.h"

static int	get_max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < n)
		bits++;
	return (bits);
}

static void	process_bit_pass(t_stack **a, t_stack **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		// If the current bit is 0, push to b
		if ((((*a)->top->index >> bit) & 1) == 0)
			pb(*a, *b);
		// If the bit is 1, rotate a
		else
			ra(*a);
		i++;
	}
	// Move all from b back to a
	while (stack_size(*b) > 0)
		pa(*a, *b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int size;
	int max_bits;
	int bit;

	if (!a || !*a || !(*a)->top || is_sorted(*a))
		return ;
	size = stack_size(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit_pass(a, b, bit, size);
		bit++;
	}
}