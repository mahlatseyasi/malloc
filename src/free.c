/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:49:40 by mkhoza            #+#    #+#             */
/*   Updated: 2019/07/23 10:47:24 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	t_block	*block;
	t_zone	*zone;

	if (ptr != NULL && g_first_addr != NULL)
	{
		block = (t_block*)(ptr - sizeof(t_block));
		if (check_block_exist(block) == TRUE)
		{
			if (block->is_free == TRUE)
				return ;
			zone = (t_zone*)block->zone;
			release_block(block);
			release_empty_zone(zone);
		}
	}
}
