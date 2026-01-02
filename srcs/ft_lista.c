/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lista.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:00:07 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/02 21:10:08 by afogonca         ###   ########.fr       */
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

int	ft_lista_add_utils(t_lista **list, long nbr)
{
	t_lista	*prev;
	t_lista	*curr;
	t_lista	*next;

	prev = NULL;
	curr = *list;
	while (curr != NULL)
	{
		if (curr->nbr == nbr)
			return (ft_putstr_fd("Error!\nDuplicate Detected\n", 2), 1);
		next = ft_XOR(prev, curr->both);
		if (!next)
			break ;
		prev = curr;
		curr = next;
	}
	next = ft_lista_new(nbr);
	next->both = curr;
	curr->both = ft_xor(prev, next);
	return (0);
}

int	ft_lista_add_back(t_lista **list, long nbr)
{
	if (nbr >= INT_MAX || nbr <= INT_MIN)
		return (ft_putstr_fd("Error\nNumber needs to be an int!\n", 2), 1);
	if (!*list)
		*list = ft_lista_new(nbr);
	else
		return (ft_lista_add_utils(list, nbr));
	return (0);
}

void	ft_free_lista(t_lista *curr)
{
	t_lista	*prev;
	t_lista	*next;

	prev = NULL;
	while (curr != NULL)
	{
		next = ft_XOR(prev, curr->both);
		prev = curr;
		curr = next;
		free(prev);
	}
}

t_lista	*ft_xor(t_lista *x, t_lista *y)
{
	return ((t_lista *)((uintptr_t)(x) ^ (uintptr_t)(y)));
}
