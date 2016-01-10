GTEST_DIR = googleTest/gtest
GMOCK_DIR = googleTest/gmock
CPPFLAGS += -I$(GTEST_DIR)/include -I$(GMOCK_DIR)/include
LD_LIBRARIES = -L $(GTEST_DIR)/lib -lgtest -L $(GMOCK_DIR)/lib -lgmock

CXXFLAGS += -g -Wall -Wextra

CPPFLAGS += -Iinclude

SOURCE:= $(wildcard src/*.cpp)
SOURCE_OBJ:= $(SOURCE:src/%.cpp=obj/%.o)

TESTS:= $(wildcard test/*.cpp)
TESTS_OBJ:= $(TESTS:test/%.cpp=obj/%.o)

OBJ:= $(SOURCE_OBJ) $(TESTS_OBJ)
TARGET:= obj/unitTest.exe

all: $(TARGET)
	$(TARGET)

clean:
	@rm -f $(OBJ) $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(LD_LIBRARIES) -o $(TARGET)

$(SOURCE_OBJ):obj/%.o:src/%.cpp
	$(CXX) -g $(CPPFLAGS) -c $< -o $@

$(TESTS_OBJ):obj/%.o:test/%.cpp
	$(CXX) -g $(CPPFLAGS) -c $< -o $@