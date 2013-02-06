APP_PATH = $(PWD)

AR = ../lib/base.a

LIB_PATH = -L /usr/local/lib/ 

LIB = -lprotobuf -lpthread -lrt 

INCLUDE = -I ./ -I ../include/ -I /usr/local/include/ 

CXXFLAGS =-g -Wall -fPIC $(INCLUDE)

CC = g++ -shared

EXE = libRulePlugin.so libDataApiPlugin.so
Target:$(EXE)

libRulePlugin.so:rule_plugin.o behavior_data.pb.o result_info.pb.o
	$(CC) $(CXXFLAGS) -o libRulePlugin.so rule_plugin.o behavior_data.pb.o result_info.pb.o $(AR) $(LIB_PATH) $(LIB)

libDataApiPlugin.so:data_api_plugin.o behavior_data.pb.o result_info.pb.o
	$(CC) $(CXXFLAGS) -o libDataApiPlugin.so data_api_plugin.o behavior_data.pb.o result_info.pb.o $(AR) $(LIB_PATH) $(LIB)

clean:
	rm -rf $(EXE) *.o 
