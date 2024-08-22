/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:47:40 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/22 15:18:35 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void ft_mutex(pthread_mutex_t *mutex, e_choices choice)
{
    if (choice == INIT)
        error_handler(pthread_mutex_init(mutex, NULL));
    else if (choice == LOCK)
        error_handler(pthread_mutex_lock(mutex));
    else if (choice == UNLOCK)
        error_handler(pthread_mutex_unlock(mutex));
    else
        ft_perror("Incorrect MUTEX choice");  
}

void ft_perror(char *error_msg)
{
    printf(RED_COLOR"%s\n"RESET, error_msg);
    exit(EXIT_FAILURE);
}

void fill_struct(char **data, int ac, t_infos *info)
{
    if (ac == 6)
        (*info).meals = ft_atoi(data[5]);
    else
        (*info).meals = -1;
    (*info).num_of_philos = ft_atoi(data[1]);
    (*info).time_to_die = ft_atoi(data[2]) * 1e3;
    (*info).time_to_eat = ft_atoi(data[3]) * 1e3;
    (*info).time_to_sleep = ft_atoi(data[4]) * 1e3;
}

int check_overflow(char *number)
{
    long nbr;
    int sign;
    
    nbr = 0;
    sign = 1;
    
    while (*number)
    {
        nbr = nbr * 10 + *number - '0';
        if (nbr > INT_MAX)
            return (0);
		number++;
    }
    return (1);
}
