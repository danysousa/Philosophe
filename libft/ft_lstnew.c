/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:45:52 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	if (!content)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
		newlst->next = NULL;
		return (newlst);
	}
	newlst->content = (void *)content;
	newlst->content_size = content_size;
	newlst->next = NULL;
	return (newlst);
}
