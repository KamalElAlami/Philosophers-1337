/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:54:51 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/24 17:35:08 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <errno.h>

#define RED_COLOR		"\x1b[31m"
#define YELLOW_COLOR	 	"\x1b[33m"
#define GREEN_COLOR	 	"\x1b[32m"
#define RESET		 	"\x1b[0m"

typedef enum e_choices
{
	CREATE,
	JOIN,
	DETACH,
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_choices;

typedef enum e_state
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
}	t_state;

typedef enum e_time
{
	MILLI,
	MICRO,
}	t_time;

typedef struct s_infos
{
	long				start_time;
	long				num_of_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					meals;
	int					end_simulation;
	pthread_mutex_t		*end_mutex;
	pthread_mutex_t		*print_mutex;
}	t_infos;

typedef struct t_philosopher
{
	int						index;
	int						meals_eaten;
	long					last_meal;
	t_infos					*info;
	pthread_t				thread;
	pthread_mutex_t			*forchette;
	pthread_mutex_t			*meals_eaten_lock;
	pthread_mutex_t			*last_meal_lock;
	struct t_philosopher	*next;

}	t_philosopher;

typedef struct t_collector
{
	void					*ptr;
	struct t_collector		*next;
}	t_collector;

// helpers
t_philosopher	*new_batal(int index, t_infos *info);
void			add_lbatal(t_philosopher **head, t_philosopher *node);
void			print_list(t_philosopher *list);
int				ft_mutex(pthread_mutex_t *mutex, t_choices choice);
int				ft_pthread(pthread_t *thread,
					t_philosopher **philos, t_choices choice);
long			gettimestamp(t_time unit);
void			ft_usleep(long microseconds, t_philosopher *rijal);
void			clear_stuff(t_philosopher *philos, t_infos *info);

// parsing
int				parse_input(char **data, int ac, t_infos *philo);
int				check_overflow(char *number);
int				check_validity(char **data);
void			fill_struct(char **data, int ac, t_infos *info);
void			ft_perror(char *error_msg);
int				error_handler(int error);
// void			data_init(t_infos info, t_philosopher **philos);
int				ft_isdigit(int n);
int				ft_atoi(const char *str);
void			*ft_malloc(size_t size, int flag);

// routine 
int				check_death(t_philosopher *batal);
int				sleepnthink(t_philosopher *rijal);
int				drop_forks(t_philosopher *rijal);
int				eat(t_philosopher *rijal);
int				take_forks(t_philosopher *rijal);
void			print_state(t_philosopher *batal, t_state state);
void			*routine_labtal(void *abtal);
int				check_meals(t_philosopher *rijal);

int				get_simulation_value(t_infos *info);
void			set_simulation_value(t_infos *infos, int value);
int				freq_check(t_philosopher *rijal);

long			get_lmeals_value(t_philosopher *rijal);
void			set_lmeals_value(t_philosopher *rijal, long timee);
int				get_cmeals_value(t_philosopher *rijal);
void			set_cmeals_value(t_philosopher *rijal);
