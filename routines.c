/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/26 18:44:30 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"


void print_state(int index, t_infos *info, e_state state)
{
    if (!info->end_simulation)
    {
        if (state == TAKE_FORK)
            printf("%ld %d has taken a fork\n", gettimestamp() - info->start_time, index);
        else if (state == EAT)
            printf("%ld %d is Eating\n", gettimestamp() - info->start_time, index);
        else if (state == SLEEP)
            printf("%ld %d is Sleeping\n", gettimestamp() - info->start_time, index);
        else if (state == THINK)
            printf("%ld %d is Thinking\n", gettimestamp() - info->start_time, index);
        else if (state == DIE)
            printf("%ld %d is Died\n", gettimestamp() - info->start_time, index);
        
    }
}


void *routine_labtal(void *abtal)
{
    t_philosopher *rijal = (t_philosopher *)abtal;
    while (!rijal->info->end_simulation)
    {
        // Taking forks
        ft_mutex(rijal->forchette, LOCK);
        print_state(rijal->index, rijal->info, TAKE_FORK);
        ft_mutex(rijal->next->forchette, LOCK);
        print_state(rijal->index, rijal->info, TAKE_FORK);

        // Eating
        print_state(rijal->index, rijal->info, EAT);
        rijal->last_meal = gettimestamp();
        rijal->meals_eaten++;
        usleep(rijal->info->time_to_eat);  // Convert to microseconds

        // Dropping forks
        ft_mutex(rijal->forchette, UNLOCK);
        ft_mutex(rijal->next->forchette, UNLOCK);

        // Sleeping
        print_state(rijal->index, rijal->info, SLEEP);
        usleep(rijal->info->time_to_sleep);  // Convert to microseconds

        // Thinking
        print_state(rijal->index, rijal->info, THINK);

        // Death check
        if (gettimestamp() - rijal->last_meal >= rijal->info->time_to_die ||
            (rijal->info->meals != -1 && rijal->meals_eaten >= rijal->info->meals))
            {
                ft_mutex(rijal->info->end_mutex, LOCK);
                rijal->info->end_simulation = 1;
                ft_mutex(rijal->info->end_mutex, LOCK);
            }
        if (rijal->index != 1)
            printf("enddd => %d\n", rijal->info->end_simulation);
        if ((gettimestamp() - rijal->last_meal) >= rijal->info->time_to_die)
            print_state(rijal->index, rijal->info, DIE);
    }
    return NULL;
}
