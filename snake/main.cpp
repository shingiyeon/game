#include <stdio.h>
#include <vector>
#include "Map_cls.h"
#include "Item_cls.h"
#include "Item_list_cls.h"
#include <windows.h>
#include <stdlib.h>

int main(){
    Map_cls map;
    Item_list_cls Item_list;

    map.initialize();
    map.print();
    while(1){
        map.clear();
        while(Item_list.getItemNum()<5){
            Item_list.ItemGenerated(map);
            printf("%d\n", Item_list.getItemNum());
        }
        Item_list.ItemDraw(map);
        map.print();
        
        Sleep(1000/30);
        system("cls");
    }
}