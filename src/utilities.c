/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:47:40 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/24 18:03:10 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	gettimestamp(t_time unit)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (unit == MILLI)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

int	ft_mutex(pthread_mutex_t *mutex, t_choices choice)
{
	if (choice == INIT)
		return (error_handler(pthread_mutex_init(mutex, NULL)));
	else if (choice == LOCK)
		return (error_handler(pthread_mutex_lock(mutex)));
	else if (choice == UNLOCK)
		return (error_handler(pthread_mutex_unlock(mutex)));
	else if (choice == DESTROY)
		return (error_handler(pthread_mutex_destroy(mutex)));
	else
		return (ft_perror("Incorrect MUTEX choice"), 1);
}

int	ft_pthread(pthread_t *thread, t_philosopher **philos, t_choices choice)
{
	if (choice == CREATE)
		return (error_handler(pthread_create(thread,
					NULL, routine_labtal, *philos)));
	else if (choice == JOIN)
		return (error_handler(pthread_join(*thread, NULL)));
	else if (choice == DETACH)
		return (error_handler(pthread_detach(*thread)));
	else
		return (ft_perror("Incorrect pTHREAD choice"), 1);
}

void	ft_perror(char *error_msg)
{
	printf(RED_COLOR"%s\n"RESET, error_msg);
}

void	fill_struct(char **data, int ac, t_infos *info)
{
	if (ac == 6)
		(*info).meals = ft_atoi(data[5]);
	else
		(*info).meals = -1;
	(*info).end_simulation = 0;
	(*info).num_of_philos = ft_atoi(data[1]);
	(*info).time_to_die = ft_atoi(data[2]) * 1e3;
	(*info).time_to_eat = ft_atoi(data[3]) * 1e3;
	(*info).time_to_sleep = ft_atoi(data[4]) * 1e3;
	(*info).end_mutex = ft_malloc(sizeof(pthread_mutex_t), 0);
	ft_mutex((*info).end_mutex, INIT);
	(*info).print_mutex = ft_malloc(sizeof(pthread_mutex_t), 0);
	ft_mutex((*info).print_mutex, INIT);
}
