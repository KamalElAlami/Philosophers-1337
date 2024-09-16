/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/16 12:52:59 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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

void *routine_labtal(void *philo)
{
    t_philosopher *rijal;
    rijal = (t_philosopher *)philo;

    while (!rijal->info->end_simulation)
    {
        if (take_forks(rijal) || eat(rijal) || drop_forks(rijal)
            || sleepnthink(rijal) || check_meals(rijal) || rijal->info->end_simulation)
            break;
    }

    return NULL;
}
