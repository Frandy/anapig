CC = g++
CFLAGS = -std=c++0x -I ../common
LFLAGS = -std=c++0x 


		  
COMMON_HEADERS = error.h \
		  		 stringenc.h

COMMON_SOURCES = ../common/stringenc.cpp


HEADERS = token.h \
		  lexer.h 
		  		  
SOURCES = main.cpp \
		  
COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
		  
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = test

all:$(TARGET)

$(TARGET):$(OBJECTS) $(COMMON_OBJECTS)
	$(CC)  $(LFALGS) $^ -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	rm $(OBJECTS) $(COMMON_OBJECTS)
	rm $(TARGET)