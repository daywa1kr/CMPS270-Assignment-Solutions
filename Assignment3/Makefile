seq:
	gcc -o a src/utils.c src/sequential.c
race:
	gcc -g -pthread -o a src/utils.c src/count_race.c
mutex:
	gcc -g -pthread -o a src/utils.c src/count_mutex.c
priv:
	gcc -g -pthread -o a src/utils.c src/count_private.c