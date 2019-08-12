/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:29:42 by viwade            #+#    #+#             */
/*   Updated: 2019/08/12 10:52:38 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void
	solve(env_t *o, size_t *bounces, v3d_t c)
{
	double	z;

	z = 0;
	c = (v3d_t){c.x * c.x, c.y * c.y, c.z};
	while (bounces[0] < o->bailout && (z = (z * z) + (c.x + c.y)) < 4)
	{
		c.x += c.x;
		c.y += c.y;
		bounces[0]++;
	}
	draw_pixel(o, c.x + (c.y * o->dim.x),
		color_gradient(bounces, o->bailout));
}

void
	mandelbrot(env_t *o, size_t limit, v3d_t c)
{
	size_t	i;
	size_t	bounces;

	i = 0;
	limit = o->dim.x * o->dim.y;
	while (i < limit && !(bounces = 0))
	{
		solve(o, &bounces,
			(v3d_t){(int)(i % (int)o->dim.x), (int)(i / (int)o->dim.x), 0});
		i++;
	}
}
