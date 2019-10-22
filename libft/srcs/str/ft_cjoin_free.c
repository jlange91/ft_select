/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cjoin_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:38:42 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/16 17:11:07 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cjoin_free(const char *s1, char c, char *tofree)
{
	char *dest;
	char	s2[2];

	s2[0] = c;
	s2[1] = '\0';
	dest = ft_strjoin(s1, s2);
	if (tofree)
		free(tofree);
	return (dest);
}
