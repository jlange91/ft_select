/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:46:54 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/23 15:14:35 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#include <unistd.h>

int		init_layout(int ac, char **av, t_layout *l)
{
	l->nb_col = 0;
	l->nb_raw = 0;
	l->col_len = 0;
	l->pos[0] = 1;
	l->pos[1] = 1;
	l->nb_args = ac - 1;
	if (!(l->params = init_params(ac, av)))
	{
		ft_putendl_fd("ft_select: init_params: malloc_error", STDERR_FILENO);
		return(1);
	}
	return (0);
}
