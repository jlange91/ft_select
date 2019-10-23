#include "ft_select.h"

int   read_stdin(t_term *t)
{
  int	  nb_bytes;
  char	*buff;
  char	stop;

  stop = 0;
  nb_bytes = 0;
  t = (t_term*)t;
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
