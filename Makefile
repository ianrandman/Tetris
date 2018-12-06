CXXFLAGS=-Wall -O3 -g
OBJECTS=game.o board.o line.o tetromino_rotator.o $(TETROMINODIR)/color.o $(TETROMINODIR)/coordinate.o \
$(TETROMINODIR)/i_tetromino.o $(TETROMINODIR)/j_tetromino.o $(TETROMINODIR)/l_tetromino.o $(TETROMINODIR)/o_tetromino.o \
$(TETROMINODIR)/s_tetromino.o $(TETROMINODIR)/t_tetromino.o $(TETROMINODIR)/tetromino.o $(TETROMINODIR)/z_tetromino.o
BINARIES=game

TETROMINODIR=tetrominos

RGB_LIB_DISTRIBUTION=matrix
RGB_INCDIR=$(RGB_LIB_DISTRIBUTION)/include
RGB_LIBDIR=$(RGB_LIB_DISTRIBUTION)/lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a
LDFLAGS+=-L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread -L/usr/local/lib -lwiringPi

all : game

game : $(OBJECTS) $(RGB_LIBRARY)
	$(CXX) -I$(TETROMINODIR) -I$(RGB_INCDIR) -I/usr/local/include $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(RGB_LIBRARY):
	$(MAKE) -C $(RGB_LIBDIR)

%.o : %.cpp
	$(CXX) -I$(TETROMINODIR) -I$(RGB_INCDIR) $(CXXFLAGS) -c -o $@ $<

%.o : %.cc
	$(CXX) -I$(RGB_INCDIR) $(CXXFLAGS) -c -o $@ $<