/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:43:13 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/13 16:41:54 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap_rotate(t_stack *a, t_stack *b)
{
	int		i;
	int		rf;
	int		count;
	char	*line;

	count = 0;
	i = 0;
	rf = get_next_line(0, &line);
	while (rf > 0)
	{
		i++;
		count = count + swap(a, b, line);
		count = count + push(a, b, line);
		count = count + rotate(a, b, line);
		count = count + rev_rotate(a, b, line);
		free(line);
		line = NULL;
		rf = get_next_line(0, &line);
	}
	free (line);
	if (i != count)
		ft_exit_error();
}

int	main(int argc, char **argv)
{
	int		rf;
	t_stack	*a;
	t_stack	*b;

	argv++;
	argc--;
	if (argc == 0)
		return (0);
	a = get_data(argc, argv);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		ft_exit_error();
	b->begin_stack = NULL;
	b->len = 0;
	push_swap_rotate(a, b);
	if (is_it_sort(a) && a->len && !(b->len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
