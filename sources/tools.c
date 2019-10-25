#include "ft_select.h"

int layout_case_exist(t_layout *l, int x, int y)
{
  int pos;

  pos = (y * l->nb_col) + x;
  return (pos < l->nb_args) ? 1 : 0;
}

mode_t	get_type_file(char *str)
{
	struct stat s;

	return (lstat(str, &s)) ? 0 : s.st_mode;
}

int        ft_poutchar(int c)
{
    return (write(STDERR_FILENO, &c, 1));
}
