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

typedef struct s_stack
{
	int					nbr;
	int					id;
	struct s_stack		*both;
}	t_stack;

typedef struct s_data
{
	t_stack	*head_a;
	t_stack	*tail_a;
	t_stack	*head_b;
	t_stack	*tail_b;
	size_t	size;
}	t_data;

//	Ft_data

int		ft_iterate_split(t_data *data, char **split);
t_data	*ft_new_data(int ac, char **av);
void	ft_free_data(t_data	*data);

//	Ft_index

t_stack	*ft_index_min(t_stack *curr);
void	ft_stack_index(t_stack *head);
bool	ft_ver_sorted(t_data *data);

//	Ft_sort

void	ft_run_cheap_utils(t_data *data, int *cost_a, int *cost_b);
void	ft_run_cheap(t_data *data, t_stack *node);
void	ft_stack_cheapest(t_data *data);
void	ft_sort(t_data	*data);

//	Ft_cost

int		ft_calculate_cost(t_stack *head_a, t_stack *head_b, t_stack *node);
t_stack	*ft_find_in_b(t_stack *head_b, int value);
int		ft_price_rot_first(t_stack *head, t_stack *node);

//	Ft_stack

t_stack	*ft_stack_new(int nbr);
int		ft_stack_add_utils(t_stack **head, t_stack **tail, long nbr);
int		ft_stack_add_back(t_stack **head, t_stack **tail, long nbr);
void	ft_free_stack(t_stack *curr);

//	Ft_stack_utils

t_stack	*ft_find_max(t_stack *head);
t_stack	*ft_get_tail(t_stack *curr);
size_t	ft_stack_size(t_stack *head);
size_t	ft_stack_get_index(t_stack	*head, t_stack *node);

//	Ft_utils.c

int		ft_ver_str(char	*str);
int		ft_abs(int cost);
bool	ft_comp_swap(t_stack *head);
t_stack	*ft_find_max(t_stack *head);

// operations
//		ft_oper_utils.c
t_stack	*ft_xor(t_stack *x, t_stack *y);
t_stack	*ft_rmv_head(t_stack **head);
t_stack	*ft_rmv_tail(t_stack **tail);

//		ft_push_swap.c
void	ft_push(t_stack **target, t_stack **src, char *str);
void	ft_push_a(t_data *data);
void	ft_push_b(t_data *data);
void	ft_swap(t_stack **head, t_stack **tail, char *str);
void	ft_swap_both(t_data *data);

//		ft_rotate
//
void	ft_rotate(t_stack **head, t_stack **tail, char *str);
void	ft_rotate_both(t_data *data);
void	ft_rev_rotate(t_stack **head, t_stack **tail, char *str);
void	ft_rev_rot_both(t_data *data);

#endif
