all: server producer consumer

server: server.c
	gcc -o server server.c # μεταγλωττίζει το αρχείο server.c σε εκτελέσιμο "server"

producer: producer.c
	gcc -o producer producer.c # μεταγλωττίζει το αρχείο producer.c σε εκτελέσιμο "producer"

consumer: consumer.c
	gcc -o consumer consumer.c # μεταγλωττίζει το αρχείο consumer.c σε εκτελέσιμο "consumer"

clean:
	rm -f server producer consumer # διαγράφει τα εκτελέσιμα αρχεία
