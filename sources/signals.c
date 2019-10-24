#include "ft_select.h"

void	ft_set_signals()
{
	int i;

	i = 0;
	while (i <= 32)
	{
		if (i != SIGTSTP)
			signal(i, handle_signals);
		i++;
	}
}

void	handle_signals(int sig)
{
	// if (sig == SIGTSTP)
	// {
	// 	tputs(tgetstr("ve", NULL), 1, (int (*)(int))ft_putchar);
	// }
	if (sig == SIGCONT)
	{
		// print_args(singleton_layout(NULL));
		// signal(SIGTSTP, handle_signals);
		ft_set_signals();
		init_term(singleton_term(NULL));
		read_stdin(singleton_term(NULL), singleton_layout(NULL));
		return ;
	}
	else
		exit(1);
	// ft_putnbr(sig);
	// ft_putchar('\n');
}
