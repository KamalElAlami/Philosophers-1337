/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/16 15:57:20 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_death(t_philosopher *batal)
{
    if (gettimestamp(MICRO) - batal->last_meal >= batal->info->time_to_die && !get_simulation_value(batal->info))
    {
        set_simulation_value(batal->info, 1);
        printf("%ld %d died\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        return (1);
    }
    return (0);
}

int check_meals(t_philosopher *rijal)
{
    t_philosopher *clone;
    int count;

    if (rijal->info->meals == -1)
        return (0);
    clone = rijal;
    count = 0;
    while (clone)
    {
        if (clone->meals_eaten < clone->info->meals)
            count++;
        if (clone->next == rijal)
            break ;
        clone = clone->next;
    }
    if (!count)
        return (1);
    return (0);
}

void one_batal(t_philosopher *rijal)
{
    if (rijal->info->num_of_philos == 1)
    {
        ft_usleep(rijal->info->time_to_die, rijal);
        printf("%ld %d died\n", gettimestamp(MILLI) - rijal->info->start_time, rijal->index);
    }
}

void *routine_labtal(void *philo)
{
    t_philosopher *rijal;
    rijal = (t_philosopher *)philo;

    while (!get_simulation_value(rijal->info))
    {
        if (take_forks(rijal))
        {
            one_batal(rijal);
            break ;
        }
        if (eat(rijal) || drop_forks(rijal)
            || sleepnthink(rijal) || check_meals(rijal) || get_simulation_value(rijal->info))
            break;
    }

    return NULL;
}
