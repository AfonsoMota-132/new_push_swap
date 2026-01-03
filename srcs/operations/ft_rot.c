/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:22:04 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 11:22:52 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_rotate(t_stack **head, t_stack **tail, char *str)
{
	t_stack	*curr;
	t_stack	*prev;

	if (ft_stack_size(*head) <= 1)
		return ;
	curr = ft_rmv_head(head);
	prev = *tail;
	prev->both = ft_xor(prev->both, curr);
	curr->both = prev;
	*tail = curr;
	if (ft_strlen(str))
		ft_putstr_fd(str, 1);
}

void	ft_rotate_both(t_data *data)
{
	ft_rotate(&data->head_a, &data->tail_a, "");
	ft_rotate(&data->head_b, &data->tail_b, "rr\n");
}

void	ft_rev_rotate(t_stack **head, t_stack **tail, char *str)
{
	t_stack	*curr;
	t_stack	*next;

	if (ft_stack_size(*head) <= 1)
		return ;
	curr = ft_rmv_tail(tail);
	next = *head;
	next->both = ft_xor(next->both, curr);
	curr->both = next;
	*head = curr;
	if (ft_strlen(str))
		ft_putstr_fd(str, 1);
}

void	ft_rev_rot_both(t_data *data)
{
	ft_rev_rotate(&data->head_a, &data->tail_a, "");
	ft_rev_rotate(&data->head_b, &data->tail_b, "rrr\n");
}
