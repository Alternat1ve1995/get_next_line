/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:05:51 by vboiko            #+#    #+#             */
/*   Updated: 2017/01/25 16:58:40 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFF_SIZE 1

typedef struct	s_lst
{
	int			fd;
	int			flag;
	char		*str;
	void		*next;
}				t_lst;

int				get_next_line(int fd, char **line);

#endif
