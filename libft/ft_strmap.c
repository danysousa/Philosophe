/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:48:11 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*res;

	if (s && f)
	{
		i = 0;
		res = ft_memalloc(sizeof(char) * ft_strlen(s));
		while (s[i] != '\0')
		{
			res[i] = (*f)(s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
