.PHONY: build

CC		:= x86_64-w64-mingw32-gcc-win32
CFLAGS	:= -static -Wall -Wextra
TARGET	:= crdreader.exe
SRCS	:= src/crdreader.c

build:
	$(CC) -o $(TARGET) $(SRCS)
