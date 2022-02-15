/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_encore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:33:42 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/07 11:50:43 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_then_three_a(t_stack *s)
{
	if (s->stack[0] > s->stack[1])
		swap(s);
}

void	less_then_three_b(t_stack *s)
{
	if (s->stack[1] > s->stack[0])
		swap(s);
}
