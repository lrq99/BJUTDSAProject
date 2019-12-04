#ifndef SCENICCENTERPOINT_H
#define SCENICCENTERPOINT_H

class ScenicCenterPoint{
public:
    int x, y;
    int type;
    ScenicCetnerPoint(int x, int y, int type){
        this->x = x;
        this->y = y;
        this->type = type;
    }
};

#endif // SCENICCENTERPOINT_H
