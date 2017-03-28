/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:07:50 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/21 15:53:01 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unseen.h>
#include <printf.h>
#include <libft.h>

int			finishlink(t_room *room, t_room *linkroom)
{
	ft_printf("Finishing link between [%s || %p] and [%s || %p]\n",
			linkroom->roomname, linkroom, room->roomname, room);
	PR_REALC(linkroom->link, sizeof(t_room*) *
			(linkroom->linksize + 1), sizeof(t_room*) * linkroom->linksize);
	linkroom->link[linkroom->linksize - 1] = room;
	linkroom->linksize += 1;
	ft_printf("\n");
	return (1);
}

int			newlink(char *linkroom, t_room *room, t_room **preroom)
{
	size_t	i;

	i = 0;
	while ((*preroom)->link[i])
	{
		if (ft_strequ((*preroom)->link[i]->roomname, linkroom))
			break ;
		i++;
	}
	PR_REALC(room->link, (room->linksize + 1) *
			sizeof(t_room*), room->linksize * sizeof(t_room*));
	ft_printf("Creating link between ");
	ft_printf("[%s || %p] and ", room->roomname, room);
	room->link[room->linksize - 1] = (*preroom)->link[i];
	ft_printf("[%s || %p]\n", (*preroom)->link[i]->roomname,
			(*preroom)->link[i]);
	room->linksize += 1;
	MALLOC_GUARD(finishlink(room, (*preroom)->link[i]));
	return (1);
}

int			add_link(char *lf, char *buf, t_room **preroom)
{
	size_t	i;

	i = 0;
	while ((*preroom)->link[i])
	{
		if (ft_strequ((*preroom)->link[i]->roomname, lf))
		{
			while (*buf != '-' && *buf != 0)
				buf++;
			if (*buf != 0)
				buf++;
			MALLOC_GUARD(newlink(parsename(buf), (*preroom)->link[i], preroom));
			return (1);
		}
		i++;
	}
	return (0);
}
