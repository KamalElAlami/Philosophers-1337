/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:01:02 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/16 19:26:52 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int error_handler(int error)
{
    if (error == 0)
        return (0);
    else if (error == EAGAIN)
        ft_perror("Error: Insufficient resources to initialize mutex");
    else if (error == EINVAL)
        ft_perror("Error: Invalid argument");
    else if (error == EPERM)
        ft_perror("Error: Insufficient memory to initialize mutex");
    else if (error == ESRCH)
        ft_perror("Error: No thread could be found");
    else if (error == EDEADLK)
        ft_perror("Error: A deadlock would occur");
    else if (error == ENOMEM)
        ft_perror("Error: Insufficient memory to initialize mutex");
    else if (error == EBUSY)
        ft_perror("Error: The mutex is currently locked");
    else if (error == ETIMEDOUT)
        ft_perror("Error: Insufficient resources to initialize mutex");
    else
        ft_perror("Error: Unknown Error");
    return (error);
}

t_philosopher *new_batal(int index, t_infos *info)
{
    t_philosopher *node;
    
    node = ft_malloc(sizeof(t_philosopher), 0);
    node->index = index;
    node->last_meal = gettimestamp(MICRO);
    node->meals_eaten = 0;
    node->info = info;
    return (node);
}

void add_lbatal(t_philosopher **head, t_philosopher *node)
{
    t_philosopher *tmp;
    if (!*head)
    {
        *head = node; 
        node->next = *head;
    }
    tmp = *head;
    while (tmp->next)
    {
        if (tmp->next == *head)
            break ;
        tmp = tmp->next;
    }
    tmp->next = node;
    node->next = *head;    
}

void ft_usleep(long microseconds, t_philosopher *rijal)
{
    long start;
    long current;

    start = gettimestamp(MICRO);
    while (1)
    {
        current = gettimestamp(MICRO);
        if (current - start >= microseconds || check_death(rijal))
            break;
        usleep(50);
    }
}