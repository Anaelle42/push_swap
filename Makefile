NAME	=push_swap

HEADER	=	push_swap.h

SRCS	=	operations_1.c \
			operations_2.c \
			operations_3.c \
			operations_4.c \
			push_swap.c \
			check_args.c \
			lst_utils.c \
			algorithm.c \
			sort_to_a.c \
			sort_to_b.c \
 			position.c \
			do_op.c \
			opti_move.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean	:
	$(RM) $(OBJS) 

fclean	:	clean
	$(RM) $(NAME) 			

re	:	fclean all

.PHONY	:	all clean fclean re 
