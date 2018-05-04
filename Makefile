my-diff : main.cpp
	g++ main.cpp -o my-diff

.PHONY : clean

clean :
	rm my-diff diff*