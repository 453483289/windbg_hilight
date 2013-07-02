// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\SciLexer.lib")
#else
#pragma comment(lib, "..\\Release\\SciLexer.lib")
#endif

#include <assert.h>
#include <string.h>

#include "ILexer.h"
#include "Scintilla.h"
#include "SciLexer.h"

#include "LexAccessor.h"
#include "Accessor.h"
#include "LexerModule.h"

#include "..\SciLexer\src\Catalogue.h"

#define TEST_STR "text:1000 mov eax, ecx; mov ecx, edx;"
class Doc : public IDocument
{
public:
    virtual int SCI_METHOD Version() const
    {
        return 0;
    }
    virtual void SCI_METHOD SetErrorStatus(int status)
    {

    }
    virtual int SCI_METHOD Length() const
    {
        return strlen(TEST_STR);
    }
    // ������ȡ�ı�
    virtual void SCI_METHOD GetCharRange(char *buffer, int position, int lengthRetrieve) const
    {
        strcpy(buffer, 
            TEST_STR
            );
    }
    virtual char SCI_METHOD StyleAt(int position) const
    {
        return 'a';
    }
    // ��ǰ�е���ʼλ��
    virtual int SCI_METHOD LineFromPosition(int position) const
    {
        return 0;
    }
    // ��һ�е�λ��
    virtual int SCI_METHOD LineStart(int line) const 
    {
        return line + 10;
    }
    virtual int SCI_METHOD GetLevel(int line) const
    {
        return 0;

    }
    virtual int SCI_METHOD SetLevel(int line, int level)
    {
        return 0;

    }
    virtual int SCI_METHOD GetLineState(int line) const
    {
        return 0;
    }
    virtual int SCI_METHOD SetLineState(int line, int state)
    {
        return 0;

    }
    // ��ʼ��Ⱦ
    virtual void SCI_METHOD StartStyling(int position, char mask)
    {

    }
    virtual bool SCI_METHOD SetStyleFor(int length, char style) 
    {
        return true;
    }
    // ����������ϣ�stylesÿ�ֽڶ�Ӧһ�����֣�ֵ����Ӧ����ʾ����ɫ
    virtual bool SCI_METHOD SetStyles(int length, const char *styles) 
    {
        return true;
    }
    virtual void SCI_METHOD DecorationSetCurrentIndicator(int indicator)
    {
    }
    virtual void SCI_METHOD DecorationFillRange(int position, int value, int fillLength) 
    {

    }
    virtual void SCI_METHOD ChangeLexerState(int start, int end)
    {

    }
    virtual int SCI_METHOD CodePage() const 
    {
        // ExtTextOutW
        return 0; // LexAccessor���캯��
    }

    // �ֽ��Ƿ��ǿ�ͷ�Ķ��ֽ���,gbk
    virtual bool SCI_METHOD IsDBCSLeadByte(char ch) const 
    {
        return true;
    }
    virtual const char * SCI_METHOD BufferPointer() 
    {
        return NULL;
    }
    virtual int SCI_METHOD GetLineIndentation(int line)
    {
        return 0;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
    const LexerModule *lex = Catalogue::Find("asm");
    if (lex)
    {
        ILexer* p = lex->Create();
        class Doc c;
        p->Lex(0, 20, 0, &c);

    }
	return 0;
}

