/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getterandsetter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:23:16 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/15 22:23:38 by kael-ala         ###   ########.fr       */
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