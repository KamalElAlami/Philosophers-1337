/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:54:51 by kael-ala          #+#    #+#             */
/*   Updated: 2024/08/23 11:13:38 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <errno.h>
#include "../Libft-1337/libft.h"

#define RED_COLOR		"\x1b[31m"
#define YELLOW_COLOR	 	"\x1b[33m"
#define GREEN_COLOR	 	"\x1b[32m"
#define RESET		 	"\x1b[0m"


typedef enum e_choices
{
    CREATE,
    JOIN,
    DESTROY,
    INIT,
    LOCK,
    UNLOCK,
} e_choices;

typedef struct s_infos
{
    long start_time;
    int num_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int meals;
}   t_infos;


typedef struct t_philosopher
{
    int index;
    int fork;
    int meals_eaten;
    long last_meal;
    t_infos info;
    pthread_t thread;
    pthread_mutex_t *forchette;
    struct t_philosopher *next;

} t_philosopher;




// helpers

t_philosopher *new_batal(int index);
void add_lbatal(t_philosopher **head, t_philosopher *node);
void print_list(t_philosopher *list);
void ft_mutex(pthread_mutex_t *mutex, e_choices choice);
long gettimestamp(void);

// parsing

int check_overflow(char *number);
void fill_struct(char **data, int ac, t_infos *info);
void ft_perror(char *error_msg);
void error_handler(int error);
void data_init(t_infos info, t_philosopher **philos);


