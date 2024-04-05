/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:54 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/04 12:16:10 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

//libairies
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include "../libs/Libft/libft.h"

# define PUSH_SWAP_H
# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAIL		1

typedef struct s_element
{
    int value;
    struct s_element *next;
    struct s_element *prev;
} t_element;


// functions
void 	check_arg(char **argv);
void	store_arg(t_element **head, t_element **tail, char **argv);
void	init_struct(t_element **element);
void	check_and_store_arg(t_element **element, t_element **tail, char **argv);
void	create_head_and_tail(t_element **head, t_element *node, t_element **current);
void	last_node(t_element **tail_a, t_element **head);
void	swap(t_element **tail, char instruction);
void	rotate(t_element **tail, char instruction);
// void	push_b(t_element **tail, t_element **tail, t_element **head);

// Colors
# define COLOR_BLACK "\033[0;30m" // Black
# define COLOR_RED "\033[0;91m" // Red
# define COLOR_GREEN "\033[0;32m" // Green
# define COLOR_YELLOW "\033[0;33m" // Yellow
# define COLOR_BLUE "\033[0;34m" // Blue
# define COLOR_PURPLE "\033[0;35m" // Purple
# define COLOR_CYAN "\033[0;36m" // Cyan
# define COLOR_WHITE "\033[0m" // White
# define TEXT_BOLD "\033[1m" // Bold text
# define TEXT_RESET "\033[0m" // Reset text attributes

#endif