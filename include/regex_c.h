#ifndef REGEX_C_H
#define REGEX_C_H

void replaceAll(char* str, const char* pattern, const char* replacement);

class StringReplacer
{
private:
    const char* m_pattern;
    const char* m_replacement;
    
public:
    StringReplacer(const char* pattern, const char* replacement)
        : m_pattern(pattern), m_replacement(replacement) {}

    void replace(char* str);
};

#endif /* REGEX_C_H_INCLUDED */