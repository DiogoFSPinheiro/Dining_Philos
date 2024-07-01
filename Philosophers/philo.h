/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:37:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/28 02:27:39 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <errno.h>

typedef struct s_data	t_data;

typedef enum s_status
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}		t_philo_status;
/*Time*/
typedef enum e_time
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}		t_time;

/*readablity*/
typedef enum e_exit
{
	SUCCESS,
	FAILURE,
}	t_exit;

/*OPCODE for mutex*/
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

/*Forks*/
typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}					t_fork;

/*Philos*/
typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	t_fork			*first_fork; // l_fork
	t_fork			*second_fork; //r_fork
	long			last_meal;
	int				meals_eaten;
	bool			full;
	pthread_mutex_t	philo_mutex;
	t_data			*data;
}			t_philo;

/*Input saver ./philo 5 800 200 200 [5]*/
struct s_data
{
	long			nbr_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_of_meals;
	long			start_sim;
	long			threads_running_nbr;
	bool			end_sim;
	bool			all_threads_ready;
	pthread_mutex_t	table_mutex;
	pthread_mutex_t	log_mutex;
	pthread_t		monitor_thread;
	t_fork			*forks;
	t_philo			*philos;
};

int		main(int c, char *v[]);
int		ft_data_parsing(t_data *data, char **args);
void	ft_data_init(t_data *data);
void	ft_log_status(t_philo *philo, t_philo_status status);

void	ft_meal_start(t_data *data);
void	*ft_meal_simulation(void *arg);
void	*monitor_philo(void *arg);
void	ft_increase_long(pthread_mutex_t *mutex, long *value);
bool	ft_all_thread_runnning(pthread_mutex_t *mutex, long *threads,
			long philo_nbr);
void	*ft_solo_philo(void *arg);
void	ft_think(t_philo *philo, bool pre_start);
void	ft_desinc_philo(t_philo *philo);

void	ft_cleanup(t_data *data);
//-------utils---------
int		ft_isdigit(int c);
long	ft_atol(const char *str);
void	ft_error_exit(char *error);
void	ft_print_data(t_data *data);
long	ft_gettime(t_time code);
void	ft_usleep(long usec, t_data *data);
//------safe guards------
void	ft_safe_phread(pthread_t *thread, void *(*func)(void *),
			void *data, t_opcode code);
void	ft_safe_mutex(pthread_mutex_t *mutex, t_opcode code);
void	*ft_safe_malloc(int size);
//------setters and getters------
void	ft_set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool	ft_get_bool(pthread_mutex_t *mutex, bool *value);
void	ft_set_long(pthread_mutex_t *mutex, long *dest, long value);
long	ft_get_long(pthread_mutex_t *mutex, long *value);
bool	ft_sim_finished(t_data *data);
//------sincronization----------
void	ft_wait_threads(t_data *data);

#endif
