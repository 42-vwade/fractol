/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:18:22 by viwade            #+#    #+#             */
/*   Updated: 2019/08/23 11:55:16 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define IS_O(n) ((n) + !((n) % 2))

void
	fractol(cfg_t config)
{
	env_t	o;

	env_init(&o);
	o.config = config;
	*((size_t*)&o.bailout) = 10;
	o.zoom = (t_zoom){-2.5, 1, -1, 1};
	*((t_zoom*)&o.z_ref) = o.zoom;
	o.scale = 1;
	o.dim = (v3d_t){IS_O(DIM_X), IS_O(DIM_Y), IS_O(DIM_Y) / IS_O(DIM_X)};
	mandelbrot(&o);
//	mlx_loop(o.m_init);
}
