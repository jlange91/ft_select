/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:34:12 by jlange            #+#    #+#             */
/*   Updated: 2019/10/25 15:34:15 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_set_signals()
{
	int i;

	i = 0;
	while (i <= 32)
	{
		signal(i, handle_signals);
		i++;
	}
}

void	handle_signals(int sig)
{
	t_term *t;
	t_layout *l;

	t = singleton_term(NULL);
	l = singleton_layout(NULL);
	if (sig == SIGTSTP)
	{
		term_off(t);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, (char[2]){t->old.c_cc[VSUSP], 0});
	}
	else if (sig == SIGWINCH)
		resize_window(t, l);
	else if (sig == SIGCONT)
	{
		if (init_term(t))
			exit(1);
		signal(SIGTSTP, handle_signals);
		signal(SIGCONT, handle_signals);
		print_args(l, t->height);
		return ;
	}
	else
		exit(0);
}
