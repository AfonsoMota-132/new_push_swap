/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:25:52 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/02 21:11:36 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdint.h>
# include <limits.h>

typedef struct s_lista
{
	int					nbr;
	int					id;
	struct s_lista		*both;
}	t_lista;

typedef struct s_data
{
	t_lista	*head_a;
	t_lista	*tail_a;
	t_lista	*head_b;
	t_lista	*tail_b;
}	t_data;

t_data	*ft_new_data(int ac, char **av);
void	ft_free_data(t_data	*data);
int		ft_lista_add_back(t_lista **head, t_lista **tail, long nbr);
t_lista	*ft_xor(t_lista *x, t_lista *y);
void	ft_free_lista(t_lista *curr);

#endif
