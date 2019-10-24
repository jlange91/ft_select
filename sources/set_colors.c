/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:47:17 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/24 18:08:11 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static inline void            set_text_color2(char c)
{
    if (c == 'A')
        ft_putstr(D_GREY);
    else if (c == 'B')
        ft_putstr(B_RED);
    else if (c == 'C')
        ft_putstr(B_GREEN);
    else if (c == 'D')
        ft_putstr(YELLOW);
    else if (c == 'E')
        ft_putstr(B_BLUE);
    else if (c == 'F')
        ft_putstr(B_MAGENTA);
    else if (c == 'G')
        ft_putstr(B_CYAN);
    else if (c == 'H')
        ft_putstr(WHITE);
}
void                        set_text_color(char c)
{
    if (c == 'a')
        ft_putstr(BLACK);
    else if (c == 'b')
        ft_putstr(RED);
    else if (c == 'c')
        ft_putstr(GREEN);
    else if (c == 'd')
        ft_putstr(BROWN);
    else if (c == 'e')
        ft_putstr(BLUE);
    else if (c == 'f')
        ft_putstr(MAGENTA);
    else if (c == 'g')
        ft_putstr(CYAN);
    else if (c == 'h')
        ft_putstr(GREY);
    else
        set_text_color2(c);
}

void	set_colors(char *colors, mode_t type)
{
	size_t	i;
	mode_t	mode;

	i = -1;
	if (!colors)
		return ;
	mode = type & 0xF000;
	if ((mode ^ S_IFDIR) == 0)
		i = 0;
	else if ((mode ^ S_IFLNK) == 0)
		i = 2;
	else if ((mode ^ S_IFSOCK) == 0)
		i = 4;
	else if ((mode ^ S_IFIFO) == 0)
		i = 6;
	else if ((mode ^ S_IFBLK) == 0)
		i = 10;
	else if ((mode ^ S_IFCHR) == 0)
		i = 12;
	else if ((type & S_ISUID) && (type & 0111))
		i = 14;
	else if ((type & S_ISGID) && (type & 0111))
		i = 16;
	else if (type & 0111)
		i = 8;
	else if ((type & S_ISVTX) && (type & 02) && (mode ^ S_IFDIR) == 0)
		i = 18;
	else if ((type & 02) && (mode ^ S_IFDIR) == 0)
		i = 20;
	if (i >= 0 && i < ft_strlen(colors))
		set_text_color(colors[i]);
}
