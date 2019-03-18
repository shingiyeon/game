#include <stdio.h>

class Map_cls {
    private:
        static const int height;
        static const int width;
        char** map;

    public:
        Map_cls();
        ~Map_cls();

        void clear();
        void initialize();
        void draw(int h, int w, int obj);
        void print();
        
        const int get_height();
        const int get_width();
};

const int Map_cls::height = 42;
const int Map_cls::width = 42;

Map_cls::Map_cls(){
    map = new char*[height];
    for(int i=0; i<height; i++){
        map[i] = new char[width];
    }
}

Map_cls::~Map_cls(){
    for(int i=0; i<height; i++){
        delete[] map[i];
    }
    delete[] map;
}

void Map_cls::clear(){
    for(int i=1; i<height-1; i++){
        for(int j=1; j<width-1; j++){
            map[i][j] = ' ';
        }
    }
}

void Map_cls::initialize(){
    clear();
    for(int i=0; i<height; i++){
        map[i][0] = '▦';
        map[i][width-1] = '▦';
    }
    for(int i=0; i<width; i++){
        map[0][i] = '▦';
        map[height-1][i] = '▦';
    }
}

void Map_cls::print(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void Map_cls::draw(int h, int w, int obj){
    map[h][w] = obj;
}

const int Map_cls::get_height(){
    return height;
}

const int Map_cls::get_width(){
    return width;
}

