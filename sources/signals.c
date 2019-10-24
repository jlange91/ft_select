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
	//ft_putendl_fd(ft_itoa(sig), 2);
	if (sig == SIGTSTP)
	{
		ft_putendl_fd("b", 2);
		term_off(t);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, (char[2]){t->old.c_cc[VSUSP], 0});
	}
	else if (sig == SIGWINCH)
	{
		get_size_term(t);
		calc_layout(t, l);
		print_args(l);
	}
	else if (sig == SIGCONT)
	{
		ft_putendl_fd("a", 2);
		// print_args(singleton_layout(NULL));
		init_term(t);
		singleton_term(t);
		ft_set_signals();
		read_stdin(t, l);
		return ;
	}
	else
		exit(1);
	// ft_putnbr(sig);
	// ft_putchar('\n');
}
