CC=clang
CFLAGS=-g -Wall -Wextra -Werror

EXEC=client-introduction client-tutoriel client-interactif client-projetX planB client-crypteMove client-bayOfPigs client-crypteSeq client-oneMillion client-northwoods client-lostCause
all: $(EXEC)

client-interactif: client-interactif.o client.o

client-tutoriel: client-tutoriel.o client.o

client-introduction: client-introduction.o client.o

client.o: client.c client.h

client-projetX : client-projetX.o client.o

planB : planB.o client.o

client-crypteMove: client-crypteMove.o client.o

client-bayOfPigs: client-bayOfPigs.o client.o

client-crypteSeq : client-crypteSeq.o client.o

client-oneMillion : client-oneMillion.o client.o

client-northwoods : client-northwoods.o client.o

client-lostCause : client-lostCause.o client.o
clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
