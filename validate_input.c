/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:44:16 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/18 11:30:35 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_unauthorized_characters(char c, int is_first)
{
	if (c < 48 || c > 57)
	{
		if (c == 45 && is_first == 0)
			return ;
		error_message();
	}
}

void	check_duplicates(int x, int y)
{
	if (x == y)
		error_message();
}

void	check_min_max(int x)
{
	if (x < (long)INT_MIN || x > (long)INT_MAX)
		error_message();
}

void	validate_input(char *argv[], int argc)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < argc)
	{
		j = 0;
		x = ft_atoi(argv[i]);
		while (argv[i][j])
		{
			check_unauthorized_characters(argv[i][j], j);
			j++;
		}
		j = i + 1;
		while (j < argc && i < argc - 1)
		{
			check_duplicates(x, ft_atoi(argv[j]));
			j++;
		}
		check_min_max(x);
		i++;
	}
}
