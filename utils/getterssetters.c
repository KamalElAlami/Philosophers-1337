/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getterssetters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:41:36 by dedsec            #+#    #+#             */
/*   Updated: 2024/09/18 23:41:41 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int get_simulation_value(t_infos *info)
{
    int value;

    ft_mutex(info->end_mutex, LOCK);
    value = info->end_simulation;
    ft_mutex(info->end_mutex, UNLOCK);
    return (value);
}

void set_simulation_value(t_infos *infos, int value)
{
    ft_mutex(infos->end_mutex, LOCK);
    infos->end_simulation = value;
    ft_mutex(infos->end_mutex, UNLOCK);
}

long get_lmeals_value(t_philosopher *rijal)
{
    long value;

    ft_mutex(rijal->last_meal_lock, LOCK);
    value = rijal->last_meal;
    ft_mutex(rijal->last_meal_lock, UNLOCK);
    return (value);
}

void set_lmeals_value(t_philosopher *rijal, long timee)
{
    ft_mutex(rijal->last_meal_lock, LOCK);
    rijal->last_meal = timee;
    ft_mutex(rijal->last_meal_lock, UNLOCK);
}
int get_cmeals_value(t_philosopher *rijal)
{
    int value;

    ft_mutex(rijal->meals_eaten_lock, LOCK);
    value = rijal->meals_eaten;
    ft_mutex(rijal->meals_eaten_lock, UNLOCK);
    return (value);
}

void set_cmeals_value(t_philosopher *rijal)
{
    ft_mutex(rijal->meals_eaten_lock, LOCK);
    rijal->meals_eaten++;
    ft_mutex(rijal->meals_eaten_lock, UNLOCK);
}