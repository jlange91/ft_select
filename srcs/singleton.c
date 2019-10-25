/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:34:18 by jlange            #+#    #+#             */
/*   Updated: 2019/10/25 17:27:40 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term  *singleton_term(t_term *t, int set)
{
	static t_term *term = NULL;

	if (t || set)
		term = t;
	return term;
}

t_layout  *singleton_layout(t_layout *l)
{
	static t_layout *layout = NULL;

	if (l)
		layout = l;
	return layout;
}
