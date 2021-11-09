/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:04:03 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:04:07 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putline(char **line, char **s_mod, char *ptr)
{
	char	*freestr;

	if (!ptr)
	{
		*line = ft_strjoin(NULL, *s_mod);
		free(*s_mod);
		*s_mod = NULL;
		if (!(*line))
			return (-1);
		return (0);
	}
	*ptr = '\0';
	*line = ft_strjoin(NULL, *s_mod);
	if (!(*line))
	{
		free(*s_mod);
		return (-1);
	}
	freestr = *s_mod;
	*s_mod = ft_strjoin(NULL, ++ptr);
	free(freestr);
	freestr = NULL;
	if (!(*s_mod))
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		rf;
	char		*ptr;
	char		*freestr;
	static char	*s_mod;
	char		s[513];

	if (fd < 0 || 512 <= 0 || !line)
		return (-1);
	ptr = ft_strchr(s_mod, '\n');
	while (!ptr)
	{
		rf = read(fd, s, 512);
		if (rf < 0)
			return (-1);
		s[rf] = 0;
		freestr = s_mod;
		s_mod = ft_strjoin(s_mod, s);
		free(freestr);
		if (!s_mod)
			return (-1);
		ptr = ft_strchr(s_mod, '\n');
		if (rf == 0)
			return (ft_putline(line, &s_mod, ptr));
	}
	return (ft_putline(line, &s_mod, ptr));
}
