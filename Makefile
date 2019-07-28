ifeq ($(OS), Windows_NT)
	CXX = g++
else
	CXX = i686-w64-mingw32-g++
endif

OBJS += Common/Border.o Common/Button.o Common/CheckBox.o Common/CheckList.o Common/ComboBox.o Common/DotBorder.o Common/DoubleBorder.o Common/LineBorder.o Common/Control.o Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Common/Label.o Common/MassageBox.o Common/NumericBox.o Common/Panel.o Common/RadioBox.o Common/RadioList.o Common/TextBox.o Common/WaveBorder.o  

all: $(OBJS)
	$(CXX) $(OBJS) -o main.exe -static

clean:
	rm -f $(OBJS)
	rm -f *.exe