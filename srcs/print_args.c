/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:33:42 by jlange            #+#    #+#             */
/*   Updated: 2019/10/28 10:18:30 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static inline void	print_colors(t_layout *l, int i)
{
	set_colors(l->colors, l->params[i].type);
	ft_putstr_fd(l->params[i].str, STDIN_FILENO);
	if (l->colors)
		ft_putstr_fd(RESET, STDIN_FILENO);
}

int					print_arg(t_layout *l, int t_height, int i)
{
	if ((l->params[i].t_y - l->y_offset) >= t_height)
		return (1);
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
	return (0);
}

void				print_args(t_layout *l, int t_height)
{
	int		i;

	tputs(tgetstr("cl", NULL), STDIN_FILENO, ft_poutchar);
	if (l->nb_col == 0)
	{
		ft_putstr_fd("Term width is insufficient please resize window.\n",
				STDIN_FILENO);
		return ;
	}
	set_y_offset(l, t_height);
	i = l->y_offset * l->nb_col;
	while (i >= 0 && i < l->nb_args)
	{
		if (print_arg(l, t_height, i))
			break ;
		i++;
	}
}
