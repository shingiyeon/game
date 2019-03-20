
struct pos{
    int x;
    int y;
};

class Item_cls{
    private:
        pos POS;

    public:
        Item_cls(int x, int y);
        ~Item_cls();

        int getX();
        int getY();
};

Item_cls::Item_cls(int x, int y){
    POS.x = x;
    POS.y = y;
}

Item_cls::~Item_cls(){
}

int Item_cls::getX(){
    return POS.x;
}

int Item_cls::getY(){
    return POS.y;
}