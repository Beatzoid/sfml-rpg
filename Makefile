SFML_PATH = /opt/homebrew/Cellar/sfml/2.5.1_2

cppFileNames := $(shell find ./src -type f -name "*.cpp")
GPP_OPTIONS = -Wall -Wextra -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations

all: compile

compile:	
	mkdir -p bin
	g++ $(cppFileNames) -I$(SFML_PATH)/include -o bin/app -L$(SFML_PATH)/lib $(GPP_OPTIONS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	cp ./src/config/window.ini ./bin/window.ini