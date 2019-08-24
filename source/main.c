/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:06:40 by viwade            #+#    #+#             */
/*   Updated: 2019/08/24 16:21:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void
	start_console(char *v)
{
	if (v)
		fractol((cfg_t){
			.p_threads = sysconf(_SC_NPROCESSORS_ONLN) * THREADS_PER_CPU - 1});
	else
	{
		ft_putendl(
			"usage: ./fractol <method>\n\t"
			"methods:	1. mandelbrot\n"
			"       	2. julia\n"
			"       	3. [undecided]"
		);
	}
}

int
	main(int n, char **v)
{
	if (n == 2)
		start_console(v[1]);
	else
		start_console(0);
}
