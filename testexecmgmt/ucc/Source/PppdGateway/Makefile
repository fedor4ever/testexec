##########################################################################
#
# Makefile for ...
#
##########################################################################

##########################################################################
#
# Definitions
#
##########################################################################
TARGET=		../../bin/pppdgateway
INCLUDES=
OBJECTS=	pppdgateway.o socket_helper.o
LIBS= 		-lpthread

##########################################################################
#
# Rules
#
##########################################################################
$(TARGET):	$(OBJECTS)
	gcc -gstabs -Wall -o $(TARGET) $(OBJECTS) $(LIBS)

%.o:	%.c
	gcc -gstabs -Wall $(INCLUDES) -c $< -o $@

%.o:	%.cpp
	g++ -gstabs -Wall $(INCLUDES) -c $< -o $@

clean:
	rm -r -f $(TARGET) *.o *~
