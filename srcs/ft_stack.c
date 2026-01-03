/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:00:07 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/02 21:13:33 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_stack	*ft_stack_new(int nbr)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->id = -1;
	new->both = NULL;
	return (new);
}

int	ft_stack_add_utils(t_stack **head, t_stack **tail, long nbr)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	prev = NULL;
	curr = *head;
	while (curr != NULL)
	{
		if (curr->nbr == nbr)
			return (ft_putstr_fd("Error!\nDuplicate Detected\n", 2), 1);
		next = ft_xor(prev, curr->both);
		if (!next)
			break ;
		prev = curr;
		curr = next;
	}
	next = ft_stack_new(nbr);
	if (!next)
		return (1);
	next->both = curr;
	curr->both = ft_xor(prev, next);
	*tail = next;
	return (0);
}

int	ft_stack_add_back(t_stack **head, t_stack **tail, long nbr)
{
	if (nbr >= INT_MAX || nbr <= INT_MIN)
		return (ft_putstr_fd("Error\nNumber needs to be an int!\n", 2), 1);
	if (!*head)
	{
		*head = ft_stack_new(nbr);
		if (!*head)
			return (1);
		*tail = *head;
	}
	else
		return (ft_stack_add_utils(head, tail, nbr));
	return (0);
}

void	ft_free_stack(t_stack *curr)
{
	t_stack	*prev;
	t_stack	*next;

	prev = NULL;
	while (curr != NULL)
	{
		next = ft_xor(prev, curr->both);
		prev = curr;
		curr = next;
		free(prev);
	}
}
