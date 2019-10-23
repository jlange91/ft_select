/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:46:54 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/23 14:52:00 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#include <unistd.h>

void	init_layout(int ac, char **av, t_layout *lay)
{
	lay->nb_col = 0;
	lay->nb_raw = 0;
	lay->col_len = 0;
	lay->pos[0] = 0;
	lay->pos[1] = 0;
	lay->param = NULL;
}
