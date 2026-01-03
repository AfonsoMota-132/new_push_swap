/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:40:52 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 10:40:58 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_lista	*ft_xor(t_lista *x, t_lista *y)
{
	return ((t_lista *)((uintptr_t)(x) ^ (uintptr_t)(y)));
}

t_lista	*ft_rmv_head(t_lista **head)
{
	t_lista	*curr;
	t_lista	*next;

	if (!*head)
		return (NULL);
	curr = *head;
	next = curr->both;
	if (next)
		next->both = ft_xor(next->both, curr);
	*head = next;
	curr->both = NULL;
	return (curr);
}

t_lista	*ft_rmv_tail(t_lista **tail)
{
	t_lista	*curr;
	t_lista	*prev;

	if (!*tail)
		return (NULL);
	curr = *tail;
	prev = curr->both;
	if (prev)
		prev->both = ft_xor(prev->both, curr);
	*tail = prev;
	curr->both = NULL;
	return (curr);
}
