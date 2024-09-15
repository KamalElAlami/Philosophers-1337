/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getterssetters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:41:36 by dedsec            #+#    #+#             */
/*   Updated: 2024/09/15 14:59:08 by dedsec           ###   ########.fr       */
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