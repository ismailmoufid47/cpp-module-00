NAME = test_accounts

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp Account.cpp
HDR = Account.hpp

OBJ = $(SRC:%.cpp=obj/%.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

obj/%.o: %.cpp $(HDR)
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re