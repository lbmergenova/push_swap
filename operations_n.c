/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:46:06 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:46:08 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_n(t_stack *stack, void (*f)(t_stack *), int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(stack);
		i++;
	}
}

void	rotate_n(t_stack *stack, int n)
{
	if (n - (stack->len) / 2 - (stack->len) % 2 > 0)
	{
		n = stack->len - n + 1;
		operation_n(stack, lst_rev_rotate, n);
		ft_write_n("rra\n", n);
	}
	else
	{
		n = n - 1;
		operation_n(stack, lst_rotate, n);
		ft_write_n("ra\n", n);
	}
}

void	ft_write_n(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, str, ft_strlen(str));
		i++;
	}
}
