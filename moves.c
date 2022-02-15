/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:16:56 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/07 12:00:17 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	temp;

	temp = s->stack[0];
	s->stack[0] = s->stack[1];
	s->stack[1] = temp;
	if (s->is_a)
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
}

void	rotate(t_stack *s)
{
	int	i;
	int	temp;

	temp = s->stack[0];
	i = 0;
	while (i < s->size)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[s->size - 1] = temp;
	ft_putstr("ra\n");
}

void	r_rotate(t_stack *s)
{
	int	i;
	int	temp;

	i = s->size - 1;
	temp = s->stack[s->size - 1];
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
	s->stack[0] = temp;
	ft_putstr("rra\n");
}

void	push_a(t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = s_b->stack[0];
	while (i < s_b->size)
	{
		s_b->stack[i] = s_b->stack[i + 1];
		i++;
	}
	s_b->size--;
	i = s_a->size;
	while (i > 0)
	{
		s_a->stack[i] = s_a->stack[i - 1];
		i--;
	}
	s_a->stack[0] = temp;
	s_a->size++;
	ft_putstr("pa\n");
}

void	push_b(t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = s_a->stack[0];
	while (i < s_a->size)
	{
		s_a->stack[i] = s_a->stack[i + 1];
		i++;
	}
	s_a->size--;
	i = s_b->size;
	while (i > 0)
	{
		s_b->stack[i] = s_b->stack[i - 1];
		i--;
	}
	s_b->stack[0] = temp;
	s_b->size++;
	ft_putstr("pb\n");
}
