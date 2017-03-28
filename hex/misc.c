/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:04:42 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/21 16:21:10 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unseen.h>
#include <libft.h>
#include <printf.h>
#include <limits.h>

char		*alt_parsename(char *buf)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = ft_strdup(buf);
	MALLOC_GUARD(ret);
	while (ret[i] && (ret[i] != ' '))
		i++;
	ret[i] = 0;
	while (i)
	{
		buf++;
		i--;
	}
	while (*buf && !ISDIGIT(*buf))
		buf++;
	if (!buf || !(ISDIGIT(*buf)))
	{
		ft_dprintf(2, "ERROR : INVALID INPUT");
		exit(2);
	}
	return (ret);
}

char		*parsename(char *buf)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = ft_strdup(buf);
	MALLOC_GUARD(ret);
	while (ret[i] && (ret[i] != '-'))
		i++;
	ret[i] = 0;
	return (ret);
}

void		setret(t_room **ret)
{
	(*ret)->linksize = 1;
	(*ret)->ants = 0;
	(*ret)->endstart = 0;
	(*ret)->blacklisted = 0;
	(*ret)->heat = ULONG_MAX;
	(*ret)->antnames = (int*)malloc(sizeof(int) * g_antnumber);
	ft_bzero((*ret)->antnames, sizeof(int) * g_antnumber);
}
