/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:01:11 by viwade            #+#    #+#             */
/*   Updated: 2019/08/24 15:33:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define _ILT(n)	((n) < 0 ? 0 : (n))
#define _RAD(n)	((n) / 180.0 * M_PI)
#define _8CH(n)	(0xff & (int)(127.0 + 128.0 * cos(n)))
#define _SQR(n) ((_ILT(n)) * 10)

pixel_u	color_gradient(long double n, size_t bailout)
{
	if (n >= bailout)
		return ((pixel_u){0});
	return ((pixel_u){
		.c.r = _8CH(_RAD(n / bailout * 360)),
		.c.g = _8CH(_RAD(n / bailout * (360 - 30))),
		.c.b = _8CH(_RAD(n / bailout * (360 - 60)))
	});
}
