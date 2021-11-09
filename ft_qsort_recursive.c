/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_recursive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:44:24 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/13 16:42:56 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_qsort_recursive(int *array, int len)
{
	int	i;
	int	j;
	int	mid;
	int	tmp;

	i = 0;
	j = len - 1;
	mid = array[len / 2];
	while (i <= j)
	{
		while (array[i] < mid)
			i++;
		while (array[j] > mid)
			j--;
		if (i <= j)
		{
			ft_swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
	if (j > 0)
		ft_qsort_recursive(array, j + 1);
	if (i < len)
		ft_qsort_recursive(&array[i], len - i);
}
