CFLAGS=-g -Wall -c -fPIC
LFLAGS=-lsodium

main: main.c libattoid.so
	$(CC) -I. -L. -Wl,-rpath=. -o $@ main.c -lattoid $(LFLAGS)

tests: test/tests_main.c libattoid.so
	$(CC) -I. -L. -Wl,-rpath=. -o $@ test/tests_main.c -lattoid $(LFLAGS)

libattoid.so: attoid.o
	$(CC) -shared -o $@ $^

attoid.o: attoid.c
	$(CC) $(CFLAGS) $^ $(LFLAGS)

.PHONY=clean
clean:
	rm attoid.o libattoid.so main test/tests_main.c tests
