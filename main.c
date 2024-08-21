/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:53:49 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/21 13:00:45 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

// ./philo  num_of_philos time_die time_eat time_sleep

void data_init(t_infos info, t_philosopher **philos)
{
	
}

int parse_input(char **data, int ac, t_infos *philo)
{
	int i;
	int j;

	i = 1;
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
	fill_struct(data, ac, philo);
	return (1);
}
int main(int ac, char **av)
{
	t_infos info; 
	t_philosopher *abtal;

	if (ac != 5 && ac != 6)
		ft_perror("Usage : NUM_PHILOS TIME_DIE TIME_EAT TIME_SLEEP");
	if (!parse_input(av, ac, &info))
		ft_perror("Enter a raw number that doesn't exceed INT_MAX");
	data_init(info, &abtal);
}