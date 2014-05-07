/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:46:21 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void **ptr, size_t size, size_t new_size)
{
	void	*mem;

	if (size == new_size)
		return (*ptr);
	mem = ft_memalloc(new_size);
	if (mem)
	{
		ft_memcpy(mem, *ptr, MIN(size, new_size));
		ft_memdel(ptr);
	}
	return (mem);
}
