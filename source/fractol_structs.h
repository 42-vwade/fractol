/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:30:09 by viwade            #+#    #+#             */
/*   Updated: 2019/08/12 09:16:08 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_STRUCTS_H
# define _FRACTOL_STRUCTS_H
# include <stdlib.h>
# include <sys/types.h>
# include "fractol_macros.h"

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

struct	s_config
{
	long	p_threads;
};

struct	s_fractol
{
	cfg_t	config;
	void	*m_init;
	void	*m_window;
	char	*m_title;
	void	*m_image;
	void	*m_start;
	v3d_t	dim;
	size_t	bailout;
};

#endif
