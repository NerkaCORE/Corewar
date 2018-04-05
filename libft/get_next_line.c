/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:43:04 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/26 17:36:25 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/get_next_line.h"

t_fd			*serach_fd(int fd, t_fd **liste)
{
	while ((*liste) && (*liste)->fd != fd)
		liste = &(*liste)->next;
	if (!(*liste))
	{
		if (!((*liste) = malloc(sizeof(t_fd))))
			return (NULL);
		(*liste)->next = NULL;
		(*liste)->fd = fd;
		(*liste)->stat = NULL;
	}
	return (*liste);
}

char			*ft_join_free(char *s1, char *s2, int d)
{
	char		*str;
	int			len;

	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (d == 1)
	{
		free(s1);
		free(s2);
		s1 = NULL;
		s2 = NULL;
	}
	if (d == 2)
	{
		free(s1);
		s2 = NULL;
	}
	return (str);
}

int				read_stat(t_fd *liste, char **line)
{
	char		*tmp;
	char		*subtmp;

	if (liste->stat == NULL)
		return (0);
	if ((tmp = ft_strchr(liste->stat, '\n')))
	{
		if (!(subtmp = ft_strsub(liste->stat, 0, tmp - liste->stat)))
			return (-1);
		*line = ft_strjoin(*line, subtmp);
		ft_strdel(&subtmp);
		liste->stat = ft_strdup(liste->stat + (tmp - liste->stat) + 1);
		return (*line == NULL ? -1 : 1);
	}
	else
	{
		*line = ft_strjoin(*line, liste->stat);
		ft_strdel(&liste->stat);
	}
	return (*line == NULL ? -1 : 0);
}

int				read_fonction(char **line, t_fd *liste)
{
	int			r;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	char		*tmp_new;

	while ((r = read(liste->fd, buff, BUFF_SIZE)))
	{
		if (r < 0)
			return (-1);
		buff[r] = '\0';
		if ((tmp = ft_strchr(buff, '\n')))
		{
			tmp_new = ft_strsub(buff, 0, tmp - buff);
			*line = ft_join_free(*line, tmp_new, 1);
			liste->stat = ft_strdup(buff + (tmp - buff) + 1);
			return (1);
		}
		else
			*line = ft_join_free(*line, buff, 2);
	}
	if (!*line)
		return (-1);
	return ((r == 0 && **line == '\0') ? 0 : 1);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd *liste = NULL;
	t_fd		*new_fd;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (!(new_fd = serach_fd(fd, &liste)))
		return (-1);
	if (read_stat(new_fd, line))
		return (*line == NULL ? -1 : 1);
	return (read_fonction(line, new_fd));
}
