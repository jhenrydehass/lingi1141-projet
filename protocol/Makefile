CFLAGS=-Wall -Werror -Wshadow -Wextra -g

all: receiver

receiver: receiver.o read_loop.o real_address.o wait_for_sender.o create_socket.o
	gcc $(CFLAGS) -o receiver receiver.o read_loop.o real_address.o wait_for_sender.o create_socket.o

receiver.o: src/receiver.c src/read_loop.h src/real_address.h src/wait_for_sender.h src/create_socket.h
	gcc $(CFLAGS) -c src/receiver.c

read_loop.o: src/read_loop.c src/read_loop.h
	gcc $(CFLAGS) -c src/read_loop.c

real_address.o: src/real_address.c src/real_address.h
	gcc $(CFLAGS) -c src/real_address.c

wait_for_sender.o: src/wait_for_sender.c src/wait_for_sender.h
	gcc $(CFLAGS) -c src/wait_for_sender.c

create_socket.o: src/create_socket.c src/create_socket.h
	gcc $(CFLAGS) -c src/create_socket.c 

clean:
	rm -rf receiver sender *.o *.c~ *.h~
