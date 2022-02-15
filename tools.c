/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:11:55 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/07 11:29:25 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_strlen(char	*str)
{
	int	i;

	if (!*str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_bzero(int *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

int	ft_atoi(char *str)
{
	int		sign;
	int		nbr;
	long	long_nbr;

	sign = 1;
	nbr = 0;
	long_nbr = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		long_nbr = long_nbr * 10;
		long_nbr += *str - '0';
		str++;
	}
	if (long_nbr < -2147483648 || long_nbr >= 2147483647)
		error_message("Number to big!\n");
	nbr = long_nbr;
	return (nbr * sign);
}

int	*ft_calloc(int count, int size)
{
	int	*s;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	s = malloc(size * count);
	if (!s)
		error_message("Memory allocation error!\n");
	ft_bzero(s, size);
	return (s);
}
