APP_PATH = $(PWD)

AR = ../lib/base.a 

LIB_PATH = -L /usr/local/lib/ 

LIB = -lprotobuf -lpthread -lrt -ldl

INCLUDE = -I ./ -I ../include/ -I /usr/local/include/ 

CXXFLAGS =-g -Wall -fPIC $(INCLUDE)
#CXXFLAGS = -Wall -fPIC $(INCLUDE)

EXE := TestPlugin
Target:$(EXE)

TestPlugin:test_plugin.o plugin_factory.o plugin_holder.o plugin_conf.pb.o behavior_data.pb.o result_info.pb.o
	g++ $(CXXFLAGS) -o TestPlugin test_plugin.o plugin_factory.o plugin_holder.o plugin_conf.pb.o behavior_data.pb.o result_info.pb.o $(AR) $(LIB_PATH) $(LIB)

clean:
	rm -rf $(EXE) *.o 
