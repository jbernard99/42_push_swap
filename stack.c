/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:47:38 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/09 12:20:24 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_average(int *s, int size)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total = total + s[i];
		i++;
	}
	return (total / size);
}

void	copie_stack_a(t_arrays *a)
{
	int	i;

	i = 0;
	while (i < a->a->size)
	{
		a->c->stack[i] = a->a->stack[i];
		i++;
	}
}

t_stack	*init_stack(int size, int is_a)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	s->stack = ft_calloc(size * 2, sizeof(int));
	s->size = size;
	s->average = 0;
	s->is_a = is_a;
	return (s);
}
