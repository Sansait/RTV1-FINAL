/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:13:10 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/03 16:10:59 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftctype.h"
#include "ftmath.h"

int		ft_isxdigit(int c)
{
	return (ft_isdigit(c) || ft_btw(c, 65, 70) || ft_btw(c, 97, 102));
}
