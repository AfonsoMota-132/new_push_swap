/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:58:32 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 12:04:19 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_lista	*ft_index_min(t_lista *curr)
{
	t_lista	*prev;
	t_lista	*next;
	t_lista	*tmp;

	prev = NULL;
	tmp = NULL;
	while (curr)
	{
		if (!tmp && curr->id == -1)
			tmp = curr;
		else if (curr->id == -1 && curr->nbr < tmp->nbr)
			tmp = curr;
		next = ft_xor(prev, curr->both);
		prev = curr;
		curr = next;
	}
	return (tmp);
}

void	ft_lista_index(t_lista *head)
{
	size_t	size;
	size_t	i;
	t_lista	*tmp;

	i = 0;
	size = ft_lista_size(head);
	while (i < size)
	{
		tmp = ft_index_min(head);
		if (tmp)
			tmp->id = i;
		i++;
	}
}

bool	ft_ver_sorted(t_data *data)
{
	t_lista	*prev;
	t_lista	*curr;
	t_lista	*next;

	if (ft_lista_size(data->head_b))
		return (false);
	curr = data->head_a;
	prev = NULL;
	while (curr)
	{
		next = ft_xor(curr->both, prev);
		if (next && next->id < curr->id)
			return (false);
		prev = curr;
		curr = next;
	}
	return (true);
}
