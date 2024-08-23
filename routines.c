/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:50:43 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/23 15:57:19 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <./includes/philosophers.h> 



void *routine_labtal(void *abtal)
{
    t_philosopher *rijal;

    rijal = (t_philosopher *)abtal;
    while (1)
    {
        //taking fork
        //take_fork();
        if (!(rijal->fork))
        {
            ft_mutex(rijal->forchette, LOCK);
            printf("%ld %d has take a fork\n", rijal->info.start_time - gettimestamp(), rijal->index);
            rijal->fork = 1;
        }
        if (!rijal->next->fork)
        {
            ft_mutex(rijal->forchette, LOCK);
            printf("%ld %d has take a fork\n", rijal->info.start_time - gettimestamp(), rijal->index);
            rijal->next->fork = 1;
        }
        if (rijal->fork && rijal->next->fork)
            rijal->has_forks = 1;
        //eating
        // start_eating();
        if (rijal->has_forks)
        {
            printf("%ld %d is eating\n", rijal->info.start_time - gettimestamp(), rijal->index);
            rijal->last_meal = gettimestamp();
            rijal->meals_eaten++;
            usleep(rijal->info.time_to_eat);
        }
        //drop the fork
        ft_mutex(rijal->forchette, UNLOCK);
        ft_mutex(rijal->next->forchette, UNLOCK);
        //sleepin
        printf("%ld %d is sleeping\n", rijal->info.start_time - gettimestamp(), rijal->index);
        usleep(rijal->info.time_to_sleep);
        //thinking
        printf("%ld %d is Thinking\n", rijal->info.start_time - gettimestamp(), rijal->index);
        //death check
        if (rijal->last_meal >= rijal->info.time_to_die || rijal->info.meals != -1 && (rijal->meals_eaten >= rijal->info.meals))
        {
            printf("%ld %d is Died\n", rijal->info.start_time - gettimestamp(), rijal->index);
            break ;
        }
    }
}
