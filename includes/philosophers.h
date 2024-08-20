#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include "../Libft-1337/libft.h"

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
    int left_fork;
    int right_fork;
    int meals_eaten;
    long last_meal;
    pthread_t thread;

} t_philosopher;

typedef struct s_limits
{
    t_infos *data;
    t_philosopher *abtal;
    pthread_mutex_t *forks;
    pthread_mutex_t *print;
    int flag;
} t_limits;

// parsing

int check_overflow(char *number);
void fill_struct(char **data, int ac, t_infos *info);