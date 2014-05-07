/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:47:32 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	siz;
	char	*copy;

	if (str[0] == '\0')
		return (NULL);
	siz = ft_strlen(str) + 1;
	copy = (char *)malloc(sizeof(char) * siz);
	if (copy == NULL)
		return ((char *)NULL);
	(void)ft_memcpy(copy, str, siz);
	return (copy);
}
