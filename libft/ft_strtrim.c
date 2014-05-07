/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:58:31 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;

	if (!s)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	len = ft_strlen(s) - 1;
	while (len > 0 && s[len] && ft_isspace(s[len]))
		len--;
	return (ft_strsub(s, 0, len + 1));
}
