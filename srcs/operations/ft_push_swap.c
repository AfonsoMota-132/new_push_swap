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

void	ft_push(t_stack **target, t_stack **src, char *str)
{
	t_stack	*curr;
	t_stack	*next;

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

void	ft_push_a(t_data *data)
{
	ft_push(&data->head_a, &data->head_b, "pa\n");
	data->tail_a = ft_get_tail(data->head_a);
	if (!data->head_b)
		data->tail_b = NULL;
}

void	ft_push_b(t_data *data)
{
	ft_push(&data->head_b, &data->head_a, "pb\n");
	data->tail_b = ft_get_tail(data->head_b);
	if (!data->head_a)
		data->tail_a = NULL;
}

void	ft_swap(t_stack **head, t_stack **tail, char *str)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*fourth;

	if (!*head || ft_stack_size(*head) < 2)
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
	if (ft_stack_size(*head) == 2)
		*tail = first;
	if (ft_strlen(str))
		ft_putstr_fd(str, 1);
}

void	ft_swap_both(t_data *data)
{
	ft_swap(&data->head_a, &data->tail_a, "");
	ft_swap(&data->head_b, &data->tail_b, "");
	ft_putstr_fd("ss\n", 1);
}
