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

t_stack	*ft_xor(t_stack *x, t_stack *y)
{
	return ((t_stack *)((uintptr_t)(x) ^ (uintptr_t)(y)));
}

t_stack	*ft_rmv_head(t_stack **head)
{
	t_stack	*curr;
	t_stack	*next;

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

t_stack	*ft_rmv_tail(t_stack **tail)
{
	t_stack	*curr;
	t_stack	*prev;

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
