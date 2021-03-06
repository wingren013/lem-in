/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jd_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:35:26 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/19 19:38:19 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t		jd_flag(intmax_t nb, char **ret)
{
	*ret = ft_itoa_base(nb, 10);
	return (ft_strlen(*ret));
}
