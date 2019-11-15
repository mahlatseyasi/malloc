/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:48:45 by mkhoza            #+#    #+#             */
/*   Updated: 2019/07/23 10:38:23 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void		*calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		allocation_size;

	ptr = NULL;
	allocation_size = count * size;
	ptr = malloc(allocation_size);
	if (ptr != NULL)
		ft_bzero(ptr, allocation_size);
	return (ptr);
}
