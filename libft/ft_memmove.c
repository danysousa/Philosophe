/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:46:18 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*dp;
	unsigned char		*sp;

	if (n > 0)
	{
		dp = (unsigned char *)src;
		sp = (unsigned char *)dest;
		if (!n)
			return (dest);
		if (dest <= src)
			return (ft_memcpy(dest, src, n));
		dp += n;
		sp += n;
		while (n--)
			*--sp = *--dp;
		return (dest);
	}
	return (dest);
}
