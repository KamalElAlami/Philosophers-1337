/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:47:40 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/17 23:58:55 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long gettimestamp(e_time unit)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    if (unit == MILLI)
        return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    else
        return ((tv.tv_sec * 1000000) + tv.tv_usec);
}


void ft_mutex(pthread_mutex_t *mutex, e_choices choice)
{
    if (choice == INIT)
        error_handler(pthread_mutex_init(mutex, NULL));
    else if (choice == LOCK)
        error_handler(pthread_mutex_lock(mutex));
    else if (choice == UNLOCK)
        error_handler(pthread_mutex_unlock(mutex));
    else if (choice == DESTROY)
        error_handler(pthread_mutex_destroy(mutex));
    else
        ft_perror("Incorrect MUTEX choice");  
}
void ft_pthread(pthread_t *thread, t_philosopher **philos, e_choices choice)
{
    if (choice == CREATE)
        error_handler(pthread_create(thread, NULL, routine_labtal, *philos));
    else if (choice == JOIN)
        error_handler(pthread_join(*thread, NULL));
    else if (choice == DETACH)
        error_handler(pthread_detach(*thread));
    else
        ft_perror("Incorrect pTHREAD choice");  
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
    (*info).end_simulation = 0;
    (*info).num_of_philos = ft_atoi(data[1]);
    (*info).time_to_die = ft_atoi(data[2]) * 1e3;
    (*info).time_to_eat = ft_atoi(data[3]) * 1e3;
    (*info).time_to_sleep = ft_atoi(data[4]) * 1e3;
    (*info).end_mutex = ft_malloc(sizeof(pthread_mutex_t), 0);
    ft_mutex((*info).end_mutex, INIT);  
    (*info).print_mutex = ft_malloc(sizeof(pthread_mutex_t), 0);
    ft_mutex((*info).print_mutex, INIT);  
}

int check_overflow(char *number)
{
    long nbr;
    
    nbr = 0;
    while (*number)
    {
        nbr = nbr * 10 + *number - '0';
        if (nbr > INT_MAX)
            return (0);
		number++;
    }
    return (1);
}
