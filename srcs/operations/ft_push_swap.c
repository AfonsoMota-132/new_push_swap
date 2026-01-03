/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:36:56 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 10:39:50 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_push(t_lista **target, t_lista **src, char *str)
{
	t_lista	*curr;
	t_lista	*next;

	if (!*src)
		return ;
	curr = ft_rmv_head(src);
	next = *target;
	curr->both = next;
	if (next)
		next->both = ft_xor(next->both, curr);
	*target = curr;
	if (ft_strlen(str))
		ft_putstr_fd(str, 1);
}

void	ft_swap(t_lista **head, char *str)
{
	t_lista	*first;
	t_lista	*second;
	t_lista	*third;
	t_lista	*fourth;

	if (!*head || ft_lista_size(*head) < 2)
		return ;
	first = *head;
	second = first->both;
	if (!second)
		return ;
	third = ft_xor(second->both, first);
	first->both = ft_xor(second, third);
	second->both = first;
	if (third)
	{
		fourth = ft_xor(second, third->both);
		third->both = ft_xor(first, fourth);
	}
	*head = second;
	if (ft_strlen(str))
		ft_putstr_fd(str, 1);
}

void	ft_swap_both(t_data *data)
{
	ft_swap(&data->head_a, "");
	ft_swap(&data->head_b, "");
	ft_putstr_fd("ss\n", 2);
}
