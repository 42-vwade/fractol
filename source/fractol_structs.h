/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:30:09 by viwade            #+#    #+#             */
/*   Updated: 2019/08/24 14:16:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_STRUCTS_H
# define _FRACTOL_STRUCTS_H
# include <stdlib.h>
# include <sys/types.h>
# include "fractol_macros.h"

typedef struct s_image	t_img;
typedef struct s_map	t_map;
typedef struct s_zoom	t_zoom;

struct	s_rgb
{
	unsigned int	b:BIT_DEPTH;
	unsigned int	g:BIT_DEPTH;
	unsigned int	r:BIT_DEPTH;
};

union	u_pixel
{
	unsigned int	i;
	struct s_rgb	c;
};

struct	s_vec2d
{
	ssize_t	x;
	ssize_t	y;
};

struct	s_vec3d
{
	long double	x;
	long double	y;
	long double	z;
};

struct	s_zoom
{
	long double	x_min;
	long double	x_max;
	long double	y_min;
	long double	y_max;
};

struct s_map
{
	unsigned long	iter[DIM_Y * DIM_X];
};


struct	s_image
{
	void		*ref;
	pixel_t		*pixel;
	pixel_t		*start;
	int			depth;
	int			line;
	int			endian;
	uint32_t	width;
	uint32_t	height;
};

struct	s_config
{
	long	p_threads;
	int		lame;
};

struct	s_fractol
{
	cfg_t			config;
	void			*m_init;
	void			*m_window;
	char			*m_title;
	void			*m_image;
	void			*m_start;
	t_img			bmp;
	v3d_t			dim;
	unsigned long	map[DIM_Y * DIM_X];
	const size_t	bailout;
	const t_zoom	z_ref;
	t_zoom			zoom;
	long double		scale;
	v3d_t			center;
};

#endif
