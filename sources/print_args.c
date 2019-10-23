/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:15:14 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/23 15:20:38 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_args(t_param *params, size_t s)
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
		i++;
	}
}
