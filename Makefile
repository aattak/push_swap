###############################################################################
 ################################           ##################################
##############################    Variables    ################################
 ################################           ##################################
###############################################################################

NAME				=	push_swap

B_NAME				=	checker

LIB_PUSH_SWAP		=	lib_push_swap.a

LIB_CHECKER			=	lib_checker.a

HEADERS				=	-I includes/

PUSH_SWAP_HEADER	=	includes/push_swap.h

CHECKER_HEADER		=	includes/checker_bonus.h includes/get_next_line.h

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror

RM					=	rm -f

PUSH_SWAP_MAIN_SRC	=	srcs/push_swap.c 

PUSH_SWAP_MAIN_OBJ	=	$(PUSH_SWAP_MAIN_SRC:.c=.o)

PUSH_SWAP_SRCS		=	srcs/input_output/ft_split.c \
						srcs/input_output/parse_input.c srcs/linked_lists_operations/list_add.c \
						srcs/stack_operations/pop_and_push.c srcs/stack_operations/swap_and_rotate.c \
						srcs/stack_sort_instructions/push.c srcs/stack_sort_instructions/rotate.c \
						srcs/stack_sort_instructions/reverse_rotate.c srcs/stack_sort_instructions/swap.c \
						srcs/input_output/string_manip.c srcs/input_output/utils.c \
						srcs/linked_lists_operations/list_clear.c srcs/linked_lists_operations/list_create.c \
						srcs/linked_lists_operations/list_utils.c

PUSH_SWAP_OBJS		=	$(PUSH_SWAP_SRCS:.c=.o)

CHECKER_MAIN_SRC	=	checker_srcs/checker_bonus.c

CHECKER_MAIN_OBJ	=	$(CHECKER_MAIN_SRC:.c=.o)

CHECKER_SRCS		=	checker_srcs/get_next_line/get_next_line.c checker_srcs/get_next_line/get_next_line_utils.c \
						checker_srcs/instructions/apply_instruction.c checker_srcs/instructions/instructions_utils.c

CHECKER_OBJS		=	$(CHECKER_SRCS:.c=.o)

###############################################################################
 #########################                          ##########################
######################     Push Swap Creation Rules     #######################
 #########################                          ##########################
###############################################################################

all: $(NAME)

$(PUSH_SWAP_OBJS): $(PUSH_SWAP_HEADER)

$(LIB_PUSH_SWAP): $(PUSH_SWAP_OBJS)
		@echo "\033[1;32m\nBuilding lib_push_swap.a ...\033[0m"
		ar rcs $(LIB_PUSH_SWAP) $(PUSH_SWAP_OBJS)
		@echo "\033[1;32m\nlib_push_swap.a built successfully\n\033[0m"

$(PUSH_SWAP_MAIN_OBJ): $(PUSH_SWAP_HEADER)

$(NAME): $(PUSH_SWAP_MAIN_OBJ) $(LIB_PUSH_SWAP)
		@echo "\033[1;32m\nBuilding push_swap ...\033[0m"
		$(CC) $(CFLAGS) $(HEADERS) $(PUSH_SWAP_MAIN_OBJ) $(LIB_PUSH_SWAP) -o $(NAME)
		@echo "\033[1;32m\npush_swap built successfully\n\033[0m"

###############################################################################
 ##########################                        ###########################
########################    Checker Creation Rules    #########################
 ##########################                        ###########################
###############################################################################

$(CHECKER_OBJS): $(CHECKER_HEADER) $(PUSH_SWAP_HEADER)

$(LIB_CHECKER): $(CHECKER_OBJS)
		@echo "\033[1;32m\nBuilding lib_checker.a ...\033[0m"
		ar rcs $(LIB_CHECKER) $(CHECKER_OBJS)
		@echo "\033[1;32m\nlib_checker.a built successfully\n\033[0m"

$(CHECKER_MAIN_OBJ): $(CHECKER_HEADER) $(PUSH_SWAP_HEADER)

$(B_NAME): $(CHECKER_MAIN_OBJ) $(LIB_PUSH_SWAP) $(LIB_CHECKER)
		@echo "\033[1;32m\nBuilding checker ...\033[0m"
		$(CC) $(CFLAGS) $(HEADERS) $(CHECKER_MAIN_OBJ) $(LIB_CHECKER) $(LIB_PUSH_SWAP) -o $(B_NAME)
		@echo "\033[1;32m\nchecker built successfully\n\033[0m"

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
		$(RM) $(PUSH_SWAP_MAIN_OBJ) $(PUSH_SWAP_OBJS)
		@echo "\033[1;31m\nRemove checker object files ...\033[0m"
		$(RM) $(CHECKER_MAIN_OBJ) $(CHECKER_OBJS)
		@echo "\033[1;32m\nCleaning object files terminated successfully\n\033[0m"

fclean: clean
		@echo "\033[1;32mCleaning executables ...\033[0m"
		@echo "\033[1;31m\nRemove push_swap ...\033[0m"
		$(RM) $(NAME)
		@echo "\033[1;31m\nRemove lib_push_swap.a ...\033[0m"
		$(RM) $(LIB_PUSH_SWAP)
		@echo "\033[1;31m\nRemove checker ...\033[0m"
		$(RM) $(B_NAME)
		@echo "\033[1;31m\nRemove lib_checker.a ...\033[0m"
		$(RM) $(LIB_CHECKER)
		@echo "\033[1;32m\nFull Cleaning terminated successfully\n\033[0m"

.PHONY: all bonus clean fclean re
.SECONDARY: $(PUSH_SWAP_MAIN_OBJ) $(PUSH_SWAP_OBJS) $(CHECKER_MAIN_OBJ) $(CHECKER_OBJS) $(LIB_PUSH_SWAP) $(LIB_CHECKER)
