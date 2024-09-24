/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getterssetters2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:07:36 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/24 17:08:15 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_cmeals_value(t_philosopher *rijal)
{
	int	value;

	ft_mutex(rijal->meals_eaten_lock, LOCK);
	value = rijal->meals_eaten;
	ft_mutex(rijal->meals_eaten_lock, UNLOCK);
	return (value);
}

void	set_cmeals_value(t_philosopher *rijal)
{
	ft_mutex(rijal->meals_eaten_lock, LOCK);
	rijal->meals_eaten++;
	ft_mutex(rijal->meals_eaten_lock, UNLOCK);
}
