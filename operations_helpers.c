#include "push_swap.h"

void	swap_first_two(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->top = second;
}

void	push_top(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (!src || !dst || src->size == 0)
		return ;
	node = src->top;
	src->top = node->next;
	src->size--;
	node->next = dst->top;
	dst->top = node;
	dst->size++;
}

void	rotate_up(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	s->top = first->next;
	first->next = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rotate_down(t_stack *s)
{
	t_node *prev;
	t_node *last;

	if (!s || s->size < 2)
		return ;
	prev = NULL;
	last = s->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = s->top;
	s->top = last;
}
