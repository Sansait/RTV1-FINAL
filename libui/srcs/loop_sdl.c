/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 02:39:43 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/10 02:45:23 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	loop_sdl(int *quit, t_sdl *sdl)
{
	while (!*quit)
	{
		if (SDL_WaitEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_QUIT)
				*quit = 1;
		}
	}
}
