/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:59:55 by vboiko            #+#    #+#             */
/*   Updated: 2017/01/13 15:03:00 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (len > 0 && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] != '\0' && len > 0 && big[i + j] == little[j])
			{
				j++;
				len--;
			}
			if (little[j] == '\0')
				return ((char *)(big + i));
			len = len + j;
		}
		i++;
		len--;
	}
	return (NULL);
}
