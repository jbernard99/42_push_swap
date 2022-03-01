/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:30:03 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/18 17:34:43 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack {
	int	*stack;
	int	size;
	int	average;
	int	is_a;
}	t_stack;

typedef struct s_arrays {
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
}	t_arrays;

// -- push_swap.c -- //
int			main(int argc, char *argv[]);

// -- sort_stack.c -- //
void		sort_stack(t_arrays *a);

// -- sort_stack_encore.c -- //
void		less_then_three_a(t_stack *s);
void		less_then_three_b(t_stack *s);

// -- moves.c -- //
void		swap(t_stack *s);
void		rotate(t_stack *s);
void		r_rotate(t_stack *s);
void		push_a(t_stack *s_a, t_stack *s_b);
void		push_b(t_stack *s_a, t_stack *s_b);

// -- stack.c -- //
int			get_average(int *s, int size);
void		copie_stack_a(t_arrays *a);
t_stack		*init_stack(int size, int is_a);

// -- indexing.c -- //
void		array_indexing(t_arrays *a);

// -- radix_sort.c -- //
void		radix_sort(t_stack *s_a, t_stack *s_b);

// -- arrays.c -- //
t_arrays	*init_arrays(char *argv[], int argc);

// -- validate_input.c -- //
int			has_space(char *str);
int			validate_input(char *argv[], int argc);

// -- tools.c -- //
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_bzero(int *s, int n);
int			ft_atoi(char *str);
int			*ft_calloc(int count, int size);

// -- more_tools.c -- //
int			ft_strlcpy(char *dest, char *src, int size);

// -- ft_split.c -- //
char		**ft_split(char *s, char c);

// -- error_message.c -- //
void		error_message(void);

#endif