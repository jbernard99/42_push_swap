/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:43:59 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/09 12:35:48 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int split_argv_size(char *argv[])
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	print_state(t_arrays *a, int argc)
{
	int	i;
	
	printf("\n == Current State ==\n");
	printf("\n - Stack A:\n	");
	i = 0;
	while (i < argc)
	{
		printf(" %d", a->a->stack[i]);
		i++;
	}
	printf("\n\n - Stack B:\n	");
	i = 0;
	while (i < argc)
	{
		printf(" %d", a->b->stack[i]);
		i++;
	}
	printf("\n\n");
}

int	main(int argc, char *argv[])
{
	t_arrays	*arrays;
	int	to_free;
	int	i;
	
	to_free = 0;
	argv++;
	argc--;
	if (argc < 1)
		error_message("Not enough parameters!\n");
	else if (argc == 1)
	{
		if (has_space(argv[0]))
		{
			argv = ft_split(argv[0], ' ');
			to_free = 1;
			argc = split_argv_size(argv);
		}
		else
			error_message("Not enough parameters!\n");
	}
	validate_input(argv, argc);
	arrays = init_arrays(argv, argc);
	array_indexing(arrays);
	sort_stack(arrays);
	print_state(arrays, argc);

	if (to_free != 0)
		free(argv);
}