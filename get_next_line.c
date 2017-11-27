/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:04:17 by vboiko            #+#    #+#             */
/*   Updated: 2017/01/25 17:13:02 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

char	*ft_strljoin(char const *s1, char const *s2, size_t len)
{
	size_t		i;
	size_t		j;
	char		*concatenated;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	concatenated = ft_strnew(ft_strlen(s1) + len);
	if (concatenated == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		concatenated[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (i < len)
		concatenated[j++] = s2[i++];
	concatenated[j] = '\0';
	return (concatenated);
}

int		ft_parser(int fd, char **line, t_lst **lst, int i)
{
	int		rd;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	ft_bzero(tmp, BUFF_SIZE);
	rd = read(fd, tmp, BUFF_SIZE);
	if (rd == -1)
		return (-1);
	if (rd == 0 && (*lst)->flag == 0)
	{
		*line = ft_strsub((*lst)->str, 0, i);
		(*lst)->flag = 1;
		if ((*lst)->str[0] != '\0')
			return (1);
		return (0);
	}
	else if (rd == 0 && (*lst)->flag != 0)
	{
		*line[0] = '\0';
		return (0);
	}
	(*lst)->str = ft_strljoin((*lst)->str, tmp, rd);
	return (1);
}

int		ft_reader(int fd, char **line, t_lst **lst)
{
	int		i;
	int		ret;

	i = 0;
	while ((*lst)->str[i] != '\n' && (*lst)->str[i] != '\0')
		i++;
	if ((*lst)->str[i] == '\n')
	{
		*line = ft_strsub((*lst)->str, 0, i);
		(*lst)->str = ft_strsub((*lst)->str, i + 1, ft_strlen((*lst)->str) - i);
		return (1);
	}
	else
	{
		ret = ft_parser(fd, line, lst, i);
		if (ret == -1 || ret == 0)
			return (ret);
		else if ((*lst)->flag == 1 && ret == 1)
			return (1);
		ft_reader(fd, line, lst);
	}
	return (ret);
}

t_lst	*ft_creator(t_lst *temp, t_lst **nxt, t_lst **lst, int fd)
{
	temp = (t_lst *)malloc(sizeof(t_lst));
	temp->str = (char *)malloc(sizeof(char));
	temp->fd = fd;
	temp->flag = 0;
	temp->str[0] = '\0';
	temp->next = NULL;
	if (*lst == NULL)
		*lst = temp;
	else
	{
		*nxt = *lst;
		while ((*nxt)->next != NULL)
			*nxt = (*nxt)->next;
		(*nxt)->next = temp;
	}
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	static t_lst	*lst;
	t_lst			*temp;
	t_lst			*nxt;
	int				ret;

	temp = lst;
	if (line == NULL)
		return (-1);
	while (temp != 0 && temp->fd != fd)
		temp = temp->next;
	if (temp != 0 && temp->fd == fd)
		ret = ft_reader(fd, line, &temp);
	else
	{
		temp = ft_creator(temp, &nxt, &lst, fd);
		ret = ft_reader(fd, line, &temp);
	}
	return (ret);
}
