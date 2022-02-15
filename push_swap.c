/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:43:59 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/15 09:53:41 by jbernard         ###   ########.fr       */
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

void	free_all(t_arrays *a)
{
	free(a->a->stack);
	free(a->a);
	free(a->b->stack);
	free(a->b);
	free(a);
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
	free_all(arrays);

	if (to_free != 0)
		free(argv);
}