#ifndef _CSOURCEIMAGE_H_
#define _CSOURCEIMAGE_H_

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class CSourceImage : wxObject
{    
    DECLARE_CLASS( CSourceImage )
    
    public:
        
        bool LoadImage(const wxString& path);
        CSourceImage();
        ~CSourceImage();
        wxString GetName();
        int GetWidth();
        int GetHeight();
        int GetLeft();
        int GetTop();
        void SetLeft(int left);
        void SetTop(int top);
        wxImage* GetImage();
        
        static int Compare(CSourceImage **first, CSourceImage **second);
        static int CompareArea(CSourceImage **first, CSourceImage **second);
        
    protected:
        wxString name;
        wxImage* sourceImage;
        int width;
        int height;
        int left;
        int top;

    private:
    
};

WX_DECLARE_OBJARRAY(CSourceImage, SourceImageList);

#endif