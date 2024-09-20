/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:53:49 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/19 12:50:17 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void create_threads(t_philosopher **philos)
{
	int i;
	t_philosopher *temp;

	i = 0;
	temp = *philos;
	while (i < temp->info->num_of_philos)
	{
		ft_pthread(&(temp->thread), &temp, CREATE);
		temp = temp->next;
		i++;
	}
	i = 0;
	temp = *philos;
	while (i < temp->info->num_of_philos)
	{
		ft_pthread(&(temp->thread), &temp, DETACH);
		temp = temp->next;
		i++;
	}
	temp = *philos;
	while (1)
	{
		if (freq_check(temp))
		{
			usleep(2);
			break ;
		}
	}
}

void setup_data(t_infos *info, t_philosopher **philos)
{
	int i;
	t_philosopher *tmp;
	i = 1;
	while (i <= (*info).num_of_philos)
		add_lbatal(philos, new_batal(i++, info));
	tmp = *philos;
	while (tmp->next)
	{
		tmp->forchette = ft_malloc(sizeof(pthread_mutex_t), 0);
		tmp->meals_eaten_lock = ft_malloc(sizeof(pthread_mutex_t), 0);
		tmp->last_meal_lock = ft_malloc(sizeof(pthread_mutex_t), 0);
		ft_mutex(tmp->forchette, INIT);
		ft_mutex(tmp->meals_eaten_lock, INIT);
		ft_mutex(tmp->last_meal_lock, INIT);
		if (tmp->next == *philos)
			break;
		tmp = tmp->next;
	}	
}
int parse_input(char **data, int ac, t_infos *philo)
{
	int i;
	int j;

	i = 1;
	if (!data[1] || !data[2] || !data[3] || !data[4])
		return (0);
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (!ft_isdigit(data[i][j]))
				return (0);
			j++;
		}
		if (!check_overflow(data[i]))
			return (0);
		i++;
	}
	if (!check_validity(data))
		return (0);
	fill_struct(data, ac, philo);
	return (1);
}

void clear_stuff(t_philosopher *philos, t_infos *info)
{
    t_philosopher *tmp;

    tmp = philos;
    while (tmp)
    {
        ft_mutex(tmp->forchette, DESTROY);
        ft_mutex(tmp->meals_eaten_lock, DESTROY);
        ft_mutex(tmp->last_meal_lock, DESTROY);
        if (tmp->next == philos)
            break;
        tmp = tmp->next;
    }
	ft_mutex(info->end_mutex, DESTROY);
	ft_mutex(info->print_mutex, DESTROY);
}
int main(int ac, char **av)
{
	t_infos info; 
	t_philosopher *abtal;

	abtal = NULL;
	info.start_time = gettimestamp(MILLI);
	if (ac != 5 && ac != 6)
		ft_perror("Usage : NUM_PHILOS TIME_DIE TIME_EAT TIME_SLEEP");
	if (!parse_input(av, ac, &info))
		ft_perror("Error: Invalid Input");
	setup_data(&info, &abtal);
	create_threads(&abtal);
	// clear_stuff(abtal, &info);
	ft_malloc(0, 1);
}