/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:30:09 by viwade            #+#    #+#             */
/*   Updated: 2019/08/19 06:41:48 by viwade           ###   ########.fr       */
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
	double	x;
	double	y;
	double	z;
};

struct	s_zoom
{
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
};

struct s_map
{
	unsigned long	*iter;
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
	t_map			map;
	const size_t	bailout;
	t_zoom			zoom;
};

#endif
