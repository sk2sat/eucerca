TARGET	= eucerca
OBJS	= main.o

%.o: %.c
	$(CC) -c -o $@ $<

%.o: %.cc
	$(CXX) -c -o $@ $<

# command

default:
	make $(TARGET)

run:
	make
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f *.o

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^
