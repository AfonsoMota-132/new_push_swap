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

t_lista *ft_find_max(t_lista *head)
{
    t_lista *max = head;
    t_lista *current = head;
    t_lista *prev = NULL;
    t_lista *next;
    
    while (current)
    {
        if (current->id > max->id)
            max = current;
        
        next = ft_xor(prev, current->both);
        prev = current;
        current = next;
    }
    return max;
}

bool	ft_comp_swap(t_lista *head)
{
	t_lista	*first;
	t_lista	*second;

	first = head;
	if (!head)
		return (false);
	second = first->both;
	return (first->id < second->id);
}

int	ft_price_rot_first(t_lista *head, t_lista *node)
{
	size_t	list_size;
	size_t	i;

	list_size = ft_lista_size(head);
	i = ft_lista_get_index(head, node);
	if (i <= list_size / 2)
		return (i);
	else
		return (-(list_size - i));
}

int	ft_abs(int cost)
{
	if (cost >= 0)
		return (cost);
	else
		return (cost * -1);
}

t_lista	*ft_find_target_in_b(t_lista *head_b, int value)
{
	t_lista	*current;
	t_lista	*prev;
	t_lista	*best_match;
	t_lista	*next;

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

int	ft_calculate_cost(t_lista *head_a, t_lista *head_b, t_lista *node)
{
	t_lista	*target;
	int		cost_a;
	int		cost_b;

	cost_a = ft_price_rot_first(head_a, node);
	target = ft_find_target_in_b(head_b, node->id);
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

void	ft_run_cheap(t_data *data, t_lista *node)
{
	t_lista	*target;
	int		cost_a;
	int		cost_b;

	cost_a = ft_price_rot_first(data->head_a, node);
	target = ft_find_target_in_b(data->head_b, node->id);
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

void	ft_lista_cheapest(t_data *data)
{
	int		cost;
	t_lista	*tmp;
	t_lista	*prev;
	t_lista	*curr;
	t_lista	*next;

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
	ft_push_b(data);
	ft_push_b(data);
	if (ft_comp_swap(data->head_b))
		ft_swap(&data->head_b, &data->tail_b, "sb\n");
	while (ft_lista_size(data->head_a) > 0)
		ft_lista_cheapest(data);
    t_lista *max = ft_find_max(data->head_b);
    int cost = ft_price_rot_first(data->head_b, max);
    
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
	while (ft_lista_size(data->head_b) > 0)
		ft_push_a(data);
}
