CC ?= g++

my-diff : main.cpp
	$(CC) main.cpp -o my-diff

.PHONY : clean

clean :
	rm my-diff diff*