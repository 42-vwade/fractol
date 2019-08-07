/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:02:59 by viwade            #+#    #+#             */
/*   Updated: 2019/08/07 11:53:43 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <math.h>
# include "../.minilibx/mlx.h"
# include "fractol_macros.h"
# include "fractol_structs.h"

void	fractol(cfg_t config);
void	mandelbrot(void);

#endif
