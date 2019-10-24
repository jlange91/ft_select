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

int		init_layout(int ac, t_layout *l)
{
	l->nb_col = 0;
	l->nb_raw = 0;
	l->col_len = 0;
	l->pos[0] = 0;
	l->pos[1] = 0;
	l->nb_args = ac - 1;
	l->params = NULL;
	l->colors = getenv("LSCOLORS");
	return (0);
}
