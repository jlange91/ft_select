/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbg_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:53:59 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/05 17:55:56 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdbg_nbr(const char *key, int value)
{
	ft_putchar_fd('[', 2);
	ft_putstr_fd(key, 2);
	ft_putstr_fd("]-[", 2);
	ft_putnbr_fd(value, 2);
	ft_putchar_fd(']', 2);
	ft_putchar_fd('\n', 2);
}
