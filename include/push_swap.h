/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:54 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/10 14:55:42 by lscarcel         ###   ########.fr       */
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


// parsing
void 	only_int_in_stack(char **argv);
void	check_and_store_arg(t_element **top_of_stack, t_element **bot_of_stack, int argc, char **argv);
void	store_arg(t_element **top_of_stack, t_element **bot_of_stack, char **argv);
int 	is_stack_already_sorted(t_element **top_of_stack, int argc);
int		check_for_duplicates(t_element **top_of_stack);

// sorting
void	little_sort(t_element *top_of_stack, t_element *bot_of_stack);

// Opérations
void	swap(t_element **tail, char instruction);
void	rotate(t_element **top_of_stack, char instruction);
void	reverse_rotate(t_element **top_of_stack, char instruction);

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