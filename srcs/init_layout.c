/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:32:56 by jlange            #+#    #+#             */
/*   Updated: 2019/10/25 15:33:04 by jlange           ###   ########.fr       */
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
	l->y_offset = 0;
	l->nb_args = ac - 1;
	l->params = NULL;
	l->colors = getenv("LSCOLORS");
	return (0);
}
