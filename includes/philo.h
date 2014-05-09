/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:33:55 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/09 17:33:02 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define NB_PHIL 7
# define MAX_LIFE 30
# define EAT_T 2
# define REST_T 2
# define THINK_T 2
# define TIMEOUT 30
# define IS_BUSY 16
# define WAITING 3
# define EAT 2
# define THINK 1
# define REST 0

# define WIN_H 200
# define WIN_W 900

# define DANCE "Now, it is time... To DAAAAAAAANCE !!!"
# define TB_NAME1 "Roger", "Francis", "Auguste", "Marcus", "Bernard",
# define TB_NAME2 "Bruce", "George"
# define TB_NAME TB_NAME1 TB_NAME2
# define TB_ACTION "dors", "pense", "mange", "attend", "mort", "dance"

# include <mlx.h>
# include "struct.h"

/*
**	action
*/
void	rest(t_data *data);
void	think(t_data *data);
void	eat(t_data *data);
void	waiting(t_data *data);
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
void	destroy_stick(pthread_mutex_t stick[]);

/*
**	philo
*/
void	*func(void *p_data);

/*
**	textures
*/
void	add_texture(t_env *env, char *tex_path);

/*
**	save_friend
*/
int		save_friend(t_data *data);

/*
**	clear
*/
void	clear_win(t_env *env);

#endif
