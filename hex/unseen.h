/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unseen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:56:27 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/21 14:57:11 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSEEN_H
# define UNSEEN_H

# include <stdio.h>

# define ERROR_GUARD(x) if(!x){ perror("ERROR"); return (0);}
# define GLEN (ft_strlen(g_string) + ft_strlen(buf) + 1)

typedef struct		s_room {
	struct s_room	**link;
	size_t			linksize;
	char			*roomname;
	char			endstart;
	char			blacklisted;
	size_t			ants;
	size_t			xcord;
	size_t			ycord;
	int				*antnames;
	size_t			heat;
}					t_room;

extern size_t		g_antnumber;
extern size_t		g_currentroom;
extern size_t		g_antname;
extern char			*g_string;

int					initialize(t_room **preroom);
int					pathfinder(t_room *preroom);
t_room				**link_realc(t_room **room, size_t size);
void				displaymaze(void);
char				*alt_parsename(char *buf);
char				*parsename(char *buf);
void				setret(t_room **ret);
int					finishlink(t_room *room, t_room *linkroom);
int					newlink(char *linkroom, t_room *room, t_room **preroom);
int					add_link(char *lf, char *buf, t_room **preroom);
int					g_str(char *buf);

#endif
