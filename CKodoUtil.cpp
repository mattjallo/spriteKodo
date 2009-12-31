#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "CKodoUtil.h"

IMPLEMENT_CLASS(CKodoUtil, wxObject)

CKodoUtil* CKodoUtil::Instance()
{
    if(this->instance == 0)
        this->instance = new CKodoUtil();
    return this->instance;
}

CKodoUtil::CKodoUtil()
{
    this->instance = this;
}

CKodoUtil::~CKodoUtil()
{

}

bool CKodoUtil::AddImageFile(wxString path)
{
    try
    {
        CSourceImage image();
        if(image.LoadImage(path))
        {
            _sourceImageList.Add(image);
            return true;
        }
        else
        {
            wxLogStderr errLog();
            errLog.DoLogString(_("Warning: ") + path + _(" not included."), wxDateTime::GetTimeNow());
            return false;
        }
    }
    catch(...)
    {
        wxLogStderr errLog();
        errLog.DoLogString(_("Error: While loading ") + path, wxDateTime::GetTimeNow());
        return false;
    }
}


