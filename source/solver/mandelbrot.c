/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:29:42 by viwade            #+#    #+#             */
/*   Updated: 2019/08/24 16:32:53 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#define Z1(n,s)		((n)/MAX(1,(s)))
#define ZX(n,s,o)	(Z1(n,s))
#define ZY(n,s,o)	(Z1(n,s))
#define ZOOM(a,b,c,d,z,o) (t_zoom){ZX(a,z,o),ZX(b,z,o),ZY(c,z,o),ZY(d,z,o)}
#define _MRNGC(min,max)	(RANGE((min),(max)) - (min))
#define OFFSET(n,min,max,c) ((n) * _MRNGC(min,max))
#define MANDELBROT_ALGORITHM(z, c)	(M_Z2(z) + M_C2(c))

static void
	draw_pixel(env_t *o, size_t index, pixel_u col)
{
	((int *)o->m_start)[index] = 0xffffff & col.i;
}

static void
	solve(env_t *o, size_t *bounces, v3d_t p)
{
	v3d_t	c;
	v3d_t	d;

	bounces[0] = 0;
	d.x = OFFSET(p.x / o->dim.x, o->zoom.x_min, o->zoom.x_max, o->center.x);
	d.y = OFFSET(p.y / o->dim.y, o->zoom.y_min, o->zoom.y_max, o->center.y);
	d.z = OFFSET(p.z / o->dim.y, o->zoom.y_min, o->zoom.y_max, o->center.z);
	c = (v3d_t){d.x, d.y, 0};
	c = (v3d_t){c.x * c.x, c.y * c.y, (c.x + c.y) * (c.x + c.y)};
	while (c.x + c.y < 4 && bounces[0]++ < o->bailout)
	{
		c = (v3d_t){c.x - c.y + d.x, c.z - c.x - c.y + d.y, 0};
		c = (v3d_t){c.x * c.x, c.y * c.y, (c.x + c.y) * (c.x + c.y)};
	}
	draw_pixel(o, p.x + (p.y * o->dim.x), color_gradient(*bounces, o->bailout));
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

	i = -1;
  	limit = o->dim.x * o->dim.y;
	o->zoom = ZOOM(o->z_ref.x_min,
		o->z_ref.x_max, o->z_ref.y_min, o->z_ref.y_max, o->scale, o->center);
	while (++i < limit)
		solve(o, &o->map[i],
			(v3d_t){(int)(i % (int)o->dim.x), (int)(i / (int)o->dim.x), 0});
	mlx_put_image_to_window(o->m_init, o->m_window, o->m_image, 0, 0);
	return ;
	ft_memcpy(o->map, o->m_start, sizeof(*o->map) * DIM_Y * DIM_X);
}
