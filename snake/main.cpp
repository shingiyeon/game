#include <stdio.h>
#include <vector>
#include "Map_cls.h"
#include "Item_cls.h"
#include "Item_list_cls.h"
#include "snake_cls.h"
#include <windows.h>
#include <stdlib.h>

int main(){
    Map_cls map;
    Item_list_cls Item_list;
    snake_cls snake(5,5);

    map.initialize();
    map.print();
    while(Item_list.getItemNum()<5){
        Item_list.ItemGenerated(map);
    }
    while(1){
        map.clear();

        
        snake.get_input();
        snake.move(map);
        Item_list.ItemDraw(map);
        snake.draw(map);
        map.draw(21, 41, Item_list.getItemNum()+'0');
        map.print();
        
        if(snake.check_food(Item_list)){
            Item_list.ItemGenerated(map);
        }
        Sleep(1000/30);
        system("cls");
    }
}