# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: idonado <idonado@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:23:24 by idonado       #+#    #+#                  #
#    Updated: 2021/08/24 14:49:42 by idonado       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\

GNL_SRC = get_next_line_utils.c get_next_line.c

GNL_MAP = get_next_line/

SRC_MAP = srcs/

GNL_SRCS = $(addprefix $(GNL_MAP), $(GNL_SRC))

SRCS = $(addprefix $(SRC_MAP), $(SRC))

OBJ := $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

HDR = -I hdrs

FLAGS = -Wall -Werror -Wextra -fPIC

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rcs $@ $^

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: libft all clean fclean re