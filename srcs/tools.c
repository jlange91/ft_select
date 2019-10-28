/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:34:29 by jlange            #+#    #+#             */
/*   Updated: 2019/10/28 10:34:58 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	resize_window(t_term *t, t_layout *l)
{
	int index;

	index = (l->pos[1] * l->nb_col) + l->pos[0];
	get_size_term(t);
	calc_layout(t, l);
	if (l->nb_col)
	{
		l->pos[0] = index % l->nb_col;
		l->pos[1] = index / l->nb_col;
		l->y_offset = 0;
	}
	print_args(l, t->height);
}

void	set_y_offset(t_layout *l, int t_height)
{
	while ((l->pos[1] - l->y_offset) < 0)
		l->y_offset -= 1;
	while ((l->pos[1] - l->y_offset) >= t_height)
		l->y_offset += 1;
}

int		layout_case_exist(t_layout *l, int x, int y)
{
	int pos;

	pos = (y * l->nb_col) + x;
	return (pos < l->nb_args) ? (1) : (0);
}

mode_t	get_type_file(char *str)
{
	struct stat s;

	return (lstat(str, &s)) ? (0) : (s.st_mode);
}

int		ft_poutchar(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}
