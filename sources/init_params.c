#include "ft_select.h"

t_param   *init_params(int ac, char **av)
{
  t_param *ret;
  int     i;

  i = 0;
  if (!(ret = (t_param*)malloc(sizeof(t_param) * (ac - 1))))
    return (ret);
  while (i < ac - 1)
  {
    ret[i].str = av[i + 1];
    ret[i].len = ft_strlen(av[i + 1]);
    ret[i].l_x = 0;
    ret[i].l_y = 0;
    ret[i].t_x = 0;
    ret[i].t_y = 0;
    ret[i].selected = 0;
    i++;
  }
  return (ret);
}
