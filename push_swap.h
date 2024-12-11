/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:34:56 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/11 18:19:04 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "stdio.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	int				target_index;
	int				move_cost_a;
	int				move_cost_b;
}	t_stack;

typedef struct s_move_cost
{
	int	move_cost_a;
	int	move_cost_b;
}	t_move_cost;

int		check_overflow(char **argv, int argc);
int		ft_atoi(const char *str);
int		is_nbr(char *str);
int		is_sorted(t_stack *s);
void	push(t_stack **s, int value);
int		pop(t_stack **s);
void	sx(t_stack **s_a, t_stack **s_b, char *op);
void	px(t_stack **s_a, t_stack **s_b, char *op);
void	rx(t_stack **s_a, t_stack **s_b, char *op);
void	rrx(t_stack **s_a, t_stack **s_b, char *op);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		list_size(t_stack *s);
void	apply_op(t_stack **s, char *op);
int		list_max(t_stack *s);
int		list_min(t_stack *s);
int		has_less_operations(t_move_cost *ind_1,
			t_move_cost *ind_2, int len_1, int len_2);
t_stack	*parse_args(char **nbrs, int argc);
int		check_args(char **argv, int argc);
int		repeated_nbrs(t_stack *s);
int		get_ind(t_stack *s, int value);
int		list_average(t_stack *s_a);;
void	sort_stack(t_stack *s_a, t_stack *s_b);
void	sort_first_three_elements(t_stack **s_a);
void	sort_remaining_elements(t_stack **s_a, int size);
void	optimize_rotation_moves(t_stack **s_1, t_stack **s_2,
			t_move_cost *cheaper_inds);
void	send_to_stack_a(t_stack **s_a, t_stack **s_b);
char	**ft_split(const char *s, char c);
void	sort_and_transfer_to_a(t_stack **s_a, t_stack **s_b);
void	calculate_moves_cost(t_stack **a, t_stack **b);
void	reset_ind(t_stack **s);
void	ft_lstclear(t_stack **lst);
int		is_valid_op(char *op);
void	ft_free(char **splited_str);

#endif