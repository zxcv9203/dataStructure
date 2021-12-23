SRCS =	main.c \
		arrayheap.c

OBJS = $(SRCS:.c=.o)

NAME = kruskal

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I.

LIBCOM = -L. -lgraph

GRAPH_DIR = linkedgraph

GRAPH = libgraph.a

all			:	$(NAME)

$(NAME)		:	$(GRAPH) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBCOM)

$(GRAPH)	:
				make -C $(GRAPH_DIR)
				mv $(GRAPH_DIR)/$(GRAPH) .
clean		:
				rm -f $(OBJS)
				make -C $(GRAPH_DIR) clean

fclean		:	clean
				rm -f $(NAME)
				rm -f $(GRAPH)
			
re			:	fclean $(NAME)

.PHONY		:	all clean fclean re