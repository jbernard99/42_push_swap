/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:41:54 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/05 00:41:54 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}
