/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:29:42 by viwade            #+#    #+#             */
/*   Updated: 2019/08/11 09:44:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void
	solve(env_t *o, size_t limit, v3d_t c)
{
	size_t	i;
	size_t	bounces;
	double	z;

	i = 0;
	z = 0;
	c = (v3d_t){c.x * c.x, c.y * c.y, c.z};
	while (i < limit && !(bounces = 0))
	{
		z = 0;
		while (bounces < o->bailout && (z = (z * z) + (c.x + c.y)) < 4)
			bounces++;
		draw_pixel(o, i, color_gradient(bounces, o->bailout));
		i++;
	}
}

void
	mandelbrot(void)
{
	;
}
