/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:59:03 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/24 17:41:07 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	say_my_type(t_param *p)
{
	struct stat s;

	if (stat(p->str, s))
		p->type = 0;
	else
		p->type = s.st_mode;
}

void	set_file_type(t_layout *lay)
{
	size_t i;

	i = 0;
	while (i < lay->nb_args)
	{
		say_my_type(lay->params[i]);
		i++;
	}
}
