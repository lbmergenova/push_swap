/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:45:15 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:45:18 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	from_a_to_b(t_stack *a, t_stack *b, int border, int mid)
{
	int	i;
	int	n;
	int	count;

	i = 0;
	if (border == a->max)
	{
		while (a->len > 3)
			go_move_0(a, b, border, mid);
	}
	else
	{
		n = a->len - 3;
		while (i > n)
		{
			go_move_0(a, b, border, mid);
			i++;
		}
	}
	count = 0;
	return (count);
}

t_stack	*get_stack_b(t_stack *a)
{
	int		i;
	int		n;
	t_stack	*b;

	i = 0;
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		ft_exit_error();
	b->begin_stack = NULL;
	b->len = 0;
	n = a->len;
	if (a->len < 3)
		return (b);
	if (!is_it_sort(a) && a->len > 200)
	{
		from_a_to_b(a, b, a->mid, a->qrt);
		from_a_to_b(a, b, a->max, a->tqrt);
	}
	else if (!is_it_sort(a) && a->len > 3)
		from_a_to_b(a, b, a->max, a->mid);
	return (b);
}

void	from_b_to_a(t_stack *a, t_stack *b)
{
	int		min;
	t_move	move;

	while (b->begin_stack)
	{
		move = min_move(a, b);
		min = ft_min(ft_min(move.m1, move.m2), ft_min(move.m3, move.m4));
		if (move.m1 == min)
			go_move_1(a, b, move);
		else if (move.m2 == min)
			go_move_2(a, b, move);
		else if (move.m3 == min)
			go_move_3(a, b, move);
		else if (move.m4 == min)
			go_move_4(a, b, move);
		redefine_stack(a);
	}
}
