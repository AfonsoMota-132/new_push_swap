/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:59:15 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 19:00:37 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_calculate_cost(t_stack *head_a, t_stack *head_b, t_stack *node)
{
	t_stack	*target;
	int		cost_a;
	int		cost_b;

	cost_a = ft_price_rot_first(head_a, node);
	target = ft_find_in_b(head_b, node->id);
	cost_b = ft_price_rot_first(head_b, target);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		cost_a = ft_abs(cost_a);
		cost_b = ft_abs(cost_b);
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

t_stack	*ft_find_in_b(t_stack *head_b, int value)
{
	t_stack	*current;
	t_stack	*prev;
	t_stack	*best_match;
	t_stack	*next;

	best_match = NULL;
	current = head_b;
	prev = NULL;
	while (current)
	{
		if (current->id < value)
		{
			if (!best_match || current->id > best_match->id)
				best_match = current;
		}
		next = ft_xor(prev, current->both);
		prev = current;
		current = next;
	}
	if (!best_match)
		return (ft_find_max(head_b));
	return (best_match);
}

int	ft_price_rot_first(t_stack *head, t_stack *node)
{
	size_t	list_size;
	size_t	i;

	list_size = ft_stack_size(head);
	i = ft_stack_get_index(head, node);
	if (i <= list_size / 2)
		return (i);
	else
		return (-(list_size - i));
}
