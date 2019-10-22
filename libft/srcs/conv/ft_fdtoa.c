/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:53:38 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/30 15:59:00 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fdtoa(int fd, int buff_size)
{
	char *buff;
	char *ret;

	ret = NULL;
	if (buff_size < 1)
		return (NULL);
	if (!(buff = ft_strnew(buff_size)))
		return (NULL);
	while (read(fd, buff, buff_size) == buff_size)
	{
		ret = ft_strjoin_free(ret, buff, ret);
	}
	ret = ft_strjoin_free(ret, buff, ret);
	free(buff);
	return (ret);
}
