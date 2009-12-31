#ifndef _CKODOUTIL_H_
#define _CKODOUTIL_H_

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "CSourceImage.h"

class CKodoUtil : wxObject
{    
    DECLARE_CLASS( CKodoUtil )
    
    public:
    
    CKodoUtil();
    ~CKodoUtil();
    static CKodoUtil* Instance();
    bool AddImageFile(wxString path);
    void Generate();    
    
    protected:
    
    static CKodoUtil* instance = 0;
    
    SourceImageList _sourceImageList;
    wxBitmap* _bitmap;
    wxString _css;

    void GenerateBitmap();
    void GenerateCSS();
    
    private:
};

#endif