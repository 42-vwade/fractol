/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:29:42 by viwade            #+#    #+#             */
/*   Updated: 2019/08/20 00:34:24 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void
	draw_pixel(env_t *o, size_t index, pixel_u col)
{
	int	*screen;

	screen = o->m_start;
	screen[index] = 0xffffff & col.i;
}

static size_t
	solve(env_t *o, size_t *bounces, v3d_t c)
{
	double	z;

	z = 0;
	c.x = (c.x - o->dim.x * 0.5) / o->dim.x;
	c.y = (c.y - o->dim.y * 0.5) / o->dim.y;
	c = (v3d_t){c.x * c.x, c.y * c.y, c.z};
	while (bounces[0] < o->bailout && (z = (z * z) + (c.x + c.y)) < 4)
	{
		c.x += c.x;
		c.y += c.y;
		bounces[0]++;
	}
	return (bounces[0]);
	draw_pixel(o, c.x + (c.y * o->dim.x), color_gradient(*bounces, o->bailout));
}

/*
**	caveat: transformed return value:
**		from: void -> size_t
**		todo: create array of known bounces representing each pixel & store it
**		ergo: O(n += dim*dim) calculate color from each index, then place pixel
**		undo: O(n -= dim*dim) calculate bounces, color, immediately place pixel
*/

void
	mandelbrot(env_t *o)
{
	size_t	i;
	size_t	limit;
	size_t	bounces;

	i = -1;
	limit = o->dim.x * o->dim.y;
	while (++i < limit && !(bounces = 0))
		o->map.iter[i] = solve(o, &bounces,
			(v3d_t){(int)(i % (int)o->dim.x), (int)(i / (int)o->dim.x), 0});
}
