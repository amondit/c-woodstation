CC=gcc
INCLUDES=-I.
LIBS=-L. -L/usr/lib -lwiringPi

all: woodstation

woodstation: woodstation.o
        $(CC) -o $@ $^ $(LIBS)

clean:
        rm -rf *.o woodstation

%.o:    %.c
        $(CC) $(INCLUDES) -o $@ -c $^

