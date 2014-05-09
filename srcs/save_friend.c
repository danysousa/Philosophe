/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_friend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 16:58:20 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/09 16:58:35 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		save_friend(t_data *data)
{
	int		prev;
	int		next;
	int		tmp;

	tmp = data->shared->warning_nb[0];
	if (data->n == data->shared->warning_nb[1] || data->n == tmp)
		return (42);
	tmp = data->shared->warning_nb[0];
	prev = tmp - 1 == (-1) ? 6 : tmp - 1;
	next = (tmp + 1) % 7;
	if (data->n == next || data->n == prev)
		return (REST);
	tmp = data->shared->warning_nb[1];
	prev = tmp - 1 == (-1) ? 6 : tmp - 1;
	next = (tmp + 1) % 7;
	if (data->n == next || data->n == prev)
		return (REST);
	else
		return (42);
}
