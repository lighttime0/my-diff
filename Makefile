CC?= gcc

my-diff : main.c
	$(CC) main.c -o my-diff

.PHONY : clean

clean :
	rm my-diff diff_*