/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/10 17:49:03 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

int check_death(t_philosopher *batal)
{
    ft_mutex(batal->info->end_mutex, LOCK);
    if (gettimestamp(MICRO) - batal->last_meal >= batal->info->time_to_die && batal->info->end_simulation == 0)
    {
        batal->info->end_simulation = 1;
        printf("%ld %d died\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        ft_mutex(batal->info->end_mutex, UNLOCK);
        return (1);
    }
    ft_mutex(batal->info->end_mutex, UNLOCK);
    return (0);
}


void *routine_labtal(void *philo)
{
    t_philosopher *rijal;
    rijal = (t_philosopher *)philo;

    while (!rijal->info->end_simulation)
    {
        if (take_forks(rijal))
            break;
        if (eat(rijal))
            break;
        if (drop_forks(rijal))
            break;
        if (sleepnthink(rijal))
            break;
        if ((rijal->info->meals != -1 && rijal->meals_eaten >= rijal->info->meals))
            break;
        if (rijal->info->end_simulation)
            break;
    }

    return NULL;
}
