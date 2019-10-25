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

void	print_args(t_layout *lay)
{
	int		i;
	char	*tc;
	char	*move;
	char	*tcm;

	i = 0;
	tc = tgetstr("cl", NULL);
	tputs(tc, 1, ft_poutchar);
	tcm = tgetstr("cm", NULL);
	tputs(tc, STDIN_FILENO, ft_poutchar);
	while (i < lay->nb_args)
	{
		move = tgoto(tcm, lay->params[i].t_x, lay->params[i].t_y);
		tputs(move, STDIN_FILENO, ft_poutchar);
		if (lay->params[i].selected)
		{
			//REVERSE VIDEO MODE
			tc = tgetstr("mr", NULL);
			tputs(tc, STDIN_FILENO, ft_poutchar);
		}
		if (lay->params[i].l_x == lay->pos[0] && lay->params[i].l_y == lay->pos[1])
		{
			//UNDERLINED MODE
			tc = tgetstr("us", NULL);
			tputs(tc, STDIN_FILENO, ft_poutchar);
		}
		set_colors(lay->colors, lay->params[i].type);
		ft_putstr_fd(lay->params[i].str, STDIN_FILENO);
		//EXIT STYLES MODE
		if (lay->colors)
			ft_putstr_fd(RESET, STDIN_FILENO);
		tc = tgetstr("me", NULL);
		tputs(tc, STDIN_FILENO, ft_poutchar);
		tc = tgetstr("ue", NULL);
		tputs(tc, STDIN_FILENO, ft_poutchar);
		//
		i++;
	}
}
