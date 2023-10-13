# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 13:59:24 by laprieur          #+#    #+#              #
#    Updated: 2023/10/13 10:49:01 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	ex02

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

SRC				:=	main.cpp					\
					Bureaucrat.cpp				\
					AForm.cpp					\
					PresidentialPardonForm.cpp	\
					RobotomyRequestForm.cpp		\
					ShrubberyCreationForm.cpp	\
					
SRC_OBJS		:=	$(SRC:%.cpp=.build/%.o)
DEPS			:=	$(SRC_OBJS:%.o=%.d)

CXX				:=	c++
CXXFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -g
CPPFLAGS		:=	-MP -MMD
LDFLAGS			:=

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header trees $(NAME)

$(NAME): $(SRC_OBJS)
	$(CXX) $(CXXFLAGS) $(SRC_OBJS) $(LDFLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $(CPPFLAGS) $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf trees.txt
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo "   ____ ____  ____    __  __           _       _         ___  ____	"
	@echo "  / ___|  _ \|  _ \  |  \/  | ___   __| |_   _| | ___   / _ \| ___|	"
	@echo " | |   | |_) | |_) | | |\/| |/ _ \ / _  | | | | |/ _ \ | | | |___ \	"
	@echo " | |___|  __/|  __/  | |  | | (_) | (_| | |_| | |  __/ | |_| |___) |	"
	@echo "  \____|_|   |_|     |_|  |_|\___/ \____|\____|_|\___|  \___/|____/	"
	@echo "			     by laprieur											"
	@echo
	@printf "%b" "$(CYAN)CXX:      $(YELLOW)$(CXX)\n"
	@printf "%b" "$(CYAN)CXXFlags: $(YELLOW)$(CXXFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                    TREES                                     #
# **************************************************************************** #

trees:
	@echo "       _-_              _-_			" >	trees.txt
	@echo "    /~~   ~~\        /~~   ~~\		" >> trees.txt
	@echo " /~~         ~~\  /~~         ~~\	" >> trees.txt
	@echo "{               }{               }	" >> trees.txt
	@echo " \  _-     -_  /  \  _-     -_  /	" >> trees.txt
	@echo "   ~  \   /  ~      ~  \   /  ~		" >> trees.txt
	@echo "       | |              | |			" >> trees.txt
	@echo "       | |              | |			" >> trees.txt
	@echo "      /   \            /   \			" >> trees.txt

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR: