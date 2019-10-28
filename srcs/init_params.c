/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:33:16 by jlange            #+#    #+#             */
/*   Updated: 2019/10/25 17:39:39 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_param		*realloc_params(int nb_args, int ignored_index, t_param *old)
{
	t_param	*new;
	int		i;

	i = 0;
	if (!(new = (t_param*)malloc(sizeof(t_param) * (nb_args - 1))))
	{
		ft_putendl_fd("ft_select: init_params: malloc_error", STDERR_FILENO);
		ft_exit(1);
	}
	while (i < nb_args - 1)
	{
		new[i].str = (i < ignored_index) ? old[i].str : old[i + 1].str;
		new[i].len = ft_strlen(new[i].str);
		new[i].l_x = 0;
		new[i].l_y = 0;
		new[i].t_x = 0;
		new[i].t_y = 0;
		new[i].selected = (i < ignored_index) ?
			old[i].selected : old[i + 1].selected;
		new[i].type = (i < ignored_index) ? old[i].type : old[i + 1].type;
		i++;
	}
	return (new);
}

int			init_params(int ac, char **av, t_layout *l)
{
	int i;

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
		l->params[i].type = get_type_file(l->params[i].str);
		i++;
	}
	return (0);
}
