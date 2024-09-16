/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:48:25 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/16 15:48:06 by kael-ala         ###   ########.fr       */ 
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void print_state(t_philosopher *batal, e_state state)
{
    ft_mutex(batal->info->print_mutex, LOCK);
    if (!get_simulation_value(batal->info))
    {
        if (state == TAKE_FORK && !check_death(batal))
            printf("%ld %d has taken a fork\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == EAT && !check_death(batal))
            printf("%ld %d is eating\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == SLEEP && !check_death(batal))
            printf("%ld %d is sleeping\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == THINK && !check_death(batal))
            printf("%ld %d is thinking\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == DIE && !check_death(batal))
            printf("%ld %d died\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
    }
    ft_mutex(batal->info->print_mutex, UNLOCK);
}

int take_forks(t_philosopher *rijal)
{
    if (rijal->index % 2 != 0 && rijal->meals_eaten == 0) 
        ft_usleep(rijal->info->time_to_eat / 2, rijal);
    if (get_simulation_value(rijal->info))
        return (1);
    ft_mutex(rijal->forchette, LOCK);
    print_state(rijal, TAKE_FORK);
    if (get_simulation_value(rijal->info) || rijal->info->num_of_philos == 1)
        return (1);
    ft_mutex(rijal->next->forchette, LOCK);
    print_state(rijal, TAKE_FORK);
    return (0);
}

int eat(t_philosopher *rijal)
{
    if (get_simulation_value(rijal->info))
    {
        ft_mutex(rijal->forchette, UNLOCK);
        ft_mutex(rijal->next->forchette, UNLOCK);
        return (1);
    }
    print_state(rijal, EAT);
    rijal->last_meal = gettimestamp(MICRO);
    ft_usleep(rijal->info->time_to_eat, rijal);
    rijal->meals_eaten++;
    return (0);
}

int drop_forks(t_philosopher *rijal)
{
    if (get_simulation_value(rijal->info))
    {
        ft_mutex(rijal->forchette, UNLOCK);
        ft_mutex(rijal->next->forchette, UNLOCK);
        return (1);
    }
    ft_mutex(rijal->forchette, UNLOCK);
    ft_mutex(rijal->next->forchette, UNLOCK);
    return (0);
}

int sleepnthink(t_philosopher *rijal)
{
    if (get_simulation_value(rijal->info))
        return (1);
    print_state(rijal, SLEEP);
    ft_usleep(rijal->info->time_to_sleep, rijal);
    if (get_simulation_value(rijal->info))
        return (1);
    print_state(rijal, THINK);
    return (0);
}
