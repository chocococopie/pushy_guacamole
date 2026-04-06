#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// small

typedef struct r_struct
{
	int				value;
	int				index;
	struct r_struct	*next;
}					t_node;

// big

typedef struct s_struct
{
	int				size;
	t_node			*top;
}					t_stack;

// functions

int					main(int argc, char **argv);
int					is_sorted(t_stack *a);
void				free_split(char **split);
int					init_stacks(t_stack **a, t_stack **b);
int					handle_args(int argc, char **argv, t_stack *a);
int	stack_size(t_stack *s);
void	sort_stack(t_stack **a, t_stack **b);

char	**ft_split(char const *s, char c);



// parser

int	fill_stack(t_stack *a, char **argv, int count);
t_node	*new_node(int value);
void	add_back(t_stack *a, t_node *node);
int	exists_in_stack(t_stack *a, int value);
long	ft_atol(const char *str);
int		is_numeric(char *str);
int	assign_indexes(t_stack *s);

// split

int	count_words(const char *s, char c);
char	*copy_word(const char *s, int start, int len);

// operations

void			put_op(const char *op);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// operations helpers

void			swap_first_two(t_stack *s);
void			push_top(t_stack *src, t_stack *dst);
void			rotate_up(t_stack *s);
void			rotate_down(t_stack *s);

// sorting

void    sorting_3(t_stack **a);
void    sorting_45(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);

int	error_return(void);
void	free_stacks(t_stack *a, t_stack *b);

#endif
