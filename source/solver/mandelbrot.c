/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:29:42 by viwade            #+#    #+#             */
/*   Updated: 2019/08/06 07:06:39 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void
	solve(size_t limit, v3d_t c)
{
	size_t	i;
	double	z;

	i = 0;
	z = 0;
	while (i < limit)
	{
		if ((z = (z * z) + ((c.x * c.x) + (c.y * c.y))) >= 4)
			break ;
		i++;
	}
}

void
	mandelbrot(void)
{
	;
}
