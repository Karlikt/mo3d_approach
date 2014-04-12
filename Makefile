CC=g++
CFLAGS=-g -Wall -Wextra
OBJS=Main.o Waypoint.o WaypointIntegrator.o ApproachProcedure.o

mo3d: $(OBJS)
		$(CC) $(LFLAGS) $(CFLAGS) $(OBJS) -o mo3d

$(OBJS): %.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

