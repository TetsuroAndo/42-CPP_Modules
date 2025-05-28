#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 21:42:18 by teando            #+#    #+#              #
#    Updated: 2025/05/27 07:26:31 by teando           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		:= megaphone
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRCS		:= megaphone.cpp
OBJDIR		:= obj
OBJS		:= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
