/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:02:59 by viwade            #+#    #+#             */
/*   Updated: 2019/08/11 13:50:59 by viwade           ###   ########.fr       */
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
void	mandelbrot(env_t *o, size_t limit, v3d_t c);

#endif
