#include <stdlib.h>
#include <windows.h>

class Item_list_cls{
    private:
        static int item_num;
        static std::vector<Item_cls*> item_list;
    
    public:
        Item_list_cls();
        ~Item_list_cls();
        bool checkedPreviousItem(pos POS);
        int getItemNum();
        void ItemGenerated(Map_cls& Map);
        void ItemDraw(Map_cls& Map);
};

int Item_list_cls::item_num = 0;
std::vector<Item_cls*> Item_list_cls::item_list = std::vector<Item_cls*>(0);

Item_list_cls::Item_list_cls(){
}

Item_list_cls::~Item_list_cls(){
}

bool Item_list_cls::checkedPreviousItem(pos POS){
    for(int i=0; i<item_list.size(); i++){
        if(item_list[i]->getX() == POS.x && item_list[i]->getY() == POS.y){
            return true;
        }
    }
    return false;
}

void Item_list_cls::ItemGenerated(Map_cls& map){
    pos POS;
    do{
        // x : 1 ~ height - 1
        POS.x = (rand() % (map.get_height() - 2)) + 1;
        // y : 1 ~ width - 1
        POS.y = (rand() % (map.get_width() - 2)) + 1;
    }while(checkedPreviousItem(POS));
    Item_cls *item = new Item_cls(POS.x, POS.y);
    item_num++;
    item_list.push_back(item);
}

void Item_list_cls::ItemDraw(Map_cls& map){
    for(int i=0; i<getItemNum(); i++){
        map.draw(item_list[i]->getX(), item_list[i]->getY(), '#');
    }
}

int Item_list_cls::getItemNum(){
    return item_num;
}