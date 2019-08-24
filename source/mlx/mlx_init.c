/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 07:58:11 by viwade            #+#    #+#             */
/*   Updated: 2019/08/21 11:00:38 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	env_init(env_t *o)
{
	o->m_init = mlx_init();
	o->m_title = WINDOW_TITLE;
	o->m_window = mlx_new_window(o->m_init, o->dim.x, o->dim.y, o->m_title);
	o->m_image = mlx_new_image(o->m_init, o->dim.x, o->dim.y);
	o->m_start = mlx_get_data_addr(o->m_image, &(int){BIT_DEPTH},
		&o->bmp.line, &o->bmp.endian);
}
