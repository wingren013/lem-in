/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:00:52 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/21 17:51:13 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unseen.h>
#include <libft.h>
#include <printf.h>

void		addants(t_room *start)
{
	size_t	ants;
	size_t	antname;

	antname = 1;
	ants = g_antnumber;
	if (g_antnumber == 0)
	{
		ft_dprintf(2, "ERROR : ZERO ANTS\n");
		exit(2);
	}
	while (ants)
	{
		start->antnames[ants - 1] = antname;
		antname++;
		ants--;
	}
}

int			optimizearray(t_room **preroom, int i)
{
	t_room	*temp;

	temp = (*preroom)->link[0];
	(*preroom)->link[0] = (*preroom)->link[i];
	(*preroom)->link[i] = temp;
	i = 0;
	while ((*preroom)->link[i])
	{
		if ((*preroom)->link[i]->endstart == 2)
			break ;
		i++;
	}
	MALLOC_GUARD((*preroom)->link[i]);
	temp = (*preroom)->link[(*preroom)->linksize - 2];
	(*preroom)->link[(*preroom)->linksize - 2] = (*preroom)->link[i];
	(*preroom)->link[i] = temp;
	ft_printf("\n\nArray Optimized\n----------------\n\nSTART\n-----\n\n");
	return (1);
}

int			initialize(t_room **preroom)
{
	size_t	i;

	i = 0;
	while ((*preroom)->link[i])
	{
		if ((*preroom)->link[i]->endstart == 1)
			break ;
		i++;
	}
	MALLOC_GUARD((*preroom)->link[i]);
	(*preroom)->link[i]->ants = g_antnumber;
	if (0 == optimizearray(preroom, i))
	{
		ft_dprintf(2, "ERROR : ARRAY COULD NOT BE OPTIMIZED, END NOT FOUND\n");
		exit(EXIT_FAILURE);
	}
	addants((*preroom)->link[0]);
	return (1);
}
