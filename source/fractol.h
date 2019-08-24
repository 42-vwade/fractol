/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:02:59 by viwade            #+#    #+#             */
/*   Updated: 2019/08/24 14:17:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/types.h>
# include <math.h>
# include "fractol_macros.h"
# include "fractol_structs.h"
# include "../libft/libft.h"
# include "../.minilibx/mlx.h"

void	fractol(cfg_t configuration);
void	env_init(env_t *o);
void	mandelbrot(env_t *o);
pixel_u	color_gradient(long double n, size_t bailout);


#endif
