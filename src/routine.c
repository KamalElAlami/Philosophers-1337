/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/15 15:17:29 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_death(t_philosopher *batal)
{
    // ft_mutex(batal->info->end_mutex, LOCK);
    if (gettimestamp(MICRO) - batal->last_meal >= batal->info->time_to_die && !get_simulation_value(batal->info))
    {
        set_simulation_value(batal->info, 1);
        print_state(batal, DIE);
        // ft_mutex(batal->info->end_mutex, UNLOCK);
        return (1);
    }
    // ft_mutex(batal->info->end_mutex, UNLOCK);
    return (0);
}


void *routine_labtal(void *philo)
{
    t_philosopher *rijal;
    rijal = (t_philosopher *)philo;

    while (!get_simulation_value(rijal->info))
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
        if (get_simulation_value(rijal->info))
            break;
    }

    return NULL;
}
