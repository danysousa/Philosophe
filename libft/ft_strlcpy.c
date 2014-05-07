/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:48:04 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = siz;
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*d++ = *s++) == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (siz != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
