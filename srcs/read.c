/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:33:51 by jlange            #+#    #+#             */
/*   Updated: 2019/10/28 10:53:26 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static inline void	list_actions(t_term *t, t_layout *l,
		char *buff, int nb_bytes)
{
	if (!ft_strcmp(ARROW_UP, buff))
		arrow_up_action(l, t);
	else if (!ft_strcmp(ARROW_DOWN, buff))
		arrow_down_action(l, t);
	else if (!ft_strcmp(ARROW_LEFT, buff))
		arrow_left_action(l, t->height);
	else if (!ft_strcmp(ARROW_RIGHT, buff))
		arrow_right_action(l, t->height);
	else if (!ft_strcmp(SPACE, buff))
		space_action(l, t->height);
	else if (!ft_strcmp(ENTER, buff))
	{
		ft_strdel(&buff);
		enter_action(l, t);
	}
	else if (nb_bytes == sizeof(char) && buff[0] == DELETE)
		delete_action(l, t, (l->pos[1] * l->nb_col) + l->pos[0]);
	else if (nb_bytes == sizeof(char) && buff[0] == ESC)
	{
		ft_strdel(&buff);
		ft_exit(0);
	}
}

int					read_stdin(t_term *t, t_layout *l)
{
	int		nb_bytes;
	char	*buff;
	char	stop;

	stop = 0;
	nb_bytes = 0;
	t = (t_term*)t;
	print_args(l, t->height);
	while (!stop)
	{
		ioctl(STDIN_FILENO, FIONREAD, &nb_bytes);
		if (nb_bytes <= 0)
			continue ;
		if (!(buff = ft_strnew(nb_bytes)))
			break ;
		if (read(STDIN_FILENO, buff, nb_bytes) != nb_bytes)
			stop = 1;
		list_actions(t, l, buff, nb_bytes);
		ft_strdel(&buff);
	}
	return (0);
}
