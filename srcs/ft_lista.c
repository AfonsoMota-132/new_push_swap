/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lista.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:00:07 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/02 21:13:33 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_lista	*ft_lista_new(int nbr)
{
	t_lista	*new;

	new = ft_calloc(1, sizeof(t_lista));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->id = -1;
	new->both = NULL;
	return (new);
}

size_t	ft_lista_size(t_lista *head)
{
	t_lista	*prev;
	t_lista	*curr;
	t_lista	*next;
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

int	ft_lista_add_utils(t_lista **head, t_lista **tail, long nbr)
{
	t_lista	*prev;
	t_lista	*curr;
	t_lista	*next;

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
	next = ft_lista_new(nbr);
	if (!next)
		return (1);
	next->both = curr;
	curr->both = ft_xor(prev, next);
	*tail = next;
	return (0);
}

int	ft_lista_add_back(t_lista **head, t_lista **tail, long nbr)
{
	if (nbr >= INT_MAX || nbr <= INT_MIN)
		return (ft_putstr_fd("Error\nNumber needs to be an int!\n", 2), 1);
	if (!*head)
	{
		*head = ft_lista_new(nbr);
		if (*head)
			return (1);
		*tail = *head;
	}
	else
		return (ft_lista_add_utils(head, tail, nbr));
	return (0);
}
