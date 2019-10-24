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

void                        ft_background_color(char c)
{
    if (c == 'a' || c == 'A')
        ft_putstr(BACK_BLACK);
    else if (c == 'b' || c == 'B')
        ft_putstr(BACK_RED);
    else if (c == 'c' || c == 'C')
        ft_putstr(BACK_GREEN);
    else if (c == 'd' || c == 'D')
        ft_putstr(BACK_YELLOW);
    else if (c == 'e' || c == 'E')
        ft_putstr(BACK_BLUE);
    else if (c == 'f' || c == 'F')
        ft_putstr(BACK_MAGENTA);
    else if (c == 'g' || c == 'G')
        ft_putstr(BACK_CYAN);
    else if (c == 'h' || c == 'H')
        ft_putstr(BACK_GREY);
}
static inline void            ft_text_color2(char c)
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
void                        ft_text_color(char c)
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
        ft_text_color2(c);
}

void	set_colors(mode_t type)
{
	char *str;
	size_t	i;

	i = 0;
	str = getenv("LSCOLORS");
	if ((type & S_IFMT) == S_IFBLK)
		i = 10;
	else if ((type & S_IFMT) == S_IFCHR)
		i = 12;
	else if ((type & S_IFMT) == S_IFDIR && (type & S_IFMT) == S_IWOTH)
	{
		if ((type & S_IFMT) == S_ISVTX)
			i = 18;
		else
			i = 20;
	}
	else if ((type & S_IFMT) == S_IFDIR)
		i = 0;
	else if ((type & S_IFMT) == S_IFIFO)
		i = 6;
	else if ((type & S_IFMT) == S_IFLNK)
		i = 2;
	else if ((type & S_IFMT) == S_IXUSR)
	{
		if ((type & S_IFMT) == S_ISGID)
			i = 16;
		else if ((type & S_IFMT) == S_ISUID)
			i = 14;
		else
			i = 8;
	}
	else if ((type & S_IFMT) == S_IFREG)
		;
	else if ((type & S_IFMT) == S_IFSOCK)
		i = 4;
	if (i < ft_strlen(str))
	{
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("\n", 2);
		ft_text_color(str[i]);
		ft_background_color(str[i + 1]);
	}
}
