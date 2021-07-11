clean:
	@rm -r code

all: code

code: main.cpp main.hpp students.cpp display_students.cpp student_data.cpp sort_students.cpp admin.cpp database.txt
	@g++ -o code students.cpp display_students.cpp student_data.cpp sort_students.cpp admin.cpp main.cpp

# all:
# 	@g++ -c -fPIC -o mainobj.o mainobj.cpp
# 	@g++ -o code main.cpp mainobj.o
