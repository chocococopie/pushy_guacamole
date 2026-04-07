/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dishagia <dishagia@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 05:11:57 by dishagia          #+#    #+#             */
/*   Updated: 2026/04/07 19:28:36 by dishagia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_return(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a)
	{
		while (a->top)
		{
			tmp = a->top;
			a->top = a->top->next;
			free(tmp);
		}
		free(a);
	}
	if (b)
	{
		while (b->top)
		{
			tmp = b->top;
			b->top = b->top->next;
			free(tmp);
		}
		free(b);
	}
}
