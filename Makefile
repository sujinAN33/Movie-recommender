CXX = g++ #C++ 컴파일러
CXXFLAGS = -std=c++17 -Wall -Wextra #컴파일 옵션
TARGET = movie_recommender #실행 파일
SRCS = main.cpp Movie.cpp User.cpp Rating.cpp #소스 파일
OBJS = $(SRCS:.cpp=.o) #목적 파일

Movie.o: Movie.cpp Movie.h
User.o: User.cpp User.h
Rating.o: Rating.cpp Rating.h
main.o: main.cpp Movie.h User.h Rating.h

all: $(TARGET) #기본 타겟 - make 명령어를 실행했을 때 호출되는 타겟

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ #목적 파일을 링크하여 실행 파일 생성
	# $@는 타겟 이름, $^는 모든 의존 파일을 나타냄

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ #.cpp 파일을 .o 파일로 컴파일

clean:
	rm -f $(OBJS) $(TARGET) #목적 파일과 실행 파일 삭제


run: $(TARGET)
	./$(TARGET) #실행 파일 실행

.PHONY: all clean run 