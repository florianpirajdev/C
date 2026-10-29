run: app
	./app

app: main.c
	gcc main.c -o app

.PHONY: run