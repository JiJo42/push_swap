# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 09:32:42 by dleclerc          #+#    #+#              #
#    Updated: 2024/12/11 07:35:03 by dleclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Silent-------------#
ifndef VERBOSE
.SILENT:
endif
#-Color--------------#
DEFAULT	=	\033[0;39m
GRAY	=	\033[0;90m
RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
BLUE	=	\033[0;94m
MAGENTA	=	\033[0;95m
CYAN	=	\033[0;96m
WHITE 	=	\033[0;97m
#-Variable-----------------------------#
PRINTF		=	printf
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f
CC			=	cc
NAME		=	push_swap
NAME_B		=	checker
#-//---------------------------#
OBJ_DIR			=	obj
OBJB_DIR		=	objb
#-//---------------------------#
SRC_DIR			=	source
SRCB_DIR		=	source_bonus
#-//---------------------------#
HEADER		=	libft/libft.h
#-Source------------------------------------#
SRC			= 	push_swap.c					\
				push_swap_parsing.c			\
				push_swap_stack_utils.c		\
				push_swap_parsing_utils.c	\
				push_swap_utils.c			\
				swap.c						\
				push.c						\
				rotate.c					\
				reverse_rotate.c
#-Source-Bonus------------------------------#
SRCB		=	checker_bonus.c
#-Object----------------------------------------------#
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJB		=	$(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))
#-Progress-vars----------------------------------------------------------------------------------------------------------#
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
#-Progress-vars-bonus-----------------------------------------------------------------------------------------------------#
SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))
#-Rule-------------------------------------------------------------------------------------------------------------------#
all				:	$(NAME)

$(NAME)			:	$(OBJ) $(OBJ2)
#					$(RM) bonus
#					$(RM) -r $(OBJB_DIR)
					$(PRINTF) "\n"
					sleep 0.2
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(GREEN)make dependencies$(DEFAULT)\n"
					$(PRINTF) "\n"
					make -C libft --silent
					sleep 0.2
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(GREEN)dependencies done$(DEFAULT)\n"
					sleep 0.4
					$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(CYAN)$(NAME)$(GREEN) is up to date!\n$(DEFAULT)"

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c | $(OBJ_DIR)
					$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
					$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says: \t$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
					$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)
#-Rule-Bonus------------------------------------------------------------------------------------------------------------#
bonus			:	$(OBJB)
#					$(RM) -r $(OBJ_DIR)
					touch bonus
					$(PRINTF) "\n"
					sleep 0.2
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(GREEN)make dependencies$(DEFAULT)\n"
					$(PRINTF) "\n"
					make -C libft --silent
					sleep 0.2
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(GREEN)dependencies done$(DEFAULT)\n"
					sleep 0.4
					$(CC) $(CFLAGS) $(OBJB) libft/libft.a -o $(NAME_B)
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(CYAN)$(NAME_B)$(GREEN) is up to date!\n$(DEFAULT)"
					
$(OBJB_DIR)/%.o: 	$(SRC_DIRB)/%.c | $(OBJB_DIR)
					$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
					$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says: \t$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
					$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(OBJB_DIR)		:
					mkdir -p $(OBJB_DIR)
#-Rule-Cleaning---------------------------------------------------------------------------------------------------------#
clean			:
					$(RM) -r $(OBJ_DIR)
					$(RM) -r $(OBJB_DIR)
					$(PRINTF) "$(GRAY)$(NAME) says: \t$(YELLOW)_*#*__$(CYAN)Cleaning up object$(YELLOW)__*#*_"
					sleep 0.6
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t$(YELLOW)_*#*_🧹_*#*_🧹_*#*_*#*_*#*_*#*_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t$(YELLOW)_________*#*_🧹_*#*_🧹_*#*_*#*_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t$(YELLOW)_________________*#*_🧹_*#*_🧹_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t$(YELLOW)____________clean_🧹___________\n\n$(DEFAULT)"
					sleep 0.3
					make clean -C libft --silent

fclean			:	clean
					$(RM) $(NAME)
					$(RM) bonus
					$(PRINTF) "$(GRAY)$(NAME) says: \t$(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.3
					make do_clean=0 fclean -C libft --silent

re				:	fclean all
#-Rule-No-Dependencies------------------------------------------------------------------------------------------------------#
clean_nodp		:
					$(RM) -r $(OBJ_DIR)
					$(RM) -r $(OBJB_DIR)
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t$(YELLOW)____________clean_🧹___________\n\n$(DEFAULT)"
					sleep 0.3

fclean_nodp		:	clean_nodp
					$(RM) $(NAME)
					$(RM) bonus
					$(PRINTF) "$(GRAY)$(NAME) says: \t$(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.3

re_nodp			:	fclean_nodp all
#-PHONY----------------------------------------------------------------------#
.PHONY			:	all clean clean_nodp fclean fclean_nodp re re_nodp bonus
