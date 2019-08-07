/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:06:40 by viwade            #+#    #+#             */
/*   Updated: 2019/08/07 11:48:49 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void
	start_console(char *v)
{
	env_t	o;

	o.p_threads = sysconf(_SC_NPROCESSORS_ONLN) * THREADS_PER_CPU;
	if (!v)
		;
	else
	{
		;
	}
}

static void
	no_input(void)
{
	start_console(0);
}

int
	main(int n, char **v)
{
	if (n == 2)
	{
		start_console(v[1]);
	}
	else
		no_input();
}
