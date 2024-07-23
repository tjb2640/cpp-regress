CXX = g++
# INC := /usr/local/include/eigen3
# I'm using the brew install of eigen3:
INC := /opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3
CXXFLAGS = -std=c++11 -Wall -I$(INC)
TARGET = regress
SRCS = regression.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^
	rm -f $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS) $(TARGET)
