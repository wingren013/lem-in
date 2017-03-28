/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:28:53 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/21 17:46:53 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>
#include <unseen.h>
#include <printf.h>
#include <fcntl.h>

#define NORMBS preroom->link[0] = 0; preroom->linksize = 1

t_room		*newroom(char *buf)
{
	t_room	*ret;

	NEWMALLOC(t_room, ret, 1);
	ft_bzero(ret, 1);
	ret->roomname = alt_parsename(buf);
	buf++;
	ft_printf("creating room %s", ret->roomname);
	while (*buf && !ISDIGIT(*buf))
		buf++;
	if (!(*buf))
		return (0);
	ret->xcord = ft_atoi_u(buf);
	ft_printf(" at %ld", ret->xcord);
	buf++;
	while (*buf && !ISDIGIT(*buf))
		buf++;
	if (!(*buf))
		return (0);
	ret->ycord = ft_atoi_u(buf);
	ft_printf(", %ld\n", ret->ycord);
	NEWMALLOC(t_room*, ret->link, 1);
	setret(&ret);
	ft_printf("room %s is %p\n\n", ret->roomname, ret);
	return (ret);
}

int			evaluatecomment(char *buf, t_room **preroom, int fd)
{
	if (ft_strequ(buf, "##start"))
	{
		PR_REALC((*preroom)->link, ((*preroom)->linksize + 1) *
				sizeof(t_room*), (*preroom)->linksize * sizeof(t_room*));
		get_next_line(fd, &buf);
		MALLOC_GUARD(g_str(buf));
		(*preroom)->link[(*preroom)->linksize - 1] = newroom(buf);
		MALLOC_GUARD((*preroom)->link[(*preroom)->linksize - 1]);
		(*preroom)->link[(*preroom)->linksize - 1]->endstart = 1;
		(*preroom)->linksize += 1;
		(*preroom)->link[(*preroom)->linksize - 1] = 0;
	}
	else if (ft_strequ(buf, "##end"))
	{
		PR_REALC((*preroom)->link, ((*preroom)->linksize + 1) *
				sizeof(t_room*), (*preroom)->linksize * sizeof(t_room*));
		get_next_line(fd, &buf);
		MALLOC_GUARD(g_str(buf));
		(*preroom)->link[(*preroom)->linksize - 1] = newroom(buf);
		MALLOC_GUARD((*preroom)->link[(*preroom)->linksize - 1]);
		(*preroom)->link[(*preroom)->linksize - 1]->endstart = 2;
		(*preroom)->linksize += 1;
		(*preroom)->link[(*preroom)->linksize - 1] = 0;
	}
	return (1);
}

int			builderino(t_room **preroom, char *buf)
{
	PR_REALC((*preroom)->link, ((*preroom)->linksize + 1) *
			sizeof(t_room*), (*preroom)->linksize * sizeof(t_room*));
	(*preroom)->link[(*preroom)->linksize - 1] = newroom(buf);
	MALLOC_GUARD((*preroom)->link[(*preroom)->linksize - 1]);
	(*preroom)->linksize += 1;
	(*preroom)->link[(*preroom)->linksize - 1] = 0;
	return (1);
}

t_room		*farmbuilder(int fd, char *buf, t_room *preroom)
{
	NEWMALLOC(t_room, preroom, 1);
	NEWMALLOC(t_room*, preroom->link, 1);
	NORMBS;
	while (get_next_line(fd, &buf) == 1)
	{
		g_str(buf);
		if (buf[0] == '#')
		{
			ERROR_GUARD(evaluatecomment(buf, &preroom, fd));
		}
		else if (!ft_strstr(buf, "-"))
		{
			MALLOC_GUARD(builderino(&preroom, buf));
		}
		else if (ft_strstr(buf, "-"))
		{
			ERROR_GUARD(add_link(parsename(buf), buf, &preroom));
		}
		else
		{
			ft_dprintf(2, "ERROR : INVALID INPUT\n");
			return (0);
		}
	}
	return (preroom);
}

int			main(void)
{
	char	*buf;
	t_room	*preroom;

	NEWMALLOC(char, g_string, 2);
	g_string[0] = 0;
	preroom = 0;
	if (get_next_line(0, &buf) != 1)
	{
		ft_dprintf(2, "ERROR : NO OR CORRUPTED INPUT\n");
		exit(EXIT_FAILURE);
	}
	MALLOC_GUARD(g_str(buf));
	g_antnumber = ft_atoi_u(buf);
	preroom = farmbuilder(0, buf, preroom);
	MALLOC_GUARD(preroom);
	displaymaze();
	if (initialize(&preroom) == 0)
	{
		ft_dprintf(2, "ERROR : START ROOM NOT FOUND\n");
		exit(EXIT_FAILURE);
	}
	if (pathfinder(preroom) == 0)
		ft_dprintf(2, "ERROR : MAZE COULD NOT BE COMPLETED\n");
	exit(EXIT_SUCCESS);
}
