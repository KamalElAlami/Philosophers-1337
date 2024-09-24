/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:53:49 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/24 17:27:58 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	monitor(t_philosopher *rijal)
{
	while (1)
	{
		if (check_meals(rijal) || freq_check(rijal))
			break ;
		usleep(100);
	}
}

int	create_threads(t_philosopher **philos)
{
	int				i;
	t_philosopher	*temp;

	i = 0;
	temp = *philos;
	while (i < temp->info->num_of_philos)
	{
		if (ft_pthread(&(temp->thread), &temp, CREATE) != 0)
			return (0);
		temp = temp->next;
		i++;
	}
	monitor(*philos);
	i = 0;
	temp = *philos;
	while (i < temp->info->num_of_philos)
	{
		if (ft_pthread(&(temp->thread), &temp, JOIN) != 0)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	data_init(t_philosopher *rijal)
{
	rijal->forchette = ft_malloc(sizeof(pthread_mutex_t), 0);
	if (!rijal->forchette)
		return (0);
	rijal->meals_eaten_lock = ft_malloc(sizeof(pthread_mutex_t), 0);
	if (!rijal->meals_eaten_lock)
		return (0);
	rijal->last_meal_lock = ft_malloc(sizeof(pthread_mutex_t), 0);
	if (!rijal->last_meal_lock)
		return (0);
	if (ft_mutex(rijal->forchette, INIT) != 0)
		return (0);
	if (ft_mutex(rijal->meals_eaten_lock, INIT) != 0)
		return (0);
	if (ft_mutex(rijal->last_meal_lock, INIT) != 0)
		return (0);
	return (1);
}

int	setup_data(t_infos *info, t_philosopher **philos)
{
	int				i;
	t_philosopher	*tmp;

	i = 1;
	while (i <= (*info).num_of_philos)
		add_lbatal(philos, new_batal(i++, info));
	tmp = *philos;
	while (tmp->next)
	{
		if (!data_init(tmp))
			return (0);
		if (tmp->next == *philos)
			break ;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_infos			info;
	t_philosopher	*abtal;

	abtal = NULL;
	info.start_time = gettimestamp(MILLI);
	if (ac != 5 && ac != 6)
	{
		ft_perror("Usage : NUM_PHILOS TIME_DIE TIME_EAT TIME_SLEEP");
		return (1);
	}
	if (!parse_input(av, ac, &info))
	{
		ft_perror("Error: Invalid Input");
		return (1);
	}
	if (!setup_data(&info, &abtal))
		return (1);
	if (!create_threads(&abtal))
		return (1);
	clear_stuff(abtal, &info);
}
