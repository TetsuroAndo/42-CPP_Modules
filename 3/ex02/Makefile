# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 06:51:47 by teando            #+#    #+#              #
#    Updated: 2025/06/02 20:49:53 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
CXX		:= c++
CXXFLAG	:= -Wall -Wextra -Werror -std=c++98 -g
RM		:= rm -rf
SRC		:= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJDIR	:= obj
OBJ		:= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

run: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all run clean fclean re
