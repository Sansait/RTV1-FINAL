/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:31:37 by sklepper          #+#    #+#             */
/*   Updated: 2018/12/19 19:11:33 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

void		vec3_reflect(t_inter *inter)
{
	t_vec3	tmp;
	float	dot;

	dot = vec3_dot(&inter->n, &inter->ray.n);
	vec3_cpy(&tmp, &inter->n);
	vec3_scalar(&tmp, 2 * dot);
	vec3_sub(&inter->reflected, &inter->ray.n, &tmp);
}
