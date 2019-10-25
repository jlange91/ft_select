/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:33:33 by jlange            #+#    #+#             */
/*   Updated: 2019/10/25 17:42:41 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	destructor(void) __attribute__((destructor));

void	destructor(void)
{
	t_layout *l;

	l = singleton_layout(NULL);
	term_off(singleton_term(NULL, 0));
	if (l && l->params)
	{
		free(l->params);
		l->params = NULL;
	}
}

int		main(int ac, char **av)
{
	t_term 		t;
	t_layout 	l;

	if (ac <= 1)
		return (0);
	if (init_term(&t) || init_layout(ac, &l) || init_params(ac, av, &l))
		exit(1);
	singleton_term(&t, 1);
	singleton_layout(&l);
	ft_set_signals();
	calc_layout(&t, &l);
	read_stdin(&t, &l);
	return (0);
}
