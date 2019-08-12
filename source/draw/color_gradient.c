/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:01:11 by viwade            #+#    #+#             */
/*   Updated: 2019/08/10 16:52:37 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define _ILT(n)	((n) < 0 ? 0 : (n))
#define _SQR(n) ((_ILT(n)) * 10)

pixel_u	color_gradient(double n)
{
	pixel_u	v;

	if (n >= BAILOUT)
		return ((pixel_u){0});
	v.c.r = (char)(127 + 128 * sin(_SQR(n) / 180 * M_PI));
	v.c.g = (char)(127 + 128 * sin(_SQR(n - 96) / 180 * M_PI));
	v.c.b = (char)(127 + 128 * sin(_SQR(n - 192) / 180 * M_PI));
	return (v);
}
