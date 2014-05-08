/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:33:55 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/08 13:57:36 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define NB_PHIL 7
# define MAX_LIFE 20
# define EAT_T 3
# define REST_T 1
# define THINK_T 2
# define TIMEOUT 1000
# define IS_BUSY 16
# define EAT 2
# define THINK 1
# define REST 0

# include <pthread.h>

typedef struct			s_shared
{
	int					warning_pv;
	int					warning_nb;
	pthread_mutex_t		stick[NB_PHIL];
}						t_shared;

typedef struct			s_data
{
	int					life;
	int					action;
	int					n;
	int					stick;
	t_shared			*shared;
}						t_data;

typedef struct			s_phil
{
	pthread_t			thread;
	t_data				data;
}						t_phil;

/*
**	action
*/
void	rest(t_data *data);
void	think(t_data *data);
void	eat(t_data *data);
int		choose_action(t_data *data);

/*
**	pv
*/
void	*change_pv(void *p_data);

/*
**	thread
*/
void	create_phil(pthread_t phil[], t_shared *shared, t_data data[]);
void	join_phil(pthread_t phil[]);
void	destroy_stick(t_data data[]);

/*
**	philo
*/
void	*func(void *p_data);

#endif
