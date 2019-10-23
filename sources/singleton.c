#include "ft_select.h"

t_term  *singleton_term(t_term *t)
{
  static t_term *term = NULL;

  if (t)
    term = t;
  return term;
}
