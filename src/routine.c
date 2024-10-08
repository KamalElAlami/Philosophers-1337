/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/24 18:04:29 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	freq_check(t_philosopher *rijal)
{
	t_philosopher	*clone;

	clone = rijal;
	while (clone)
	{
		if (check_death(clone))
			return (1);
		if (clone->next == rijal)
			break ;
		clone = clone->next;
	}
	return (0);
}

int	check_death(t_philosopher *batal)
{
	long	real_time;

	real_time = gettimestamp(MICRO) - get_lmeals_value(batal);
	if (real_time >= batal->info->time_to_die
		&& !get_simulation_value(batal->info))
	{
		set_simulation_value(batal->info, 1);
		print_state(batal, DIE);
		return (1);
	}
	return (0);
}

int	check_meals(t_philosopher *rijal)
{
	t_philosopher	*clone;
	int				count;

	if (rijal->info->meals == -1)
		return (0);
	clone = rijal;
	count = 0;
	while (clone)
	{
		if (get_cmeals_value(clone) < clone->info->meals)
			count++;
		if (clone->next == rijal)
			break ;
		clone = clone->next;
	}
	if (!count)
	{
		set_simulation_value(rijal->info, 2);
		return (1);
	}
	return (0);
}

void	one_batal(t_philosopher *rijal)
{
	if (rijal->info->num_of_philos == 1)
	{
		ft_usleep(rijal->info->time_to_die, rijal);
		set_simulation_value(rijal->info, 1);
	}
}

void	*routine_labtal(void *philo)
{
	t_philosopher	*rijal;

	rijal = (t_philosopher *)philo;
	while (!get_simulation_value(rijal->info))
	{
		if (take_forks(rijal))
		{
			one_batal(rijal);
			break ;
		}
		if (eat(rijal) || drop_forks(rijal)
			|| sleepnthink(rijal) || check_meals(rijal)
			|| get_simulation_value(rijal->info))
			break ;
	}
	return (NULL);
}
