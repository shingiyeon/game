#include "Map_cls.h"
#include <windows.h>
#include <vector>

typedef struct pos{
    int x;
    int y;
};

class Item_cls{
    private:
        pos POS;
        static int item_num;
        static std::vector<pos> item_list;

    public:
        Item_cls();
        ~Item_cls();

        bool checkedPreviousItem();
        void ItemGenerated(Map_cls& Map);



};

int Item_cls::item_num = 0;
std::vector<pos> Item_cls::item_list = std::vector<pos>(0);

bool Item_cls::checkedPreviousItem(){
    for(int i=0; i<item_list.size(); i++){
        if(item_list[i].x == POS.x && item_list[i].y == POS.y){
            return true;
        }
    }
    return false;
}

void Item_cls::ItemGenerated(Map_cls& map){
    do{
        // x : 1 ~ height - 1
        POS.x = (rand() % (map.get_height() - 2)) + 1;
        // y : 1 ~ width - 1
        POS.y = (rand() % (map.get_width() - 2)) + 1;
    }while(checkedPreviousItem());
}