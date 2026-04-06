#include "push_swap.h"

int	*copy_array(t_stack *s)
{
	int		*arr;
	int		i;
	t_node	*cur;

	i = 0;
	arr = malloc(sizeof(int) * s->size);
	if (!arr)
		error_return();
	cur = s->top;
	while (i < s->size)
	{
		arr[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (arr);
}

void	bubble_sort(int *arr, int size)
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

int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] != value)
			i++;
		else
			return (i);
	}
	return (-1);
}

void	assign_index_to_nodes(t_stack *s, int *sorted_arr)
{
	t_node *cur;
	int i;

	cur = s->top;
	while (cur)
	{
		i = find_index(sorted_arr, s->size, cur->value);
		cur->index = i;
		cur = cur->next;
	}
}

void	assign_indexes(t_stack *s)
{
	int	*values;
	int	size;

	size = s->size;
	values = copy_array(s);
	bubble_sort(values, size);
    assign_index_to_nodes(s, values);
    free(values);
}

