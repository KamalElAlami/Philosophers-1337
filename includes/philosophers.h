#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include "../Libft-1337/libft.h"

#define RED_COLOR		"\x1b[31m"
#define YELLOW_COLOR	 	"\x1b[33m"
#define GREEN_COLOR	 	"\x1b[32m"
#define RESET		 	"\x1b[0m"

typedef struct s_infos
{
    int num_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int meals;
}   t_infos;


typedef struct s_philosopher
{
    int index;
    int fork;
    int meals_eaten;
    long last_meal;
    int flag;
    t_infos info;
    pthread_t thread;
    pthread_mutex_t *forchette;
    struct t_philosofer *next;

} t_philosopher;






// parsing

int check_overflow(char *number);
void fill_struct(char **data, int ac, t_infos *info);
void ft_perror(char *error_msg);