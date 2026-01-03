/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:03:31 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 14:06:13 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_run_cheap_utils(t_data *data, int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		ft_rotate_both(data);
		(*cost_a)--;
		(*cost_b)--;
	}
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		ft_rev_rot_both(data);
		(*cost_a)++;
		(*cost_b)++;
	}
	while ((*cost_a) < 0)
	{
		ft_rev_rotate(&data->head_a, &data->tail_a, "rra\n");
		(*cost_a)++;
	}
	while ((*cost_a) > 0)
	{
		ft_rotate(&data->head_a, &data->tail_a, "ra\n");
		(*cost_a)--;
	}
}

void	ft_run_cheap(t_data *data, t_stack *node)
{
	t_stack	*target;
	int		cost_a;
	int		cost_b;

	cost_a = ft_price_rot_first(data->head_a, node);
	target = ft_find_in_b(data->head_b, node->id);
	cost_b = ft_price_rot_first(data->head_b, target);
	ft_run_cheap_utils(data, &cost_a, &cost_b);
	while (cost_b < 0)
	{
		ft_rev_rotate(&data->head_b, &data->tail_b, "rrb\n");
		cost_b++;
	}
	while (cost_b > 0)
	{
		ft_rotate(&data->head_b, &data->tail_b, "rb\n");
		cost_b--;
	}
	ft_push_b(data);
}

void	ft_stack_cheapest(t_data *data)
{
	int		cost;
	t_stack	*tmp;
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	prev = NULL;
	curr = data->head_a;
	tmp = curr;
	cost = ft_calculate_cost(data->head_a, data->head_b, curr);
	while (curr)
	{
		if (ft_calculate_cost(data->head_a, data->head_b, curr) < cost)
		{
			tmp = curr;
			cost = ft_calculate_cost(data->head_a, data->head_b, curr);
		}
		next = ft_xor(prev, curr->both);
		prev = curr;
		curr = next;
	}
	ft_run_cheap(data, tmp);
}

void	ft_sort(t_data	*data)
{
	int	cost;

	while (ft_stack_size(data->head_a) > 0)
		ft_stack_cheapest(data);
	cost = ft_price_rot_first(data->head_b,
			ft_find_max(data->head_b));
	while (cost > 0)
	{
		ft_rotate(&data->head_b, &data->tail_b, "rb\n");
		cost--;
	}
	while (cost < 0)
	{
		ft_rev_rotate(&data->head_b, &data->tail_b, "rrb\n");
		cost++;
	}
	while (ft_stack_size(data->head_b) > 0)
		ft_push_a(data);
}
