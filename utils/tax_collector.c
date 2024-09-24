/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tax_collector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:23:13 by dedsec            #+#    #+#             */
/*   Updated: 2024/09/24 17:29:53 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	collect_taxes(t_collector **taxes)
{
	t_collector	*current;
	t_collector	*temp;

	if (!taxes || !*taxes)
		return ;
	current = *taxes;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->ptr);
		free(temp);
	}
	*taxes = NULL;
}

static void	appand_taxes(t_collector **taxes, void *ptr)
{
	t_collector	*new_tax;

	new_tax = malloc(sizeof(t_collector));
	if (!new_tax)
		return ;
	new_tax->ptr = ptr;
	new_tax->next = *taxes;
	*taxes = new_tax;
}

void	*ft_malloc(size_t size, int flag)
{
	static t_collector	*taxes;
	void				*ptr;

	if (flag == 0)
	{
		ptr = malloc(size);
		if (!ptr)
			return (NULL);
		appand_taxes(&taxes, ptr);
		return (ptr);
	}
	else
		collect_taxes(&taxes);
	return (NULL);
}
