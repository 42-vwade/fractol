/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:18:22 by viwade            #+#    #+#             */
/*   Updated: 2019/08/12 09:18:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define IS_O(n) ((n) + !((n) % 2))

void
	fractol(cfg_t config)
{
	env_t	o;

	o.bailout = 10;
	o.dim = (v3d_t){IS_O(DIM_X), IS_O(DIM_Y), IS_O(DIM_Y) / IS_O(DIM_X)};
	o.m_init = mlx_init();
	o.m_title = WINDOW_TITLE;
	o.m_window = mlx_new_window(o.m_init, o.dim.x, o.dim.y, o.m_title);
}
