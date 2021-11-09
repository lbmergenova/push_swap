/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:44:58 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/13 16:45:33 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	m1;
	int	m2;
	int	m3;
	int	m4;
}	t_move;

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*begin_stack;
	int		min;
	int		qrt;
	int		mid;
	int		tqrt;
	int		max;
	int		len;
}	t_stack;

//get_data.c
t_stack		*get_data(int	argc, char **argv);
//go_move_0.c
void		go_move_0(t_stack *a, t_stack *b, int border, int mid);
//go_move.c
void		go_move_1(t_stack *a, t_stack *b, t_move move);
void		go_move_2(t_stack *a, t_stack *b, t_move move);
void		go_move_3(t_stack *a, t_stack *b, t_move move);
void		go_move_4(t_stack *a, t_stack *b, t_move move);
//utils.c
int			is_it_sort(t_stack *a);
void		redefine_stack(t_stack *stack);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
//sort_three.c
void		sorting_three(t_stack *a, t_stack *b);
//ft_qsort_recursive.c
void		ft_qsort_recursive(int	*array, int size);
//get_data_utils.c
void		ft_exit_error(void);
long int	get_nbr(char *nptr);
void		check_value(int *array, int len);
//choice_move.c
int			position_elem(t_stack *stack, int elem);
t_move		min_move(t_stack *a, t_stack *b);
//get_stack.c
t_stack		*get_stack_b(t_stack *a);
void		from_b_to_a(t_stack *a, t_stack *b);
//operations_c.c
void		rotate_n(t_stack *stack, int n);
void		operation_n(t_stack *stack, void (*f)(t_stack *), int n);
void		ft_write_n(char *str, int n);
//list.c
t_list		*lst_new(int content);
t_list		*lst_add_next(t_list *last_elem, int val);
void		lst_add_front(t_list **lst, t_list *new_elem);
t_list		*lst_n_elem(t_stack *stack, int n);
//operations.c
void		lst_rotate(t_stack *stack);
void		lst_rev_rotate(t_stack *stack);
void		lst_push(t_stack *from_s, t_stack *to_s);
void		lst_swap(t_stack *stack);
//checker_operations.c
int			swap(t_stack *a, t_stack *b, char *oprt);
int			push(t_stack *a, t_stack *b, char *oprt);
int			rotate(t_stack *a, t_stack *b, char *oprt);
int			rev_rotate(t_stack *a, t_stack *b, char *oprt);

#endif
