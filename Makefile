SRC_IN = enc_data.c amessage.pb-c.c
SRC_OUT = dec_data.c amessage.pb-c.c

TGT1 = enc_exe
TGT2 = dec_exe

#ifndef INCLUDE
INCLUDE = -I.
#endif

#ifndef LIBS
LIBS = -lprotobuf-c
#endif

#ifndef CFLAG
CFLAG = -Wall -g
#endif

CC = gcc

all: $(TGT1) $(TGT2)

$(TGT1): $(SRC_IN)
	$(CC) $(CFLAG) -o $(TGT1) $(SRC_IN) $(LIBS) $(INCLUDE)

$(TGT2): $(SRC_OUT)
	$(CC) $(CFLAG) -o $(TGT2) $(SRC_OUT) $(LIBS) $(INCLUDE)

clean:
	$(RM) $(TGT1) $(TGT2)
