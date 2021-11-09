/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:46:53 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:46:55 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	may_be_swap(int a1, int a2, int a3)
{
	if (a1 < a2 && a2 > a3 && a3 > a1)
		return (1);
	if (a1 > a2 && a2 < a3 && a3 > a1)
		return (1);
	if (a1 > a2 && a2 > a3 && a3 < a1)
		return (1);
	return (0);
}

void	sorting_three(t_stack *a, t_stack *b)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = a->begin_stack->val;
	a2 = a->begin_stack->next->val;
	a3 = a->begin_stack->next->next->val;
	if (may_be_swap(a1, a2, a3))
	{
		lst_swap(a);
		if (b->len > 1 && b->begin_stack->val < b->begin_stack->next->val)
		{
			lst_swap(b);
			write(1, "ss\n", 3);
		}
		else
			write(1, "sa\n", 3);
	}
	a->min = ft_min(ft_min(a1, a2), a3);
	a->max = ft_max(ft_max(a1, a2), a3);
}
