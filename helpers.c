/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:01:02 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/21 13:18:14 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

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

void add_last(t_philosopher **head, t_philosopher *node)
{
    t_philosopher *tmp;

    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    
}