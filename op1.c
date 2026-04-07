/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dishagia <dishagia@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 05:37:09 by dishagia          #+#    #+#             */
/*   Updated: 2026/04/07 05:37:10 by dishagia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
