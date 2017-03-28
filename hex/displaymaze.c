/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaymaze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:00:49 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/21 17:42:32 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unseen.h>
#include <printf.h>
#include <libft.h>

int			g_str(char *buf)
{
	char	*ret;

	ft_asprintf(&ret, "%s%s\n", g_string, buf);
	free(g_string);
	g_string = ret;
	return (1);
}

void		displaymaze(void)
{
	size_t	i;
	size_t	l;

	l = 0;
	i = 0;
	ft_printf("\n\n--------------------------\n\n");
	ft_printf("%s", g_string);
	ft_printf("\n\n--------------------------\n\n");
}
