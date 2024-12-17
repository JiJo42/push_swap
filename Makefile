# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 09:32:42 by dleclerc          #+#    #+#              #
#    Updated: 2024/12/17 11:30:49 by dleclerc         ###   ########.fr        #
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
#-//---------------------------#
NAME		=	push_swap
NAMEB		=	checker
#-//---------------------------#
SRC_DIR			=	source
SRCB_DIR		=	source_bonus
BUILD_DIR		=	object
BUILD_DIRB		=	object_bonus
#-//---------------------------#
HEADER		=	libft/libft.h



#-Source----------------------------------------------#
SRC			= 	source/push_swap.c					\
				source/sort_little.c				\
				source/sort_big.c					\
				source/sort_big_utils.c				\
				source/push_swap_parsing.c			\
				source/push_swap_stack_utils.c		\
				source/push_swap_parsing_utils.c	\
				source/push_swap_utils.c			\
				source/operations/swap.c			\
				source/operations/push.c			\
				source/operations/rotate.c			\
				source/operations/reverse_rotate.c	\
				source/operations/printer.c
#-Object----------------------------------------------#
OBJ			=	${SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o}
DIRS		=	$(sort $(shell dirname $(OBJ)))



#-Source-Bonus----------------------------------------#
SRCB		=	source_bonus/checker_bonus.c				\
				source_bonus/checker_parsing_bonus.c		\
				source_bonus/checker_stack_utils_bonus.c	\
				source_bonus/checker_parsing_utils_bonus.c	\
				source_bonus/checker_utils_bonus.c			\
				source_bonus/check_operation_bonus.c		\
				source_bonus/operations_bonus/swap_bonus.c	\
				source_bonus/operations_bonus/push_bonus.c	\
				source_bonus/operations_bonus/rotate_bonus.c\
				source_bonus/operations_bonus/reverse_rotate_bonus.c
#-Object-BONUS----------------------------------------#
OBJB		=	${SRCB:$(SRCB_DIR)/%.c=$(BUILD_DIRB)/%.o}
DIRSB		=	$(sort $(shell dirname $(OBJB)))



#-Progress-vars-----------------------------------------------------#
SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
#-Progress-vars-bonus-----------------------------------------------#
SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))



#-Rule-------------------------------------------------------------------------------------------------------------------#
all				:	$(NAME)

$(NAME)			:	$(OBJ)
#					$(RM) bonus
#					$(RM) -r $(BUILD_BIRB)
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
					
$(BUILD_DIR)/%.o	:	$(SRC_DIR)/%.c | $(DIRS)
						$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
						$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says: \t$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
						$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(DIRS)		:
					mkdir -p $@



#-Rule-Bonus------------------------------------------------------------------------------------------------------------#
bonus			: $(NAMEB)

$(NAMEB)			: $(OBJB)
#					$(RM) -r $(BUILD_DIR)
#					touch bonus
					$(PRINTF) "\n"
					sleep 0.2
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(GREEN)make dependencies$(DEFAULT)\n"
					$(PRINTF) "\n"
					make -C libft --silent
					sleep 0.2
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(GREEN)dependencies done$(DEFAULT)\n"
					sleep 0.4
					$(CC) $(CFLAGS) $(OBJB) libft/libft.a -o $(NAMEB)
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t$(CYAN)$(NAMEB)$(GREEN) is up to date!\n$(DEFAULT)"

$(BUILD_DIRB)/%.o	:	$(SRCB_DIR)/%.c | $(DIRSB)
						$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
						$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says: \t$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
						$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(DIRSB)		:
					mkdir -p $@


					
#-Rule-Cleaning---------------------------------------------------------------------------------------------------------#
clean			:
					$(RM) -r $(BUILD_DIR)
					$(RM) -r $(BUILD_DIRB)
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
					$(RM) $(NAMEB)
#					$(RM) bonus
					$(PRINTF) "$(GRAY)$(NAME) says: \t$(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.3
					make do_clean=0 fclean -C libft --silent

re				: fclean all

re_bonus		: fclean bonus

#-Rule-No-Dependencies------------------------------------------------------------------------------------------------------#
clean_nodp		:
					$(RM) -r $(BUILD_DIR)
					$(RM) -r $(BUILD_DIRB)
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t$(YELLOW)____________clean_🧹___________\n\n$(DEFAULT)"
					sleep 0.3

fclean_nodp		:	clean_nodp
					$(RM) $(NAME)
					$(RM) $(NAMEB)
#					$(RM) bonus
					$(PRINTF) "$(GRAY)$(NAME) says: \t$(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.3

re_nodp			:	fclean_nodp all



#-PHONY----------------------------------------------------------------------#
.PHONY			:	all clean clean_nodp fclean fclean_nodp re re_nodp bonus re_bonus
