/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:46:04 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n > 0)
	{
		while (--n && *(char *)s1 == *(char *)s2)
		{
			s1 = (char*)s1 + 1;
			s2 = (char*)s2 + 1;
		}
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	}
	return (0);
}
