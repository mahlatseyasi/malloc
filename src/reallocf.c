/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:55:29 by mkhoza            #+#    #+#             */
/*   Updated: 2019/07/22 15:03:25 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

extern void	*reallocf(void *ptr, size_t size)
{
	ptr = realloc(ptr, size);
	if (ptr == NULL)
		free(ptr);
	return (ptr);
}
