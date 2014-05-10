#pragma once

#include <windows.h>
#include <string>
#include <map>

#define theConfig (CConfig::get_instance())

class CConfig
{
public:
    COLORREF get_color(unsigned int index);
    const char* get_keywords(int index);
    bool load();
    void save();

	static CConfig& get_instance();
protected:
	CConfig();
	~CConfig();
private:
	typedef std::map<unsigned int, COLORREF> MAP_COLOR;
	typedef std::map<int, std::string> MAP_KEYWORDS;

	MAP_COLOR m_color;
	MAP_KEYWORDS m_keywords;
};

