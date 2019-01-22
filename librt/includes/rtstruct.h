/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtstruct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 00:44:05 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/19 17:31:02 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTSTRUCT_H
# define RTSTRUCT_H

# include "color.h"

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_pt3
{
	float		x;
	float		y;
	float		z;
}				t_pt3;

typedef struct	s_ray
{
	t_pt3		origin;
	t_vec3		n;
}				t_ray;

typedef struct	s_plane
{
	t_pt3		origin;
	t_vec3		n;
	t_color		color;
}				t_plane;

typedef struct	s_sphere
{
	t_pt3		origin;
	float		radius;
	t_color		color;
}				t_sphere;

typedef struct	s_cone
{
	t_pt3		origin;
	t_vec3		n;
	float		theta;
	t_color		color;
}				t_cone;

typedef struct	s_cylinder
{
	t_pt3		origin;
	t_vec3		n;
	float		radius;
	t_color		color;
}				t_cylinder;

typedef struct	s_light
{
	t_pt3		origin;
	t_color		color;
	float		intensity;
}				t_light;

typedef struct	s_cam
{
	t_pt3		pos;
	t_vec3		dir;
}				t_cam;

typedef struct	s_matrix
{
	float		m[3][3];
}				t_matrix;

typedef struct s_obj	t_obj;
typedef struct s_inter	t_inter;

struct			s_inter
{
	float		dist;
	t_obj		*obj;
	t_ray		ray;
	t_vec3		n;
	t_color		color;
	t_vec3		reflected;
	void		(*find_normal) (t_inter*);
};

struct			s_obj
{
	int			type;
	void		*shape;
	float		diffuse;
	void		(*f_inter) (t_inter*, t_obj*);
};

#endif
