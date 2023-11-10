CC = g++
FLAGS = -std=c++11

all: palindrome.out clean

PalindromeI.o: PalindromeI.cpp
	${CC} ${FLAGS} -c PalindromeI.cpp
# ^ This line should start with a tab, not spaces

PalindromeR.o: PalindromeR.cpp
	${CC} ${FLAGS} -c PalindromeR.cpp
# ^ This line should start with a tab, not spaces

palindrome.out: PalindromeI.o PalindromeR.o test_palindrome.cpp
	${CC} ${FLAGS} test_palindrome.cpp *.o -o palindrome.out
# ^ This line should start with a tab, not spaces

clean:
	rm -f *.o
	rm -f *~
	rm -f \#*
# ^ This line should start with a tab, not spaces
