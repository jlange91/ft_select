/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:32:45 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/24 14:34:16 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void destructor(void) __attribute__((destructor));

void destructor(void)
{
	ft_putendl("yolo");
	term_off(singleton_term(NULL));
}

int	main(int ac, char **av)
{
	t_term 		t;
	t_layout 	l;

	if (ac <= 1)
		return (0);

	if (init_term(&t) || init_layout(ac, &l) || init_params(ac, av, &l))
		exit(1);
	calc_layout(&t, &l);
	singleton_term(&t);
	singleton_layout(&l);
	ft_set_signals();
	read_stdin(&t, &l);
	return (0);
}
