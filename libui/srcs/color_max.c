/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:56 by sklepper          #+#    #+#             */
/*   Updated: 2018/12/10 15:25:58 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ftmath.h"

void	color_max(t_color *col1, t_color *col2)
{
	col1->r = ft_max(col1->r, col2->r);
	col1->g = ft_max(col1->g, col2->g);
	col1->b = ft_max(col1->b, col2->b);
}
