/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:46:11 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/13 16:46:12 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rotate(t_stack *stack)
{
	t_list	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->begin_stack;
	lst_n_elem(stack, stack->len)->next = tmp;
	stack->begin_stack = tmp->next;
	tmp->next = NULL;
}

void	lst_rev_rotate(t_stack *stack)
{
	t_list	*lst;
	t_list	*tmp;

	if (stack->len < 2)
		return ;
	lst = lst_n_elem(stack, stack->len - 1);
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = (stack->begin_stack);
	stack->begin_stack = tmp;
}

void	lst_push(t_stack *from_s, t_stack *to_s)
{
	t_list	*tmp;

	if (from_s->len == 0)
		return ;
	tmp = from_s->begin_stack;
	from_s->begin_stack = tmp->next;
	tmp->next = to_s->begin_stack;
	to_s->begin_stack = tmp;
	from_s->len--;
	to_s->len++;
}

void	lst_swap(t_stack *stack)
{
	int		val;
	t_list	*elem;

	if (stack->len == 0)
		return ;
	elem = stack->begin_stack;
	val = elem->val;
	elem->val = elem->next->val;
	elem->next->val = val;
}
