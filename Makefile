###############################################################################
 ################################           ##################################
##############################    Variables    ################################
 ################################           ##################################
###############################################################################

NAME				=	push_swap

B_NAME				=	checker

HEADERS				=	-I includes/

PUSH_SWAP_HEADER	=	includes/push_swap.h

CHECKER_HEADER		=	includes/checker.h

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror

RM					=	rm -f

PUSH_SWAP_SRCS		=	srcs/push_swap.c srcs/input_output/ft_split.c \
						srcs/input_output/parse_input.c srcs/linked_lists_operations/list_add.c \
						srcs/stack_operations/pop_and_push.c srcs/stack_operations/swap_and_rotate.c \
						srcs/stack_sort_instructions/push.c srcs/stack_sort_instructions/rotate.c \
						srcs/stack_sort_instructions/reverse_rotate.c srcs/stack_sort_instructions/swap.c \
						srcs/input_output/string_manip.c srcs/input_output/utils.c \
						srcs/linked_lists_operations/list_clear.c srcs/linked_lists_operations/list_create.c

PUSH_SWAP_OBJS		=	$(PUSH_SWAP_SRCS:.c=.o)

CHECKER_SRCS		=	checker/*.c checker/*/*.c

CHECKER_OBJS		=	$(CHECKER_SRCS:.c=.o)

###############################################################################
 #########################                          ##########################
######################     Push Swap Creation Rules     #######################
 #########################                          ##########################
###############################################################################

all: $(NAME)

$(PUSH_SWAP_OBJS): $(PUSH_SWAP_HEADER)

$(NAME): $(PUSH_SWAP_OBJS)
		$(CC) $(CFLAGS) $(HEADERS) $(PUSH_SWAP_OBJS) -o $(NAME)

###############################################################################
 ##########################                        ###########################
########################    Checker Creation Rules    #########################
 ##########################                        ###########################
###############################################################################

$(CHECKER_OBJS): $(CHECKER_HEADER) $(PUSH_SWAP_HEADER)

$(B_NAME): $(CHECKER_OBJS)
		$(CC) $(CFLAGS) $(HEADERS) $(CHECKER_OBJS) -o $(B_NAME)

bonus: $(B_NAME)

###############################################################################
 ##############################               ################################
############################    General Rules    ##############################
 ##############################               ################################
###############################################################################

%.o: %.c
		@echo "\033[1;32m\nCompiling objects ...\033[0m"
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

re: fclean all

clean:
		@echo "\033[1;32m\nCleaning object files ...\033[0m"
		@echo "\033[1;31m\nRemove push_swap object files ...\033[0m"
		$(RM) $(PUSH_SWAP_OBJS)
		@echo "\033[1;31m\nRemove checker object files ...\033[0m"
		$(RM) $(CHECKER_OBJS)
		@echo "\033[1;32m\nCleaning object files terminated successfully\n\033[0m"

fclean: clean
		@echo "\033[1;32mCleaning executables ...\033[0m"
		@echo "\033[1;31m\nRemove push_swap ...\033[0m"
		$(RM) $(NAME)
		@echo "\033[1;31m\nRemove checker ...\033[0m"
		$(RM) $(B_NAME)
		@echo "\033[1;32m\nFull Cleaning terminated successfully\n\033[0m"

.PHONY: all bonus clean fclean re
.SECONDARY: $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
