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
	else if (sig == SIGCONT)
	{
		// print_args(singleton_layout(NULL));
		// signal(SIGTSTP, handle_signals);
		// ft_set_signals();
		signal(SIGTSTP, handle_signals);
		signal(SIGCONT, handle_signals);
		init_term(t);
		read_stdin(t, l);
		return ;
	}
	else
		exit(1);
	// ft_putnbr(sig);
	// ft_putchar('\n');
}
