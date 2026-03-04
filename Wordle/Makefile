all: servidor cliente

servidor: server_main.o server.o
	g++ -o servidor server_main.o server.o
server_main.o: server/main.cpp server/server.h
	g++ -c server/main.cpp -o server_main.o
server.o: server/server.cpp server/server.h
	g++ -c server/server.cpp
cliente: client_main.o client.o
	g++ -o cliente client_main.o client.o
client_main.o: client/main.cpp client/client.h
	g++ -c client/main.cpp -o client_main.o
client.o: client/client.cpp client/client.h
	g++ -c client/client.cpp
clean:
	rm -f *.o servidor cliente