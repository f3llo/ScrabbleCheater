

bin/output: src/main.c
	mkdir -p bin
	gcc -o bin/output src/main.c -lcurl


clean:
	rm -rf /bin
