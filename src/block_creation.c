/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:47:20 by mkhoza            #+#    #+#             */
/*   Updated: 2019/07/23 10:36:21 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bool	is_space_available_block(t_block *block, size_t size_data)
{
	if (block != NULL && block->size_data >= size_data)
	{
		return (TRUE);
	}
	return (FALSE);
}

t_block	*get_last_block(t_zone *zone)
{
	t_block *current_block;

	current_block = zone->first_block;
	while (current_block->next_addr != NULL)
	{
		current_block = current_block->next_addr;
	}
	return (current_block);
}

t_block	*get_block_unused(t_block *block)
{
	t_block *current_block;

	current_block = block;
	while (current_block != NULL && current_block->is_free == FALSE)
	{
		current_block = current_block->next_addr;
	}
	return (current_block);
}

t_block	*get_reusable_block(t_block *block, size_t size_data)
{
	t_block *current_block;

	current_block = get_block_unused(block);
	while (current_block != NULL &&
		is_space_available_block(current_block, size_data) == FALSE)
	{
		current_block = get_block_unused(current_block->next_addr);
	}
	return (current_block);
}

t_block	*add_block_to_zone(t_zone *zone, size_t size_data)
{
	t_block *block;
	t_block *last_block;

	last_block = get_last_block(zone);
	block = (void*)last_block + sizeof(t_block) + last_block->size_data;
	block = init_one_block(zone, block, size_data);
	last_block->next_addr = block;
	return (block);
}
