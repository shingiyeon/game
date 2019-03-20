class snake_cls{
    private:
        enum {UP, DOWN, LEFT, RIGHT} dir;
        static std::vector<pos> snake;
        int length;
        int speed;


    public:
        snake_cls(int x, int y);
        ~snake_cls();

        bool check_food(Item_list_cls& Item_list);

        void get_input();
        void move(Map_cls& Map);
        void check_Dead(Map_cls& Map);
        void draw(Map_cls& Map);

};

std::vector<pos> snake_cls::snake = std::vector<pos>(0);

snake_cls::snake_cls(int x, int y){
    speed = 1;
    length = 1;
    pos POS; POS.x = x; POS.y = y;
    snake.push_back(POS);
    dir = RIGHT;
}

snake_cls::~snake_cls(){
}

bool snake_cls::check_food(Item_list_cls& Item_list){
    if(Item_list.checkedItem(snake[0].x, snake[0].y)){
        snake.push_back(snake[length-1]);
        length++;
        return 1;
    }
    else{
        return 0;
    }
}

void snake_cls::get_input(){
    if(GetAsyncKeyState(VK_UP) && dir != DOWN) {
        dir = UP;
    }
    if(GetAsyncKeyState(VK_DOWN) && dir != UP) {
        dir = DOWN;
    }
    if(GetAsyncKeyState(VK_LEFT) && dir != RIGHT) {
        dir = LEFT;
    }
    if(GetAsyncKeyState(VK_RIGHT) && dir != LEFT) {
        dir = RIGHT;
    }
}

void snake_cls::move(Map_cls& Map){
    pos dxdy = {0, 0};
    switch(dir){
        case UP:
            dxdy.x = -speed;
            break;
        case DOWN:
            dxdy.x = speed;
            break;
        case LEFT:
            dxdy.y = -speed;
            break;
        case RIGHT:
            dxdy.y = speed;
            break;
        default:
            break;
    }
    for(int c=length-1; c>0; c--){
        snake[c] = snake[c-1];
    }
    snake[0].x += dxdy.x;
    snake[0].y += dxdy.y;
    
    check_Dead(Map);

}

void snake_cls::check_Dead(Map_cls& Map){
    if(snake[0].x <= 0 || snake[0].x >= 21 || snake[0].y <= 0 || snake[0].y >= 41)
        throw "DEAD!";
    
    for(int i=1; i<length; i++){
        if( snake[0].x == snake[i].x && snake[0].y == snake[i].y){
            throw "DEAD!";
        }
    }
}

void snake_cls::draw(Map_cls& Map){
    for(int i=0; i<length; i++){
        if(!i){
            Map.draw(snake[0].x, snake[0].y, '@');
        }
        else{
            Map.draw(snake[i].x, snake[i].y, '&');
        }
    }
}