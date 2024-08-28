/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/29 00:38:29 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

int check_death(t_philosopher *batal)
{
    ft_mutex(batal->info->end_mutex, LOCK);
    if (gettimestamp(MICRO) - batal->last_meal >= batal->info->time_to_die && batal->info->end_simulation == 0)
    {
        batal->info->end_simulation = 1;
        ft_mutex(batal->info->end_mutex, UNLOCK);
        return (1);
    }
    ft_mutex(batal->info->end_mutex, UNLOCK);
    return (0);
}

void ft_usleep(long microseconds)
{
    long start;
    long current;

    start = gettimestamp(MICRO);
    while (1)
    {
        current = gettimestamp(MICRO);
        if (current - start >= microseconds)
            break;
        usleep(100);
    }
}


void print_state(t_philosopher *batal, e_state state)
{
    ft_mutex(batal->info->print_mutex, LOCK);
    if (!batal->info->end_simulation)
    {
        if (state == TAKE_FORK )
            printf("%ld %d has taken a fork\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == EAT )
            printf("%ld %d is eating\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == SLEEP )
            printf("%ld %d is sleeping\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == THINK )
            printf("%ld %d is thinking\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        else if (state == DIE )
            printf("%ld %d died\n", gettimestamp(MILLI) - batal->info->start_time, batal->index);
        
    }
    ft_mutex(batal->info->print_mutex, UNLOCK);
}

void *routine_labtal(void *philo)
{
    t_philosopher *rijal;
    rijal = (t_philosopher *)philo;

    while (1)
    {
        ft_mutex(rijal->safty, LOCK);
        // Khud l-forchettes
        if (rijal->index % 2 == 0) {
            ft_mutex(rijal->forchette, LOCK);
            print_state(rijal, TAKE_FORK);
            ft_mutex(rijal->next->forchette, LOCK);
            print_state(rijal, TAKE_FORK);
        } else {
            ft_mutex(rijal->next->forchette, LOCK);
            print_state(rijal, TAKE_FORK);
            ft_mutex(rijal->forchette, LOCK);
            print_state(rijal, TAKE_FORK);
        }

        // Kul
        print_state(rijal, EAT);
        rijal->last_meal = gettimestamp(MICRO);
        ft_usleep(rijal->info->time_to_eat);
        rijal->meals_eaten++;

        ft_mutex(rijal->forchette, UNLOCK);
        ft_mutex(rijal->next->forchette, UNLOCK);
        // N3ass
        print_state(rijal, SLEEP);
        ft_usleep(rijal->info->time_to_sleep);

        // Fkar
        print_state(rijal, THINK);

        // Check wach kaml l-meals dyalu
        if ((rijal->info->meals != -1 && rijal->meals_eaten >= rijal->info->meals) || check_death(rijal))
            break;
        ft_mutex(rijal->safty, UNLOCK);
    }

    return NULL;
}