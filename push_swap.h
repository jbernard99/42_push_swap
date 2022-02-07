/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:30:03 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/04 22:30:03 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stack {
	int		*stack;
	int		size;
	int		average;
	int		is_a;
}	t_stack;

typedef struct	s_arrays {
	t_stack *a;
	t_stack *b;
}	t_arrays;

// -- push_swap.c -- //
int	main(int argc, char *argv[]);

// -- stack.c -- //
int	get_average(int *s, int size);
t_stack	*init_stack(int size, int is_a);

// -- arrays.c -- //
t_arrays	*init_arrays(char *argv[], int argc);

// -- validate_input.c -- //
int	has_space(char *str);
void validate_input(char *argv[], int argc);

// -- tools.c -- //
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_bzero(int *s, int n);
int	ft_atoi(char *str);
int	*ft_calloc(int count, int size);

// -- more_tools.c -- //
int	ft_strlcpy(char *dest, char *src, int size);

// -- ft_split.c -- //
char	**ft_split(char *s, char c);

// -- error_message.c -- //
void	error_message(char *e);

#endif