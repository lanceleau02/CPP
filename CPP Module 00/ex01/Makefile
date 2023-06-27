# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 15:04:30 by laprieur          #+#    #+#              #
#    Updated: 2023/06/27 18:09:03 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	phonebook

#-------------------------------#
#          INGREDIENTS          #
#-------------------------------#

SRC				:=	phonebook.cpp

SRC_OBJS		:=	$(SRC:%.cpp=.build/%.o)
DEPS			:=	$(SRC_OBJS:%.o=%.d)

CC				:=	c++
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98
CPPFLAGS		:=	-MP -MMD
LDFLAGS			:=

#----------------------------#
#          UTENSILS          #
#----------------------------#

MAKEFLAGS		+= --silent --no-print-directory

#---------------------------#
#          RECIPES          #
#---------------------------#

all: $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) $(LDFLAGS) -o $(NAME)
	$(info CREATED $(NAME))

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------#
#          SPEC          #
#------------------------#

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
