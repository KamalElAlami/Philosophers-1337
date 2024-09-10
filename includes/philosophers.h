/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:54:51 by kael-ala          #+#    #+#             */
/*   Updated: 2024/09/10 12:58:30 by kael-ala         ###   ########.fr       */
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
    DETACH,
    INIT,
    LOCK,
    UNLOCK,
    DESTROY,
} e_choices;

typedef enum e_state
{
    TAKE_FORK,
    EAT,
    SLEEP,
    THINK,
    DIE,
} e_state;

typedef enum e_time
{
    MILLI,
    MICRO,
} e_time;

typedef struct s_infos
{
    long start_time;
    int num_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int meals;
    int end_simulation;
    pthread_mutex_t *end_mutex;
    pthread_mutex_t *print_mutex;
}   t_infos;


typedef struct t_philosopher
{
    int index;
    int fork;
    int meals_eaten;
    long last_meal;
    int fork_taken;
    t_infos *info;
    pthread_t thread;
    pthread_mutex_t *forchette;
    pthread_mutex_t *safty;
    struct t_philosopher *next;

} t_philosopher;




// helpers
t_philosopher *new_batal(int index, t_infos *info);
void add_lbatal(t_philosopher **head, t_philosopher *node);
void print_list(t_philosopher *list);
void ft_mutex(pthread_mutex_t *mutex, e_choices choice);
void ft_pthread(pthread_t *thread, t_philosopher **philos, e_choices choice);
long gettimestamp(e_time unit);
void ft_usleep(long microseconds, t_philosopher *rijal);

// parsing
int check_overflow(char *number);
int check_validity(char **data);
void fill_struct(char **data, int ac, t_infos *info);
void ft_perror(char *error_msg);
void error_handler(int error);
void data_init(t_infos info, t_philosopher **philos);


// routine 
int check_death(t_philosopher *batal);
int sleepnthink(t_philosopher *rijal);
int drop_forks(t_philosopher *rijal);
int eat(t_philosopher *rijal);
int take_forks(t_philosopher *rijal);
void print_state(t_philosopher *batal, e_state state);
void *routine_labtal(void *abtal);


