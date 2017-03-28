/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_realc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:00:03 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/14 18:49:19 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unseen.h>
#include <libft.h>

t_room		**link_realc(t_room **room, size_t size)
{
	t_room	**newroom;

	newroom = malloc(size + 1);
	MALLOC_GUARD(newroom);
	ft_memcpy(newroom, room, size);
	free(room);
	return (newroom);
}
