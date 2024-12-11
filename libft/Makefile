# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 09:56:45 by dleclerc          #+#    #+#              #
#    Updated: 2024/12/11 13:26:29 by dleclerc         ###   ########.fr        #
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
NAME		=	libft.a
#-//---------------------------#
SRC_DIR			=	source
BUILD_DIR		=	object
#-//---------------------------#
HEADER		=	source/gnl_dir/get_next_line.h	\
				source/printf_dir/ft_printf.h	\
				source/printf_fd_dir/ft_printffd.h
#-//---------------------------#
do_clean 	:= 	1



#-Source----------------------------------------------#
SRC			=	source/ft_strlen.c						\
				source/ft_atoi.c						\
				source/ft_atol.c						\
				source/ft_strlcpy.c						\
				source/ft_strlcat.c						\
				source/ft_strnstr.c						\
				source/ft_memset.c						\
				source/ft_memcpy.c						\
				source/ft_memmove.c						\
				source/ft_bzero.c						\
				source/ft_strdup.c						\
				source/ft_isalpha.c						\
				source/ft_isdigit.c						\
				source/ft_isalnum.c						\
				source/ft_isascii.c						\
				source/ft_isprint.c						\
				source/ft_tolower.c						\
				source/ft_toupper.c						\
				source/ft_strchr.c						\
				source/ft_strrchr.c						\
				source/ft_strncmp.c						\
				source/ft_memchr.c						\
				source/ft_memcmp.c						\
				source/ft_calloc.c						\
				source/ft_itoa.c						\
				source/ft_substr.c						\
				source/ft_strjoin.c						\
				source/ft_putchar_fd.c					\
				source/ft_putstr_fd.c					\
				source/ft_putendl_fd.c					\
				source/ft_putnbr_fd.c					\
				source/ft_split.c						\
				source/ft_strtrim.c						\
				source/ft_strmapi.c						\
				source/ft_striteri.c					\
				source/ft_lstnew.c						\
				source/ft_lstadd_front.c				\
				source/ft_lstsize.c						\
				source/ft_lstlast.c						\
				source/ft_lstadd_back.c					\
				source/ft_lstdelone.c					\
				source/ft_lstclear.c					\
				source/ft_lstiter.c						\
				source/ft_lstmap.c						\
				source/ft_printf.c						\
				source/ft_printf_fd.c					\
				source/get_next_line.c					\
				source/printf_dir/ft_putchar_pf.c		\
				source/printf_dir/ft_putstr_pf.c		\
				source/printf_dir/ft_putnbrs_pf.c		\
				source/printf_dir/ft_puthex_pf.c		\
				source/printf_dir/ft_putadress_pf.c		\
				source/printf_fd_dir/ft_putchar_pffd.c	\
				source/printf_fd_dir/ft_putstr_pffd.c	\
				source/printf_fd_dir/ft_putnbrs_pffd.c	\
				source/printf_fd_dir/ft_puthex_pffd.c	\
				source/printf_fd_dir/ft_putadress_pffd.c\
				source/gnl_dir/gnl_fix_for_pipex.c		\
				source/gnl_dir/get_next_line_utils.c
#-Object----------------------------------------------#
OBJ			=	${SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o}
DIRS		=	$(sort $(shell dirname $(OBJ)))



#-Progress-vars-----------------------------------------------------#
SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))



#-Rule-------------------------------------------------------------------------------------------------------------------#
all				:	$(NAME)

$(NAME)			:	$(OBJ)
					$(PRINTF) "\n"
					ar -rc $(NAME) $(OBJ)
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t\t$(CYAN)$(NAME)$(GREEN) is up to date!\n$(DEFAULT)"

$(BUILD_DIR)/%.o	:	$(SRC_DIR)/%.c | $(DIRS)
						$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
						$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says: \t\t$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
						$(CC) $(CFLAGS) -c $< -o $@

$(DIRS)		:
					mkdir -p $@

				
					
#-Rule-Cleaning---------------------------------------------------------------------------------------------------------#
clean			:
					$(RM) -r $(BUILD_DIR)
					$(PRINTF) "$(GRAY)$(NAME) says: \t\t$(YELLOW)_*#*__$(CYAN)Cleaning up object$(YELLOW)__*#*_"
					sleep 0.6
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)_*#*_🧹_*#*_🧹_*#*_*#*_*#*_*#*_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)_________*#*_🧹_*#*_🧹_*#*_*#*_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)_________________*#*_🧹_*#*_🧹_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)____________clean_🧹___________\n\n$(DEFAULT)"
					sleep 0.3

fclean			:	
					if [ $(do_clean) -eq 1 ]; then  make clean --silent; fi
					$(RM) $(NAME)
					$(RM) bonus
					$(PRINTF) "$(GRAY)$(NAME) says: \t\t$(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.3

re				:	fclean all



#-PHONY----------------------------------------------------------------------#
.PHONY			:	all clean fclean re