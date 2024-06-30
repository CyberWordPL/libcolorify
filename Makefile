override MAKEFLAGS += -rR

CFLAGS = \
	-Wall \
	-Wextra

CPPFLAGS = \
	-I .


build:
	gcc $(CFLAGS) -fpic $(CPPFLAGS) -c libcolorify.c -o libcolorify.o
	gcc -shared -o libcolorify.so libcolorify.o

test:
	gcc $(CFLAGS) -I/usr/include/libcolorify -c test.c -o test.o ## TEST FOR LIBCOLORIFY
	gcc -lcolorify -o test test.o

install:
	mkdir -p /usr/include/libcolorify
	cp libcolorify.h /usr/include/libcolorify/libcolorify.h
	cp libcolorify.so /usr/lib/libcolorify.so
	chmod 0755 /usr/lib/libcolorify.so
	ldconfig

uninstall:
	rm -r /usr/include/libcolorify
	rm /usr/lib/libcolorify.so
	ldconfig
