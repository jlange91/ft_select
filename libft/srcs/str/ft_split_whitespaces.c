/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:08:36 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/03 19:10:10 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_split_count(int mode, char *str, int num)
{
	int i;
	int k;
	int mot;

	i = 0;
	mot = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || !(str[i]))
			k = 0;
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		if (str[i] && k == 0)
			mot++;
		while (str[i + k] && !(str[i + k] == 32
					|| str[i + k] == 9 || str[i + k] == 10))
			k++;
		if (mode == 1 && mot == num)
			return (k);
		else if (mode == 2 && mot == num)
			return (i);
		i += k;
	}
	return (mot);
}

void	ft_split_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i] && src[i] != 32 && src[i] != 10 && src[i] != 9)
		dest[i] = src[i];
	dest[i] = '\0';
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		mot;

	mot = ft_split_count(0, str, 0);
	i = 1;
	tab = NULL;
	tab = (char**)malloc(sizeof(char*) * (mot + 1));
	tab[mot] = NULL;
	while (i <= mot)
	{
		tab[i - 1] = (char*)malloc(sizeof(char) *
				(ft_split_count(1, str, i) + 1));
		ft_split_strcpy(tab[i - 1], str + ft_split_count(2, str, i));
		i++;
	}
	return (tab);
}
