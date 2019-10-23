/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:32:45 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/22 20:18:26 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void destructor(void) __attribute__((destructor));

void destructor(void)
{
	t_term *t;

	t = singleton_term(NULL);
	ft_putendl("Reset terminal");
	if (t)
		tcsetattr(STDIN_FILENO, TCSADRAIN, &(t->old));
}

void	ft_handle_signals(int sig)
{
	ft_putnbr(sig);
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

int	main()
{
	t_term t;
	int	nb_bytes;
	char	*buff;
	char	stop = 0;
	char	*tc;

	nb_bytes = 0;
	if (init_term(&t))
		exit(1);
	singleton_term(&t);
	ft_set_signals();

		tc = tgetstr("cl", NULL);
		tputs(tc, 1, (int (*)(int))ft_putchar);

	// tc = tgetstr("co", NULL);
	// tputs(tc, 1, (int (*)(int))ft_putchar);
	//
	// tc = tgetstr("li", NULL);
	// tputs(tc, 1, (int (*)(int))ft_putchar);



	while (!stop)
	{
		ioctl(STDIN_FILENO, FIONREAD, &nb_bytes);
		if (nb_bytes <= 0)
			continue ;
		if (!(buff = ft_strnew(nb_bytes)))
			break ;
		if (read(STDIN_FILENO, buff, nb_bytes) != nb_bytes)
			stop = 1;
		if (!ft_strcmp(ARROW_UP, buff))
			ft_putstr(ARROW_UP);
		else if (!ft_strcmp(ARROW_DOWN, buff))
			ft_putstr(ARROW_DOWN);
		else if (!ft_strcmp(ARROW_LEFT, buff))
			ft_putstr(ARROW_LEFT);
		else if (!ft_strcmp(ARROW_RIGHT, buff))
			ft_putstr(ARROW_RIGHT);
		else
			ft_putstr(buff);
		ft_strdel(&buff);
	}
	return (0);
}
