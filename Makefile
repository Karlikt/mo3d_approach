CC=g++
CFLAGS=-g -Wall -Wextra
OBJS=Main.o Waypoint.o ApproachList.o

mo3d: $(OBJS)
		$(CC) $(LFLAGS) $(CFLAGS) $(OBJS) -o mo3d

$(OBJS): %.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

