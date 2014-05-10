#pragma once

#include <windows.h>
#include "ILexer.h"
#include <string>

typedef BOOL (WINAPI* EXTTEXTOUTW)(HDC hdc,          // handle to DC
                                   int X,            // x-coordinate of reference point
                                   int Y,            // y-coordinate of reference point
                                   UINT fuOptions,   // text-output options
                                   CONST RECT* lprc, // optional dimensions  
                                   LPCWSTR lpString, // string
                                   UINT cbCount,     // number of characters in string
                                   CONST INT* lpDx   // array of spacing values
                                   );

// ����ֻ�ǲο��࣬���ಢ��֧��unicode(utf-16)������utf8��gbk֮��Ҳ��֧�ֺܺã���û���Թ�
class CText : public IDocument
{
public:
    struct hook_data
    {
        HDC hdc; 
        int X;
        int Y;
        UINT fuOptions;
        CONST RECT* lprc;
        LPCWSTR lpString;
        UINT cbCount;
        CONST INT* lpDx;
        EXTTEXTOUTW ExtTextOutW_Org;
    };

    CText(const hook_data* hd);
    virtual int SCI_METHOD Version() const;
    virtual void SCI_METHOD SetErrorStatus(int status);
    virtual int SCI_METHOD Length() const;
    // ������ȡ�ı�
    virtual void SCI_METHOD GetCharRange(char *buffer, int position, int lengthRetrieve) const;
    virtual char SCI_METHOD StyleAt(int position) const;
    // ��ǰ�е���ʼλ��
    virtual int SCI_METHOD LineFromPosition(int position) const;
    // ��һ�е�λ��
    virtual int SCI_METHOD LineStart(int line) const;
    virtual int SCI_METHOD GetLevel(int line) const;
    virtual int SCI_METHOD SetLevel(int line, int level);
    virtual int SCI_METHOD GetLineState(int line) const;
    virtual int SCI_METHOD SetLineState(int line, int state);
    // ��ʼ��Ⱦ
    virtual void SCI_METHOD StartStyling(int position, char mask);
    virtual bool SCI_METHOD SetStyleFor(int length, char style);
    // ����������ϣ�stylesÿ�ֽڶ�Ӧһ�����֣�ֵ����Ӧ����ʾ����ɫ
    virtual bool SCI_METHOD SetStyles(int length, const char *styles);
    virtual void SCI_METHOD DecorationSetCurrentIndicator(int indicator);
    virtual void SCI_METHOD DecorationFillRange(int position, int value, int fillLength);
    virtual void SCI_METHOD ChangeLexerState(int start, int end);
    virtual int SCI_METHOD CodePage() const;
    // �ֽ��Ƿ��ǿ�ͷ�Ķ��ֽ���,gbk
    virtual bool SCI_METHOD IsDBCSLeadByte(char ch) const;
    virtual const char * SCI_METHOD BufferPointer();
    virtual int SCI_METHOD GetLineIndentation(int line);
private:
    std::string str_;
    //LPCWSTR m_lpString;
    //UINT m_cbCount;
    hook_data m_hd;
};