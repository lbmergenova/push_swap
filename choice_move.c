/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:44:00 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:44:03 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_elem(t_stack *stack, int elem)
{
	int		n;
	t_list	*lst;

	n = 0;
	lst = stack->begin_stack;
	while (lst && lst->val != elem)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

int	position_o_elem(t_stack *stack, int elem)
{
	int		n;
	t_list	*lst;

	n = 0;
	if (elem > stack->max)
		return (position_elem(stack, stack->max) + 1);
	else if (elem < stack->min)
		return (position_elem(stack, stack->min));
	lst = stack->begin_stack;
	if (lst->val > elem && (lst_n_elem(stack, stack->len))->val < elem)
		return (0);
	while (lst && lst->next && !(lst->val < elem && (lst->next)->val > elem))
	{
		n++;
		lst = lst->next;
	}
	return (++n);
}

t_move	define_move(int pos_a, int pos_b, int len_a, int len_b)
{
	t_move	ret;

	ret.ra = pos_a;
	ret.rb = pos_b;
	ret.rra = len_a - pos_a;
	ret.rrb = len_b - pos_b;
	ret.m1 = ft_max(ret.ra, ret.rb);
	ret.m2 = ret.ra + ret.rrb;
	ret.m3 = ret.rra + ret.rb;
	ret.m4 = ft_max(ret.rra, ret.rrb);
	return (ret);
}

t_move	min_move(t_stack *a, t_stack *b)
{
	int		min;
	int		pos_b;
	t_list	*lst_b;
	t_move	move;
	t_move	min_move;

	min = a->len + b->len;
	pos_b = 0;
	lst_b = b->begin_stack;
	min_move = define_move(0, 0, 0, 0);
	while (lst_b)
	{
		move = define_move(position_o_elem(a, lst_b->val), pos_b,
				a->len, b->len);
		if (min > ft_min(ft_min(move.m1, move.m2), ft_min(move.m3, move.m4)))
		{
			min_move = move;
			min = ft_min(ft_min(move.m1, move.m2), ft_min(move.m3, move.m4));
		}
		pos_b++;
		lst_b = lst_b->next;
	}
	return (min_move);
}
