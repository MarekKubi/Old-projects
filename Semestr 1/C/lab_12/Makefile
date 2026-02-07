SHELL = /bin/sh

# kompilator C
CC = gcc
# konsolidator (linker, loader) C
LD = gcc
# archiwizator (program do tworzenia bibliotek)
AR = ar -ru

# opcje kompilacji
# wersja do debugowania
CFL = -g -DMY_DEBUG
# wersja zoptymalizowana 
# OPT = -O3
#opcje linkowania
LDFL = 
# katalogi z bibliotekami i dolaczane biblioteki
# biblioteki
#LIB = -L/home/METAL/markubi2/lab_12/lib -llista_powiazana -lm
# katalogi z plikami naglowkowymi i  pliki naglowkowe 
#INC = -I/home/METAL/markubi2/lab_12/include

zabawa: lista_powiazana.o main.o
	$(LD) $(LDFL) -o zabawa  lista_powiazana.o main.o 

lista_powiazana: lista_powiazana.c 
	$(CC) $(CFL) -c lista_powiazana.c 

main: main.c
	$(CC) $(CFL) -c main.c

clean:
	rm -f *.o 

