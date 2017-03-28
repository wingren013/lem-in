/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:59:29 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/22 12:35:47 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unseen.h>
#include <printf.h>
#include <limits.h>

#define ANTCON (room->link[i]->link[l]->ants == 0 || ANTI)
#define ANTI room->link[i]->link[l]->heat == 0
#define HEAT room->link[i]->heat
#define MOVECON (room->link[i]->link[moveto]->heat < HEAT && MOVETWO)
#define MOVETWO (room->link[i]->link[moveto]->ants == 0 || ENDROOM)
#define ENDROOM (room->link[i]->link[moveto]->heat == 0)
#define ARGS room->antnames[i], moveto->roomname
#define CHECKLIST room->link[i]->link[l]->blacklisted == 0
#define HEATCHECK room->link[i]->link[l]->heat < heattobeat
#define MOVETOBLACK room->link[i]->link[moveto]->blacklisted == 0
#define ENDLOOP l = 0; i++
#define STARTLOOP heattobeat = room->link[i]->heat; moveto = l
#define VALIDCHECK room->link[i]->ants != 0 && VALIDTWO
#define VALIDTWO room->link[i]->heat != 0 && VALIDTHREE
#define VALIDTHREE room->link[i]->blacklisted == 0
#define BLACKLIST if (moveto->heat != 0) moveto->blacklisted = 1

void		heatmap(t_room *room, size_t newheat)
{
	size_t	i;

	i = 0;
	if (room->heat > newheat)
	{
		room->heat = newheat;
		while (i < room->linksize - 1)
		{
			heatmap(room->link[i], newheat + 1);
			i++;
		}
	}
}

void		moveant(t_room *room, t_room *moveto, size_t i)
{
	size_t	l;

	l = 0;
	while (i < g_antnumber)
	{
		if (room->antnames[i])
		{
			while (l < g_antnumber)
			{
				if (moveto->antnames[l] == 0)
				{
					moveto->antnames[l] = room->antnames[i];
					ft_printf("L%d-%s ", ARGS);
					room->antnames[i] = 0;
					BLACKLIST;
					room->ants -= 1;
					moveto->ants += 1;
					return ;
				}
				l++;
			}
		}
		l = 0;
		i++;
	}
}

void		pathfind(t_room *room, size_t i, size_t l)
{
	size_t	heattobeat;
	size_t	moveto;

	while (i < room->linksize - 1)
	{
		STARTLOOP;
		if (VALIDCHECK)
		{
			while (l < room->link[i]->linksize - 1)
			{
				if (HEATCHECK && CHECKLIST && ANTCON)
				{
					heattobeat = room->link[i]->link[l]->heat;
					moveto = l;
				}
				l++;
			}
			if ((MOVETOBLACK || ENDROOM) && MOVECON)
			{
				moveant(room->link[i], room->link[i]->link[moveto], 0);
				i--;
			}
		}
		ENDLOOP;
	}
}

int			pathfinder(t_room *preroom)
{
	size_t	i;

	heatmap(preroom->link[preroom->linksize - 2], 0);
	if (preroom->link[0]->heat == ULONG_MAX)
		return (0);
	preroom->link[0]->heat = ULONG_MAX;
	while (preroom->link[preroom->linksize - 2]->ants < g_antnumber)
	{
		i = 0;
		while (i < preroom->linksize - 1)
		{
			preroom->link[i]->blacklisted = 0;
			i++;
		}
		pathfind(preroom, 0, 0);
		ft_printf("\n");
	}
	return (1);
}
