/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:47:40 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/20 02:37:40 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void fill_struct(char **data, int ac, t_infos *info)
{
    if (ac == 6)
        (*info).meals = ft_atoi(data[6]);
    else
        (*info).meals = -1;
    (*info).num_of_philos = ft_atoi(data[1]);
    (*info).time_to_die = ft_atoi(data[2]);
    (*info).time_to_eat = ft_atoi(data[3]);
    (*info).time_to_sleep = ft_atoi(data[4]);
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
