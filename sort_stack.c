/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:19:17 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/27 16:51:54 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (s->stack[i] > s->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	stack_of_three(t_stack *s)
{
	if (s->stack[0] > s->stack[1] && s->stack[0] < s->stack[2])
		swap(s);
	else if (s->stack[0] > s->stack[1] && s->stack[1] > s->stack[2])
	{
		swap(s);
		r_rotate(s);
	}
	else if (s->stack[0] > s->stack[1] && s->stack[1] < s->stack[2])
		rotate(s);
	else if (s->stack[0] < s->stack[1] && s->stack[1] > s->stack[2])
	{
		if (s->stack[0] > s->stack[2])
			r_rotate(s);
		else if (s->stack[0] < s->stack[2])
		{
			swap(s);
			rotate(s);
		}
	}
}

void	stack_of_five(t_arrays *a)
{
	int	i;
	int	len;

	i = 0;
	len = a->a->size;
	while (a->a->size != 3)
	{
		if (a->a->stack[i] < a->a->average)
			push_b(a->a, a->b);
		else
			rotate(a->a);
	}
	stack_of_three(a->a);
	less_then_three_b(a->b);
	while (a->a->size != len)
		push_a(a->a, a->b);
}

void	sort_stack(t_arrays *a)
{
	a->a->average = get_average(a->a->stack, a->a->size);
	if (is_stack_sorted(a->a))
		return ;
	if (a->a->size < 3)
		less_then_three_a(a->a);
	if (a->a->size == 3)
		stack_of_three(a->a);
	if (a->a->size == 4 || a->a->size == 5)
		stack_of_five(a);
	if (a->a->size > 5)
		radix_sort(a->a, a->b);
}
