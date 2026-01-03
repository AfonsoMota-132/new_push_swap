/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:57:17 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 18:58:22 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*ft_find_max(t_stack *head)
{
	t_stack	*max;
	t_stack	*current;
	t_stack	*prev;
	t_stack	*next;

	max = head;
	current = head;
	prev = NULL;
	while (current)
	{
		if (current->id > max->id)
			max = current;
		next = ft_xor(prev, current->both);
		prev = current;
		current = next;
	}
	return (max);
}

t_stack	*ft_get_tail(t_stack *curr)
{
	t_stack	*prev;
	t_stack	*next;

	prev = NULL;
	while (curr)
	{
		next = ft_xor(curr->both, prev);
		prev = curr;
		curr = next;
	}
	return (prev);
}

size_t	ft_stack_size(t_stack *head)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;
	size_t	i;

	i = 0;
	curr = head;
	prev = NULL;
	while (curr)
	{
		next = ft_xor(prev, curr->both);
		prev = curr;
		curr = next;
		i++;
	}
	return (i);
}

size_t	ft_stack_get_index(t_stack	*head, t_stack *node)
{
	size_t	i;
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	i = 0;
	prev = NULL;
	curr = head;
	while (curr && curr != node)
	{
		next = ft_xor(prev, curr->both);
		prev = curr;
		curr = next;
		i++;
	}
	return (i);
}

