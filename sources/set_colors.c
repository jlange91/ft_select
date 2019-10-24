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

void	set_colors(mode_t type)
{
	char *str;
	size_t	i;

	i = 0;
	str = ft_strdup("Gxfxcxdxbxegedabagacad");
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
		ft_text_color(str[i]);
		ft_background_color(str[i + 1]);
	}
}
