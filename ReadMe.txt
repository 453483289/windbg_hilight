feature:
windbg����������ı����������֧��x86��x64
A windbg plugin to hiligth text in Disassembly and Command windows. Support x86 and x64.

����download:
http://pan.baidu.com/s/1gd3i8i3

ʹ�÷�����
��hs.dll����32λwindbg�İ�װĿ¼��hs64.dll����64λ(x64)windbg�İ�װĿ¼��
����windbg����������
.load hs
64λ��
.load hs64

how to work:
please put the dll file in to windbg installed directory.
.load hs.dll
or x64:
.load hs64.dll

note:
��������Զ���syntax��ɫ��ֻ��Ҫ�Թ���ԱȨ������windbg������windbg_hilight�������������windbg�İ�װĿ¼�����һ��windbg_hilight.ini���ο�http://www.w3schools.com/tags/ref_colorpicker.asp ��ȡ����Ҫ����ɫ����ת��ʮ��ֵ��д��ini�С�
If you want to customize the syntax color, please run windbg in administrator privileage and .load windbg_hilight.dll, then you will get windbg_hilight.ini in windbg installed diretory, change the value in color section, please refer http://www.w3schools.com/tags/ref_colorpicker.asp to get the hex color value and write the corresponding decimal value.

changelog:
2014��5��10�գ�
add patch by goldenegg: ȥ����boost������������dllж��(2013-4-30)
�µ������ļ�����Ϊwindbg_hilight.ini�������ǰ���ù�asm.ini�븴�����õ�windbg_hilight.ini������Ҫֱ�Ӹ���asm.iniΪwindbg_hilight.ini����Ϊkeywords.registers�����и���
�޸��ڴ�й¶�����x64�Ĵ�������
fixed issues Memory Leak, add register syntax for x64
2013��4��26��
���ӵ�ַ��opcode��jumpcallָ�����ɫ����
����������û��������ɫ����(ֻ�Ǽ򵥵ض�>������ֽ��м�ɫ)
2013��4��25��
�׸��汾��������ʱֻ��Disassembly���ڵĸ���

greets:
��лlinx2008�����������������û��x64�汾��http://hi.baidu.com/linx2008/item/0bee3aedc6d49e275b2d6441

by lynnux
CopyRight (C) 2013-2014
started from 2013��4��25��
