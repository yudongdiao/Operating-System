CXX=g++
CXXFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem $(GTEST_DIR)/include -std=c++11

GTEST_DIR = gtest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

MKDIR_P = mkdir -p
OBJ_DIR = obj

all: llist llist_tests submission

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

submission:
	zip -r llist-submission.zip src

obj/%.o: src/%.cpp ${OBJ_DIR}
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

obj/llist_tests.o: test/llist_tests.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

obj/gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc -o $@

obj/gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc -o $@

obj/gtest.a: obj/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

obj/gtest_main.a: obj/gtest-all.o obj/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

llist: obj/llist.o obj/main.o
	$(CXX) -o $@ $^

llist_tests : obj/llist.o obj/llist_tests.o obj/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *~ obj/*.o obj/*.a *.zip
	rm -f llist llist_tests
