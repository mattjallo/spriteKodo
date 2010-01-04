#ifndef _PACKING_H_
#define _PACKING_H_

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "CSourceImage.h"

class RP_Node
{
    protected:
    RP_Node* left_child;
    RP_Node* right_child;
    CSourceImage* image;
    
    public:
    int left;
    int top;
    int width;
    int height;
    
    RP_Node();
    RP_Node* Insert(CSourceImage* img);
    bool Unwind();
};


#endif