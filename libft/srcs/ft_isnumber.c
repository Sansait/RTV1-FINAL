/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:40:52 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/01 15:43:40 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnumber(int c)
{
	return ((c >= 48 && c <= 57) || c == 43 || c == 45);
}
