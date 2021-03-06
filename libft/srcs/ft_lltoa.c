/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 00:55:28 by nihuynh           #+#    #+#             */
/*   Updated: 2018/11/26 02:16:21 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

char	*ft_lltoa(long long value)
{
	char				*res;
	size_t				idx;
	unsigned long long	carry;

	carry = (value > 0) ? value : -value;
	idx = (value < 0) ? 2 : 1;
	while (carry /= 10)
		idx++;
	carry = (value > 0) ? value : -value;
	if (!(res = ft_strnew(idx)))
		return (NULL);
	res[0] = (value < 0) ? '-' : '0';
	while (carry)
	{
		res[--idx] = carry % 10 + 48;
		carry /= 10;
	}
	return (res);
}
