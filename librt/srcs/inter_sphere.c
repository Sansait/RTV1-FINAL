/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:19:06 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/19 19:16:15 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"
#include <math.h>

static inline float	inter(t_ray *ray, t_sphere *sphere)
{
	float	toby[3];
	float	res[2];
	float	det;
	t_vec3	rene;

	vec3_sub(&rene, (t_vec3*)&ray->origin, (t_vec3*)&sphere->origin);
	AAAA = vec3_mag(&ray->n);
	BBBB = 2.0 * vec3_dot(&ray->n, &rene);
	CCCC = vec3_dot(&rene, &rene) - sphere->radius * sphere->radius;
	det = BBBB * BBBB - 4 * AAAA * CCCC;
	if (det < 0)
		return (HUGEVAL);
	res[0] = (-BBBB + sqrt(det)) / (2 * AAAA);
	res[0] = (res[0] > 0) ? res[0] : HUGEVAL;
	res[1] = (-BBBB - sqrt(det)) / (2 * AAAA);
	res[1] = (res[1] > 0) ? res[1] : HUGEVAL;
	return ((res[0] < res[1]) ? res[0] : res[1]);
}

void				inter_sphere(t_inter *data, t_obj *node)
{
	t_sphere	*sphere;
	float		dist;

	sphere = node->shape;
	dist = inter(&data->ray, sphere);
	if (dist >= data->dist || dist < 0)
		return ;
	color_cpy(&data->color, &sphere->color);
	data->dist = dist;
	data->obj = node;
	data->find_normal = &normal_sphere;
}
