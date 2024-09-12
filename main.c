/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:53:49 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/10 17:36:26 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

// ./philo  num_of_philos time_die time_eat time_sleep 

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
		ft_pthread(&(temp->thread), &temp, JOIN);
		temp = temp->next;
		i++;
	}
}

void setup_data(t_infos *info, t_philosopher **philos)
{
	int i;
	t_philosopher *tmp;
	i = 1;
	while (i <= (*info).num_of_philos)
		add_lbatal(philos, new_batal(i++, info));
	print_list(*philos);
	// return ;
	tmp = *philos;
	while (tmp->next)
	{
		tmp->forchette = malloc(sizeof(pthread_mutex_t));
		if (!tmp->forchette)
			ft_perror("Error: Somethings Wrong With Malloc");
		tmp->safty = malloc(sizeof(pthread_mutex_t));
		if (!tmp->safty)
			ft_perror("Error: Somethings Wrong With Malloc");
		ft_mutex(tmp->forchette, INIT);
		ft_mutex(tmp->safty, INIT);
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
	// printf("shared value is <======= %d =======>\n", info.end_simulation);
	// print_list(abtal);
}