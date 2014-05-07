/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:46:51 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	size_t	len;
	void	*new;

	new = NULL;
	len = 0;
	size = 0;
	if (ptr != NULL)
	{
		len = ft_strlen((char *)ptr);
		size += len;
		if ((new = ft_memalloc(size + 1)) == NULL)
			return (NULL);
		ft_memcpy(new, ptr, len);
		ft_memdel(&ptr);
	}
	else
		new = ft_memalloc(size + 1);
	return (new);
}
