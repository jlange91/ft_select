#include "ft_select.h"

static int init_termcaps(t_term *t)
{
  int ret;

	t->type = getenv("TERM");
  if (t->type == NULL)
    return (1);
  ret = tgetent(NULL, t->type);
  if (ret == -1)
    return (2);
  else if (ret == 0)
    return (3);
  return 0;
}

static int	init_attr(t_term *t)
{
	if (tcgetattr(STDIN_FILENO, &(t->old)))
    return (4);
	t->new = t->old; // cpy
	t->new.c_lflag &= ~(ECHO | ICANON);
	t->new.c_cc[VMIN] = 1;
	t->new.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &(t->new)))
    return (5);
  return (0);
}

int init_term(t_term *t)
{
  int ret;
  char *(errors[5]);

  errors[0] = "TERM must be set (see 'env').\n";
  errors[1] = "Could not access to the termcap database.\n";
  errors[2] = "Terminal type is not defined in termcap database (or have too few informations).\n";
  ret = init_termcaps(t);
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
  return (ret);
}
