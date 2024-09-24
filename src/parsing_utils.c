/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:54:50 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/24 17:34:34 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_validity(char **data)
{
	if ((ft_atoi(data[1]) > 200 || ft_atoi(data[1]) < 1)
		|| ft_atoi(data[2]) < 60 || ft_atoi(data[3]) < 60
		|| ft_atoi(data[4]) < 60 || ft_atoi(data[5]) == -1)
		return (0);
	return (1);
}

int	check_overflow(char *number)
{
	long	nbr;

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

int	parse_input(char **data, int ac, t_infos *philo)
{
	int	i;
	int	j;

	i = 1;
	if (!data[1] || !data[2] || !data[3] || !data[4])
		return (0);
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (!ft_isdigit(data[i][j]))
				return (0);
			j++;
		}
		if (!check_overflow(data[i]))
			return (0);
		i++;
	}
	if (!check_validity(data))
		return (0);
	fill_struct(data, ac, philo);
	return (1);
}
