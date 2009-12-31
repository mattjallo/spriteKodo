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
    bool AddImageFile(const wxString& path);
    void Generate();
    bool SaveBitmap(const wxString& path);
    bool SaveCSS(const wxString& path);
    wxBitmap GetBitmapPreview();
    wxString GetCSSPreview();
    SourceImageList* GetSourceImageListReference();
    void SortImagesByName();
    
    //property accessors
    void SetBackgroundColor(const wxColour& color);
    wxColour GetBackgroundColor();
    void SetTransparentBackground(bool transparent);
    bool GetTransparentBackground();
    void SetMaxWidth(int maxWidth);
    int GetMaxWidth();
    void SetCssPrefix(const wxString& prefix);
    wxString GetCssPrefix();
    void SetOutputType(const wxString& outputType);
    wxString GetOutputType();
    static void WriteToStdErr(const wxString& errText);
    
    protected:
    
    static CKodoUtil* instance;
    
    SourceImageList _sourceImageList;
    wxBitmap* _bitmap;
    wxString _css;
    wxString _cssPrefix;
    wxColour* _backgroundColor;
    bool _transparentBackground;
    int _maxWidth;
    wxString _outputType;

    void GenerateBitmap();
    void GenerateCSS();
};

#endif