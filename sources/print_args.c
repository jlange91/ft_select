/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:15:14 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/23 15:59:11 by thdelmas         ###   ########.fr       */
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
	tputs(tc, 1, (int (*)(int))ft_putchar);
	tc = tgetstr("cl", NULL);
	tcm = tgetstr("cm", NULL);
	tputs(tc, STDIN_FILENO, (int (*)(int))ft_putchar);
	while (i < lay->nb_args)
	{
		move = tgoto(tcm, lay->params[i].t_x, lay->params[i].t_y);
		tputs(move, STDIN_FILENO, (int (*)(int))ft_putchar);
		if (lay->params[i].selected)
		{
			//REVERSE VIDEO MODE
			tc = tgetstr("mr", NULL);
			tputs(tc, STDIN_FILENO, (int (*)(int))ft_putchar);
			//
		}
		if (lay->params[i].l_x == lay->pos[0] && lay->params[i].l_y == lay->pos[1])
		{
			//UNDERLINED MODE
			tc = tgetstr("us", NULL);
			tputs(tc, STDIN_FILENO, (int (*)(int))ft_putchar);
			//
		}
		ft_putstr_fd(lay->params[i].str, STDIN_FILENO);
		//EXIT STYLES MODE
		tc = tgetstr("me", NULL);
		tputs(tc, STDIN_FILENO, (int (*)(int))ft_putchar);
		tc = tgetstr("ue", NULL);
		tputs(tc, STDIN_FILENO, (int (*)(int))ft_putchar);
		//
		i++;
	}
}