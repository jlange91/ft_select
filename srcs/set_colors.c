/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:34:04 by jlange            #+#    #+#             */
/*   Updated: 2019/10/28 10:37:18 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static inline void		set_text_color2(char c)
{
	if (c == 'A')
		ft_putstr_fd(D_GREY, STDIN_FILENO);
	else if (c == 'B')
		ft_putstr_fd(B_RED, STDIN_FILENO);
	else if (c == 'C')
		ft_putstr_fd(B_GREEN, STDIN_FILENO);
	else if (c == 'D')
		ft_putstr_fd(YELLOW, STDIN_FILENO);
	else if (c == 'E')
		ft_putstr_fd(B_BLUE, STDIN_FILENO);
	else if (c == 'F')
		ft_putstr_fd(B_MAGENTA, STDIN_FILENO);
	else if (c == 'G')
		ft_putstr_fd(B_CYAN, STDIN_FILENO);
	else if (c == 'H')
		ft_putstr_fd(WHITE, STDIN_FILENO);
}
static inline void		set_text_color(char c)
{
	if (c == 'a')
		ft_putstr_fd(BLACK, STDIN_FILENO);
	else if (c == 'b')
		ft_putstr_fd(RED, STDIN_FILENO);
	else if (c == 'c')
		ft_putstr_fd(GREEN, STDIN_FILENO);
	else if (c == 'd')
		ft_putstr_fd(BROWN, STDIN_FILENO);
	else if (c == 'e')
		ft_putstr_fd(BLUE, STDIN_FILENO);
	else if (c == 'f')
		ft_putstr_fd(MAGENTA, STDIN_FILENO);
	else if (c == 'g')
		ft_putstr_fd(CYAN, STDIN_FILENO);
	else if (c == 'h')
		ft_putstr_fd(GREY, STDIN_FILENO);
	else
		set_text_color2(c);
}

static inline void		set_i(mode_t type, mode_t mode, int *i)
{
	if ((mode ^ S_IFDIR) == 0)
		*i = 0;
	else if ((mode ^ S_IFLNK) == 0)
		*i = 2;
	else if ((mode ^ S_IFSOCK) == 0)
		*i = 4;
	else if ((mode ^ S_IFIFO) == 0)
		*i = 6;
	else if ((mode ^ S_IFBLK) == 0)
		*i = 10;
	else if ((mode ^ S_IFCHR) == 0)
		*i = 12;
	else if ((type & S_ISUID) && (type & 0111))
		*i = 14;
	else if ((type & S_ISGID) && (type & 0111))
		*i = 16;
	else if (type & 0111)
		*i = 8;
	else if ((type & S_ISVTX) && (type & 02) && (mode ^ S_IFDIR) == 0)
		*i = 18;
	else if ((type & 02) && (mode ^ S_IFDIR) == 0)
		*i = 20;
}

void					set_colors(char *colors, mode_t type)
{
	int		i;
	mode_t	mode;

	i = -1;
	if (!colors)
		return ;
	mode = type & 0xF000;
	set_i(type, mode, &i);
	if (i >= 0 && (size_t)i < ft_strlen(colors))
		set_text_color(colors[i]);
}
