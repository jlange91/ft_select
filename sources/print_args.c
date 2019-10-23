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

void	print_args(t_layout *lay, t_param *params, size_t s)
{
	size_t	i;
	char	*tc;
	char	*move;
	char	*tcm;

	i = 0;
	tc = tgetstr("cl");
	tcm = tgetstr("cm");
	tputs(tc, STDIN_FILENO, ft_putchar);
	while (i < s)
	{
		move = tgoto(tcm, params[i].x, params[i].y);
		tputs(move, STDIN_FILENO, ft_putchar);
		if (params[i].selected)
		{
			//REVERSE VIDEO MODE
			tc = tgetstr("mr");
			tputs(tc, STDIN_FILENO, ft_putchar);
			//
		}
		if (lay->x == (i + 1) % lay->nb_raw && lay->y == (i + 1) / lay->nb_raw)
		{
			//UNDERLINED MODE
			tc = tgetstr("us");
			tputs(tc, STDIN_FILENO, ft_putchar);
			//
		}
		ft_putstr_fd(params[i].str, STDIN_FILENO);
		//EXIT STYLES MODE
		tc = tgetstr("me");
		tputs(tc, STDIN_FILENO, ft_putchar);
		tc = tgetstr("ue");
		tputs(tc, STDIN_FILENO, ft_putchar);
		//
		i++;
	}
}
