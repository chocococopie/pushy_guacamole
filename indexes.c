/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dishagia <dishagia@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 05:12:05 by dishagia          #+#    #+#             */
/*   Updated: 2026/04/07 05:12:06 by dishagia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_array(t_stack *s)
{
	int		*arr;
	int		i;
	t_node	*cur;

	if (!s || s->size == 0)
		return (NULL);
	arr = malloc(sizeof(int) * s->size);
	if (!arr)
		return (NULL);
	cur = s->top;
	i = 0;
	while (i < s->size)
	{
		arr[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (arr);
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	assign_index_to_nodes(t_stack *s, int *sorted_arr)
{
	t_node	*cur;

	cur = s->top;
	while (cur)
	{
		cur->index = find_index(sorted_arr, s->size, cur->value);
		cur = cur->next;
	}
}

int	assign_indexes(t_stack *s)
{
	int	*values;

	if (!s || s->size == 0)
		return (1);
	values = copy_array(s);
	if (!values)
		return (0);
	bubble_sort(values, s->size);
	assign_index_to_nodes(s, values);
	free(values);
	return (1);
}
