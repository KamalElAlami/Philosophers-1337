/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:54:50 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/10 13:05:11 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

int check_validity(char **data)
{
    if ((ft_atoi(data[1]) > 200 && ft_atoi(data[1]) < 1)|| ft_atoi(data[2]) < 60 || ft_atoi(data[3]) < 60 || ft_atoi(data[4]) < 60)
        return (0);
    return (1);
}