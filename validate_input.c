/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:44:16 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/04 23:44:16 by jbernard         ###   ########.fr       */
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

void	check_unauthorized_characters(char c)
{
	if (c < 48 || c > 57)
	{
		if (c != 45)
			error_message("Unauthorized Character found!\n");
	}
}

void	check_duplicates(char *s1, char *s2)
{
	if (ft_atoi(s1) == ft_atoi(s2))
		error_message("Duplicate input found!\n");
}

void validate_input(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			check_unauthorized_characters(argv[i][j]);
			j++;
		}
		j = i + 1;
		while (j < argc && i < argc - 1)
		{
			check_duplicates(argv[i], argv[j]);
			j++;
		}
		i++;
	}
	printf("\n\n\n\n");
}