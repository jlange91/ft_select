/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:12:20 by jlange            #+#    #+#             */
/*   Updated: 2019/10/28 09:13:20 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_exit(int ret)
{
	t_layout *l;

	l = singleton_layout(NULL);
	term_off(singleton_term(NULL, 0));
	if (l && l->params)
	{
		free(l->params);
		l->params = NULL;
	}
	exit(ret);
}
