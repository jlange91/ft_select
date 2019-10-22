/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:32:45 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/22 18:02:25 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "libft.h"
#include "ft_select.h"

int	main()
{
	struct 	termios reset;
	struct 	termios term;
	int	nb_bytes;
	char	*buff;
	char	stop = 0;

	nb_bytes = 0;
	tcgetattr(STDIN_FILENO, &reset);
	term = reset;
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
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
			ft_putendl("HAUT");
		if (!ft_strcmp(ARROW_DOWN, buff))
			ft_putendl("BAS");
		if (!ft_strcmp(ARROW_LEFT, buff))
			ft_putendl("GAUCHE");
		if (!ft_strcmp(ARROW_RIGHT, buff))
			ft_putendl("DROITE");
		ft_strdel(&buff);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &reset);
	return (0);
}
