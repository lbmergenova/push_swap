/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:46:37 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/13 16:46:39 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

int	len_arr(char **array)
{
	int	i;

	i = 0;
	while (*(array + i))
		i++;
	return (i);
}

int	size_array(int argc, char **argv)
{
	int		i;
	int		n;
	int		size;
	char	**array;

	i = 0;
	size = 0;
	while (*(argv + i))
	{
		array = ft_split(*(argv + i), ' ');
		if (!array || !*array)
			ft_exit_error();
		n = len_arr(array);
		ft_free_array(array, n);
		size = size + n;
		i++;
	}
	return (size);
}

t_stack	*get_stack_a(int *array, int len)
{
	int		i;
	t_list	*elem;
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		ft_exit_error();
	elem = lst_new(*array);
	a->begin_stack = elem;
	a->len = len;
	i = 1;
	while (i < len)
	{
		elem = lst_add_next(elem, *(array + i));
		i++;
	}
	ft_qsort_recursive(array, len);
	check_value(array, len);
	a->min = array[0];
	a->qrt = array[len / 4];
	a->mid = array[len / 2];
	a->tqrt = array[3 * len / 4];
	a->max = array[len - 1];
	return (a);
}

t_stack	*get_data(int argc, char **argv)
{
	int		len;
	int		i;
	char	**array;
	int		*int_arr;
	t_stack	*stack;

	len = 0;
	int_arr = (int *)malloc(size_array(argc, argv) * sizeof(int));
	while (*argv)
	{
		array = ft_split(*(argv++), ' ');
		if (!array || !*array)
			ft_exit_error();
		i = 0;
		while (*(array + i))
		{
			*(int_arr + len + i) = get_nbr(*(array + i));
			i++;
		}
		ft_free_array(array, len_arr(array));
		len = len + i;
	}
	stack = get_stack_a(int_arr, len);
	free(int_arr);
	return (stack);
}
