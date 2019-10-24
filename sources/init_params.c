#include "ft_select.h"

int   init_params(int ac, char **av, t_layout *l)
{
  int     i;

  i = 0;
  if (!(l->params = (t_param*)malloc(sizeof(t_param) * (ac - 1))))
  {
    ft_putendl_fd("ft_select: init_params: malloc_error", STDERR_FILENO);
    return (1);
  }
  while (i < ac - 1)
  {
    l->params[i].str = av[i + 1];
    l->params[i].len = ft_strlen(av[i + 1]);
    l->params[i].l_x = 0;
    l->params[i].l_y = 0;
    l->params[i].t_x = 0;
    l->params[i].t_y = 0;
    l->params[i].selected = 0;
    i++;
  }
  return (0);
}
