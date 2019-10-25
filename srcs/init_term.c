/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:33:23 by jlange            #+#    #+#             */
/*   Updated: 2019/10/25 17:41:45 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static inline int		init_getent(t_term *t)
{
	int ret;

	t->type = getenv("TERM");
	if (t->type == NULL)
		return (1);
	else
		ret = tgetent(NULL, t->type);
	if (ret == -1)
		return (2);
	else if (ret == 0)
		return (3);
	return (0);
}

static inline int		init_attr(t_term *t)
{
	if (tcgetattr(STDIN_FILENO, &(t->old)))
		return (4);
	t->new = t->old;
	t->new.c_lflag &= ~(ECHO | ICANON);
	t->new.c_cc[VMIN] = 1;
	t->new.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &(t->new)))
		return (5);
	return (0);
}

int						get_size_term(t_term *t)
{
	struct winsize w;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w))
	{
		ft_putstr_fd("Could not get size of term.\n", 2);
		return (1);
	}
	t->length = w.ws_col;
	t->height = w.ws_row;
	return (0);
}

int						init_term(t_term *t)
{
	int		ret;
	char	*(errors[5]);

	errors[0] = "TERM must be set (see 'env').\n";
	errors[1] = "Could not access to the termcap database.\n";
	errors[2] = "Terminal type is not defined in termcap database \
(or have too few informations).\n";
	ret = init_getent(t);
	if (ret)
	{
		ft_putstr_fd(errors[ret - 1], 2);
		return (ret);
	}
	errors[3] = "Could not get termios structure.\n";
	errors[4] = "Could not set termios structure.\n";
	ret = init_attr(t);
	if (ret)
		ft_putstr_fd(errors[ret - 1], 2);
	if (get_size_term(t))
		exit(1);
	tputs(tgetstr("ti", NULL), 1, ft_poutchar);
	tputs(tgetstr("vi", NULL), 1, ft_poutchar);
	return (ret);
}

int						term_off(t_term *t)
{
	if (t)
	{
		tputs(tgetstr("te", NULL), 1, ft_poutchar);
		tputs(tgetstr("ve", NULL), 1, ft_poutchar);
		tcsetattr(STDIN_FILENO, TCSADRAIN, &(t->old));
	}
	return (0);
}
