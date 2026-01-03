/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:41:16 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 10:42:15 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_free_data(t_data	*data)
{
	if (data)
	{
		if (data->head_a)
			ft_free_lista(data->head_a);
		if (data->head_b)
			ft_free_lista(data->head_b);
		free(data);
	}
}

void	ft_free_lista(t_lista *curr)
{
	t_lista	*prev;
	t_lista	*next;

	prev = NULL;
	while (curr != NULL)
	{
		next = ft_xor(prev, curr->both);
		prev = curr;
		curr = next;
		free(prev);
	}
}
