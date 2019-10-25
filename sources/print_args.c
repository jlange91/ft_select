/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:15:14 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/24 17:47:01 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static inline void print_colors(t_layout *l, int i)
{
	set_colors(l->colors, l->params[i].type);
	ft_putstr_fd(l->params[i].str, STDIN_FILENO);
	if (l->colors)
		ft_putstr_fd(RESET, STDIN_FILENO);
}

void	print_args(t_layout *l, int t_height)
{
	int		i;

	tputs(tgetstr("cl", NULL), STDIN_FILENO, ft_poutchar);
	if (l->nb_col == 0)
	{
		ft_putstr_fd("Term width is insufficient please resize window.\n", STDIN_FILENO);
		return ;
	}
	set_y_offset(l, t_height);
	i = l->y_offset * l->nb_col;
	while (i >= 0 && i < l->nb_args)
	{
		if ((l->params[i].t_y - l->y_offset) >= t_height)
			break ;
		tputs(tgoto(tgetstr("cm", NULL), l->params[i].t_x,
		 l->params[i].t_y - l->y_offset),
		 STDIN_FILENO, ft_poutchar);
		if (l->params[i].selected)
			tputs(tgetstr("mr", NULL), STDIN_FILENO, ft_poutchar);
		if (l->params[i].l_x == l->pos[0] && l->params[i].l_y == l->pos[1])
			tputs(tgetstr("us", NULL), STDIN_FILENO, ft_poutchar);
		print_colors(l, i);
		tputs(tgetstr("me", NULL), STDIN_FILENO, ft_poutchar);
		tputs(tgetstr("ue", NULL), STDIN_FILENO, ft_poutchar);
		i++;
	}
}
