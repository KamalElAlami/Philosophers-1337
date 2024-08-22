/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:01:02 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/22 15:10:58 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void error_handler(int error)
{
    if (error == EAGAIN)
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
}

t_philosopher *new_batal(int index)
{
    t_philosopher *node;
    
    node = malloc(sizeof(t_philosopher));
    node->index = index;
    node->flag = 0;
    node->fork = 0;
    node->last_meal = 0;
    node->meals_eaten = 0;
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
    while (tmp->next != *head)
        tmp = tmp->next;
    tmp->next = node;
    node->next = *head;    
}

void print_list(t_philosopher *list)
{
    t_philosopher *tmp;

    tmp = list;
    while (tmp->next != list)
    {
        printf("index => %d\n", tmp->index);
        tmp = tmp->next;
    }
}