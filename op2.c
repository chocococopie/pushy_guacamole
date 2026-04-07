/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dishagia <dishagia@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 05:37:04 by dishagia          #+#    #+#             */
/*   Updated: 2026/04/07 05:37:05 by dishagia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
