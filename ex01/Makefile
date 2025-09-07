NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Contact.cpp PhoneBook.cpp utils.cpp
HDR = Contact.hpp PhoneBook.hpp macros.hpp

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