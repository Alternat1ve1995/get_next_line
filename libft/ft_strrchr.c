/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:19:58 by vboiko            #+#    #+#             */
/*   Updated: 2017/01/13 15:02:56 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
		i++;
	while (str[i] != (char)c && i != 0)
		i--;
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
