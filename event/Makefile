COM_SRC = com/protocol/common.pb-c.c com/protocol/fleet_event.pb-c.c com/protocol/fleet_message.pb-c.c
SRC_IN = enc_data.c $(COM_SRC)
SRC_OUT = dec_data.c $(COM_SRC)
#SRC_IN1 = enc_data.cpp $(COM_SRC)

TGT1 = enc_exe
TGT2 = dec_exe

#ifndef INCLUDE
INCLUDE = -I.
#endif

#ifndef LIBS
LIBS = -lprotobuf-c
#endif

#ifndef CFLAG
CFLAG = -Wall -g -Werror
#endif

CC = gcc
CXX = g++

all: $(TGT1) $(TGT2) $(TGT3)

$(TGT1): $(SRC_IN)
	$(CC) $(CFLAG) -o $(TGT1) $(SRC_IN) $(LIBS) $(INCLUDE)

$(TGT2): $(SRC_OUT)
	$(CC) $(CFLAG) -o $(TGT2) $(SRC_OUT) $(LIBS) $(INCLUDE)

$(TGT3): $(SRC_IN1)
	$(CXX) $(CFLAG) -o $(TGT3) $(SRC_IN1) $(LIBS) $(INCLUDE)

clean:
	$(RM) $(TGT1) $(TGT2) $(TGT3)
