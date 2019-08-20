/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 07:04:00 by viwade            #+#    #+#             */
/*   Updated: 2019/08/12 10:58:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_pixel(env_t *o, size_t index, pixel_u col)
{
	int	*screen;

	screen = o->m_start;
	screen[index] = 0xffffff & col.i;
}
