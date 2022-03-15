/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:44:31 by fbonini-          #+#    #+#             */
/*   Updated: 2022/02/16 16:44:34 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>

# define TOTAL_ACTIONS (5)

typedef enum e_action {
	FORK = 0,
	EAT,
	SLEEP,
	THINK,
	DIE,
}	t_action;

typedef pthread_mutex_t	t_mutex;
typedef void			t_printer(long time, int pos);

typedef struct s_mem
{
	int				total_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				died;
	long			start_clock;
	pthread_mutex_t	*lock_print;
	pthread_mutex_t	*lock_dinner;
}	t_mem;

typedef struct s_philo
{
	int				pos;
	int				eaten_times;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*lock_meals;
	pthread_mutex_t	*lock_meal_time;
	t_mem			*mem;
	t_action		action;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
long		ft_atol(const char *str);
void		ft_parse_args(int argc, char **argv);
void		ft_pre_dinner(
				t_mem *mem,
				t_mutex **fork,
				t_philo **philos,
				char **argv);
void		ft_start_dinner(int total, t_philo *philos);
void		ft_create_threads(int total, t_philo *philos, pthread_t *checker);
void		ft_join_threads(int total, t_philo *philos, pthread_t *checker);
long		ft_dinner_timer(void);
void		*ft_dinner(void *ptr);
void		*ft_check_dinner(void *ptr);
long		ft_timer(long dinner_start);
void		ft_wait_time(int time_to_wait);
int			ft_dinner_is_over(t_philo *philo);
void		ft_philo_think(t_philo *philo);
void		ft_philo_sleep(t_philo *philo);
void		ft_philo_eat(t_philo *philo);
int			ft_get_eaten_times(t_philo *philo);
int			ft_get_last_meal(t_philo *philo);
void		ft_set_meal_time(t_philo *philo);
int			ft_all_ate(t_philo *philos);
void		ft_get_print(t_philo *philo);
void		ft_philo_died(t_philo *philo);

void		ft_print_fork(long time, int pos);
void		ft_print_eat(long time, int pos);
void		ft_print_sleep(long time, int pos);
void		ft_print_think(long time, int pos);
void		ft_print_die(long time, int pos);

void		ft_fail_prep(t_mem *mem, t_mutex *forks, t_philo *philos);
void		ft_end_dinner(t_mem *mem, t_mutex *forks, t_philo *philos);

#endif