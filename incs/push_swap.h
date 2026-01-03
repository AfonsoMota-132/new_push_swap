/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:25:52 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 12:04:16 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdint.h>
# include <stdbool.h>
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
	size_t	size;
}	t_data;

t_data	*ft_new_data(int ac, char **av);
void	ft_free_data(t_data	*data);
int		ft_lista_add_back(t_lista **head, t_lista **tail, long nbr);
t_lista	*ft_xor(t_lista *x, t_lista *y);
void	ft_free_lista(t_lista *curr);
size_t	ft_lista_size(t_lista *head);
void	ft_lista_index(t_lista *head);
bool	ft_ver_sorted(t_data *data);
void	ft_rev_rot_both(t_data *data);
void	ft_print_lista(t_lista *curr);

void	ft_sort(t_data	*data);
size_t	ft_lista_get_index(t_lista	*head, t_lista *node);
t_lista	*ft_get_tail(t_lista *curr);

//	Operations
void	ft_swap(t_lista **head, t_lista **tail, char *str);
void	ft_swap_both(t_data *data);

void	ft_push_b(t_data *data);
void	ft_push_a(t_data *data);

void	ft_rotate(t_lista **head, t_lista **tail, char *str);
void	ft_rotate_both(t_data *data);
void	ft_rev_rotate(t_lista **head, t_lista **tail, char *str);
void	ft_rev_rot_both(t_data *data);


t_lista	*ft_rmv_head(t_lista **lista);
t_lista	*ft_rmv_tail(t_lista **tail);

#endif
