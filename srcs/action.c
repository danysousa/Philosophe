/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 12:33:44 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/08 17:48:39 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	eat(t_data *data)
{
	static void		(*tb_fct[4])(t_data *) = {&rest, &think, &eat, &waiting};

	data->action = EAT;
	sleep(EAT_T);
	data->life = MAX_LIFE;
	pthread_mutex_unlock(&(data->shared->stick[data->n]));
	pthread_mutex_unlock(&(data->shared->stick[(data->n + 1) % NB_PHIL]));
	tb_fct[choose_action(data)](data);
}

void	think(t_data *data)
{
	static void		(*tb_fct[4])(t_data *) = {&rest, &think, &eat, &waiting};

	data->action = THINK;
	sleep(THINK_T);
	pthread_mutex_unlock(&(data->shared->stick[data->stick]));
	tb_fct[choose_action(data)](data);
}

void	rest(t_data *data)
{
	static void		(*tb_fct[4])(t_data *) = {&rest, &think, &eat, &waiting};

	data->action = REST;
	sleep(REST_T);
	tb_fct[choose_action(data)](data);
}

void	waiting(t_data *data)
{
	static void		(*tb_fct[4])(t_data *) = {&rest, &think, &eat, &waiting};

	data->action = WAITING;
	sleep(1);
	tb_fct[choose_action(data)](data);
}

int		choose_action(t_data *data)
{
	int		nb_action;
	int		prev;
	int		next;
	int		tmp;

	tmp = data->shared->warning_nb[0];
	prev = tmp - 1 == (-1) ? 6 : tmp - 1;
	next = (data->shared->warning_nb[0] + 1) % 7;
	nb_action = REST;
	if (data->n == next || data->n == prev)
	{
		nb_action = data->action == REST ? WAITING : nb_action;
		return (nb_action);
	}
	if (pthread_mutex_trylock(&(data->shared->stick[data->n])) != IS_BUSY)
	{
		nb_action++;
		data->stick = data->n;
	}
	if (data->action == EAT)
		return (nb_action);
	tmp = (data->n + 1) % NB_PHIL;
	if (pthread_mutex_trylock(&(data->shared->stick[tmp])) != IS_BUSY)
	{
		nb_action++;
		data->stick = (data->n + 1) % NB_PHIL;
	}
	nb_action = nb_action == REST && data->action == REST ? WAITING : nb_action;
	return (nb_action);
}
