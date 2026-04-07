class Robot {
    int width;
    int height;
    int position;
    int x;
    int y;
    int flag;
    string direction;

    public:
        Robot(int width, int height, int position=0, int x=0, int y=0, string direction="East", int flag=0) {
            this->width = width;
            this->height = height;
            this->position = position;
            this->x = x;
            this->y=y;
            this->direction=direction;
            this->flag=flag;
        }
        
        void step(int num) {
            int loop_len = (width + height) * 2 - 4;
            position = (num + position) % loop_len;
            flag = 1;
        }
        
        vector<int> getPos() {
            vector<int> result(2, 0);

            if (0<= position && position <= width-1) {
                result[0] = position;
                result[1] = 0;
                // direction = "East";
            } else if (width <= position && position < width + height - 1) {
                result[0] = width - 1;
                result[1] = position - (width-1);
                // direction = "North";

            } else if (width+height-1 <= position && position < 2*width+height-2) {
                result[0] = (width-1) - (position-(width+height-2));
                result[1] = height-1;
                // direction = "West";
            } else if (2*width+height-2 <= position && position < (width+height)*2) {
                result[0] = 0;
                result[1] = (height-1)-(position-(2*width+height-3));
                // direction = "South";
            }
            return result;
        }
        
        string getDir() {
            if (0<= position && position <= width-1) {
                direction = "East";
            } else if (width <= position && position < width + height - 1) {
                direction = "North";

            } else if (width+height-1 <= position && position < 2*width+height-2) {
                direction = "West";
            } else if (2*width+height-2 <= position && position < (width+height)*2) {
                direction = "South";
            }

            if (flag && position==0)
                return "South";
            return direction;
        }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */