SOURCE = Source\ Files/*.cpp
HEADERS = HeaderFiles/*.h

all: lab_beta
	./lab_beta

lab_beta:
	g++ $(SOURCE) -o lab_beta

clang:
	clang-format -i $(SOURCE) $(HEADERS)

clean:
	rm lab_beta