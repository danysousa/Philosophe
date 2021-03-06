/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 12:33:44 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/08 18:38:21 by dsousa           ###   ########.fr       */
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
	pthread_mutex_unlock(&(data->shared->stick[data->stick]));
	sleep(THINK_T);
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

int		choose_action(t_data *data)
{
	int		nb_action;
	int		tmp;

	nb_action = REST;
	if (save_friend(data) == REST)
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
