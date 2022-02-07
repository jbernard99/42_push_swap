/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:47:38 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/04 23:47:53 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_average(int *s, int size)
{
	int i;
	int total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total = total + s[i];
		i++;
	}
	return (total / size);
}

t_stack	*init_stack(int size, int is_a)
{
	t_stack *s;
	
	s->stack = ft_calloc(size, sizeof(int));
	s->size = size;
	s->average = 0;
	s->is_a = is_a;
	return (s);
}