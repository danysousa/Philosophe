/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 14:09:21 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/09 17:32:37 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct			s_textur
{
	void				*img;
}						t_texture;

typedef struct			s_env
{
	void				*win;
	void				*mlx;
	t_texture			textures[6];
}						t_env;

typedef struct			s_shared
{
	int					warning_pv[2];
	int					warning_nb[2];
	t_env				*env;
	pthread_mutex_t		stick[NB_PHIL];
	int					death;
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

#endif
