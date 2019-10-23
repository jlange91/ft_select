/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:32:45 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/23 16:01:22 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void destructor(void) __attribute__((destructor));

void destructor(void)
{
	t_term *t;

	t = singleton_term(NULL);
	if (t)
	{
		ft_putendl("Reset terminal");
		tcsetattr(STDIN_FILENO, TCSADRAIN, &(t->old));
	}
}

void	ft_handle_signals(int sig)
{
	// ft_putnbr(sig);
	sig = (int)sig;
	ft_putchar('\n');
	exit(1);
}

void	ft_set_signals()
{
	int i;

	i = 0;
	while (i <= 32)
	{
		signal(i, ft_handle_signals);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_term 		t;
	t_layout 	l;

	if (ac <= 1)
		return (0);
	if (init_term(&t) || init_layout(ac, av, &l))
		exit(1);
	calc_layout(&t, &l);
	singleton_term(&t);
	ft_set_signals();
	read_stdin(&t, &l);
	return (0);
}
