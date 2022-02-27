/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:07:02 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/27 16:52:07 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_array_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition_array(int stack[], int low, int high)
{
	int		i;
	int		j;
	int		temp;

	j = low;
	i = low - 1;
	while (j <= high - 1)
	{
		temp = stack[high];
		if (stack[j] < temp)
		{
			i++;
			quick_array_swap(&(stack[i]), &(stack[j]));
		}
		j++;
	}
	quick_array_swap(&(stack[i + 1]), &(stack[high]));
	return (i + 1);
}

void	quick_sort_array(int stack[], int low, int high)
{
	int		x;

	if (low < high)
	{
		x = partition_array(stack, low, high);
		quick_sort_array(stack, low, x - 1);
		quick_sort_array(stack, x + 1, high);
	}
}

void	array_indexing(t_arrays *a)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	index = 1;
	a->c = init_stack(a->a->size, 0);
	copie_stack_a(a);
	quick_sort_array(a->c->stack, 0, a->c->size - 1);
	while (i < a->c->size)
	{
		j = 0;
		while (j < a->c->size)
		{
			if (a->a->stack[i] > a->c->stack[j])
				index++;
			j++;
		}
		a->a->stack[i] = index;
		index = 1;
		i++;
	}
	free(a->c->stack);
	free(a->c);
}
