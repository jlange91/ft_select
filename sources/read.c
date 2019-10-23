#include "ft_select.h"

int   read_stdin(t_term *t, t_layout *l)
{
  int	  nb_bytes;
  char	*buff;
  char	stop;

  stop = 0;
  nb_bytes = 0;
  t = (t_term*)t;
  print_args(l);
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
      arrow_up_action(l);
		else if (!ft_strcmp(ARROW_DOWN, buff))
      arrow_down_action(l);
		else if (!ft_strcmp(ARROW_LEFT, buff))
      arrow_left_action(l);
		else if (!ft_strcmp(ARROW_RIGHT, buff))
      arrow_right_action(l);
    else if (!ft_strcmp(SPACE, buff))
      space_action(l);

		// else
		// 	ft_putstr(buff);
		ft_strdel(&buff);
	}
  return (0);
}
