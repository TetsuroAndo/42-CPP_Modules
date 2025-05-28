# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 06:58:27 by teando            #+#    #+#              #
#    Updated: 2025/05/29 00:03:42 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= phonebook
CXX		:= c++
CXXFLAG	:= -Wall -Wextra -Werror -std=c++98
SRC		:= Contact.cpp PhoneBook.cpp main.cpp
OBJDIR	:= obj
OBJ		:= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
