/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:54:22 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:23 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(int error)
{
	if (error == 0)
	{
		ft_putstr_fd("Usage: ./fractol [julia | mandelbrot ", 2);
		ft_putstr_fd("| newton | burningship | multibrot | juliux ", 2);
		ft_putendl_fd("| celtic | bird]", 2);
	}
	else if (error == 1)
	{
		ft_putendl_fd("Mlx error, verify environement...", 2);
	}
	exit(0);
}
