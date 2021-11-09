/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   checker_operations.c							   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sfearow <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/12 22:43:38 by sfearow		   #+#	#+#			 */
/*   Updated: 2021/08/13 16:42:04 by sfearow          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *a, t_stack *b, char *oprt)
{
	if (ft_strnstr("sa", oprt, 2))
	{
		lst_swap(a);
		return (1);
	}
	else if (ft_strnstr("sb", oprt, 2))
	{
		lst_swap(b);
		return (1);
	}
	else if (ft_strnstr("ss", oprt, 2))
	{
		lst_swap(a);
		lst_swap(b);
		return (1);
	}
	return (0);
}

int	push(t_stack *a, t_stack *b, char *oprt)
{
	if (ft_strnstr("pa", oprt, 2))
	{
		lst_push(b, a);
		return (1);
	}
	else if (ft_strnstr("pb", oprt, 2))
	{
		lst_push(a, b);
		return (1);
	}
	return (0);
}

int	rotate(t_stack *a, t_stack *b, char *oprt)
{
	if (ft_strnstr("ra", oprt, 2))
	{
		lst_rotate(a);
		return (1);
	}
	else if (ft_strnstr("rb", oprt, 2))
	{
		lst_rotate(b);
		return (1);
	}
	else if (ft_strnstr("rr", oprt, 2))
	{
		lst_rotate(a);
		lst_rotate(b);
		return (1);
	}
	return (0);
}

int	rev_rotate(t_stack *a, t_stack *b, char *oprt)
{
	if (ft_strlen(oprt) < 3)
		return (0);
	if (ft_strnstr("rra", oprt, 3))
	{
		lst_rev_rotate(a);
		return (1);
	}
	else if (ft_strnstr("rrb", oprt, 3))
	{
		lst_rev_rotate(b);
		return (1);
	}
	else if (ft_strnstr("rrr", oprt, 3))
	{
		lst_rev_rotate(a);
		lst_rev_rotate(b);
		return (1);
	}
	return (0);
}
