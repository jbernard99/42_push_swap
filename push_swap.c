/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:43:59 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/18 11:30:53 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_argv_size(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	free_all(t_arrays *a, char *argv[], int is_splited)
{
	int	i;

	free(a->a->stack);
	free(a->a);
	free(a->b->stack);
	free(a->b);
	free(a);
	if (is_splited)
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

int	main(int argc, char *argv[])
{
	t_arrays	*arrays;
	int			to_free;

	to_free = 0;
	argv++;
	if (--argc < 1)
		return (0);
	else if (argc == 1)
	{
		if (has_space(argv[0]))
		{
			argv = ft_split(argv[0], ' ');
			to_free = 1;
			argc = split_argv_size(argv);
		}
		else
			return (0);
	}
	validate_input(argv, argc);
	arrays = init_arrays(argv, argc);
	array_indexing(arrays);
	sort_stack(arrays);
	free_all(arrays, argv, to_free);
}
