# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 09:56:45 by dleclerc          #+#    #+#              #
#    Updated: 2024/12/09 10:59:48 by dleclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Silent-------------#
ifndef VERBOSE
.SILENT:
endif

# Color
DEFAULT		=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE 		=	\033[0;97m

# Variables
PRINTF		=	printf
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f
CC			=	cc
NAME		=	libft.a
#--------------------#
OBJ_DIR			=	obj
OBJ_PF_DIR		=	obfpf
OBJ_PFFD_DIR	=	obfpffd
OBJ_GNL_DIR		=	objgnl
#--------------------#
SRC_DIR 	=	source
SRC_PF_DIR 	=	printf_utils
SRC_PFFD_DIR =	printf_fd_utils
SRC_GNL_DIR	=	gnl_utils
#--------------------#
HEADER		=	gnl_utils/get_next_line.h	\
				printf_utils/ft_printf.h	\
				printf_fd_utils/ft_printffd.h
#--------------------#
do_clean 	:= 	1

# Source
SRC			=	ft_strlen.c			\
				ft_atoi.c			\
				ft_atol.c			\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strnstr.c		\
				ft_memset.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_bzero.c			\
				ft_strdup.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_calloc.c			\
				ft_itoa.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_split.c			\
				ft_strtrim.c		\
				ft_strmapi.c		\
				ft_striteri.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_printf.c			\
				ft_printf_fd.c	\
				get_next_line.c

SRC_PF		=	ft_putchar_pf.c	\
				ft_putstr_pf.c	\
				ft_putnbrs_pf.c	\
				ft_puthex_pf.c	\
				ft_putadress_pf.c

SRC_PFFD	=	ft_putchar_pffd.c	\
				ft_putstr_pffd.c	\
				ft_putnbrs_pffd.c	\
				ft_puthex_pffd.c	\
				ft_putadress_pffd.c

SRC_GNL		=	gnl_fix_for_pipex.c	\
				get_next_line_utils.c
# Object
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_PF		=	$(addprefix $(OBJ_PF_DIR)/, $(SRC_PF:.c=.o))
OBJ_PFFD	=	$(addprefix $(OBJ_PFFD_DIR)/, $(SRC_PFFD:.c=.o))
OBJ_GNL		=	$(addprefix $(OBJ_GNL_DIR)/, $(SRC_GNL:.c=.o))

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all					:	$(NAME)

$(NAME)				:	$(OBJ) $(OBJ_PF) $(OBJ_PFFD) $(OBJ_GNL)
					$(PRINTF) "\n\n"
					ar -rc $(NAME) $(OBJ) $(OBJ_PFFD) $(OBJ_PF) $(OBJ_GNL)
					$(PRINTF) "$(GRAY)libft says : $(CYAN)$(NAME)$(GREEN) is up to date!\n$(DEFAULT)"
			
$(OBJ_DIR)/%.o		:	$(SRC_DIR)/%.c | $(OBJ_DIR)
					$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
					$(PRINTF) "\r%100s\r$(GRAY)libft says :$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
					$(CC) $(CFLAGS)  -c $< -o $@

$(OBJ_PF_DIR)/%.o	:	$(SRC_PF_DIR)/%.c | $(OBJ_PF_DIR)
					$(CC) $(CFLAGS)  -c $< -o $@

$(OBJ_PFFD_DIR)/%.o	:	$(SRC_PFFD_DIR)/%.c | $(OBJ_PFFD_DIR)
					$(CC) $(CFLAGS)  -c $< -o $@

$(OBJ_GNL_DIR)/%.o	:	$(SRC_GNL_DIR)/%.c | $(OBJ_GNL_DIR)
					$(CC) $(CFLAGS)  -c $< -o $@

$(OBJ_DIR)			:
					mkdir -p $(OBJ_DIR)

$(OBJ_PF_DIR)		:
					mkdir -p $(OBJ_PF_DIR)

$(OBJ_PFFD_DIR)		:
					mkdir -p $(OBJ_PFFD_DIR)

$(OBJ_GNL_DIR)		:
					mkdir -p $(OBJ_GNL_DIR)
					
clean				:
					$(RM) -r $(OBJ_DIR)
					$(RM) -r $(OBJ_PF_DIR)
					$(RM) -r $(OBJ_PFFD_DIR)
					$(RM) -r $(OBJ_GNL_DIR)			
					$(PRINTF) "$(GRAY)libft says : $(YELLOW)_*#*__$(CYAN)Cleaning up object$(YELLOW)__*#*_"
					sleep 0.8
					$(PRINTF) "\r\r$(GRAY)libft says : $(YELLOW)_*#*_🧹_*#*_🧹_*#*_*#*_*#*_*#*_"
					sleep 0.4
					$(PRINTF) "\r\r$(GRAY)libft says : $(YELLOW)_________*#*_🧹_*#*_🧹_*#*_*#*_"
					sleep 0.4
					$(PRINTF) "\r\r$(GRAY)libft says : $(YELLOW)_________________*#*_🧹_*#*_🧹_"
					sleep 0.4
					$(PRINTF) "\r\r$(GRAY)libft says : $(YELLOW)____________clean_🧹___________\n\n$(DEFAULT)"
					sleep 0.4
					
fclean				:
					if [ $(do_clean) -eq 1 ]; then  make clean --silent; fi
					$(RM) $(NAME)
					$(PRINTF) "$(GRAY)libft says : $(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.4

re					:	fclean all

.PHONY				:	all clean fclean re