/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:07:02 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/09 12:31:44 by jbernard         ###   ########.fr       */
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
	int		pivot;

	j = low;
	i = (low - 1);
	while (j <= high - 1)
	{
		pivot = stack[high];
		if (stack[j] < pivot)
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
	int		pi;

	if (low < high)
	{
		pi = partition_array(stack, low, high);
		quick_sort_array(stack, low, pi - 1);
		quick_sort_array(stack, pi + 1, high);
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

