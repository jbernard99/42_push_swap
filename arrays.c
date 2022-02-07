/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:48:01 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/07 16:05:06 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arrays	*init_arrays(char *argv[], int argc)
{
	t_arrays *a;
	int	i;

	i = 0;
	while (i < argc)
	{
		printf("%d - %s\n", i, argv[i]);
		i++;
	}

	a->a = init_stack(argc, 1);
	a->b = init_stack(argc, 0);
	
	i = 0;
	while (i < argc)
	{
		printf("%d - %s\n", i, argv[i]);
		i++;
	}
	
	i = 0;
	while (i < argc)
	{
		a->a->stack[i] = ft_atoi(argv[i]);
		i++;
	}
	a->a->average = get_average(a->a->stack, argc);
	return (a);
}