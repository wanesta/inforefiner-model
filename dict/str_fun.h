//
// Created by root on 10/16/22.
//

#ifndef INFOREFINER_MODEL_STR_FUN_H
#define INFOREFINER_MODEL_STR_FUN_H
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct TargetValue
{
    double pre_ori;
    double pre_wei;

    TargetValue() : pre_ori(0.0), pre_wei(0.0) {}
    TargetValue(const double &val)
    {
        pre_ori = val;
        pre_wei = val;
    }

    TargetValue& operator = (const TargetValue &item)
    {
        if (this != &item)
        {
            pre_ori = item.pre_ori;
            pre_wei = item.pre_wei;
        }
        return *this;
    }
};

struct TargetParam
{
    double bias;
    double coef;
    double power;

    TargetParam() : bias(0.0), coef(0.0), power(0.0)  {}

    void CopyFrom(const TargetParam* p)
    {
        if (NULL != p)
        {
            this->bias  = p->bias;
            this->coef  = p->coef;
            this->power = p->power;
        }
    }
};

template<class T>
inline string to_string(const T& src)
{
    stringstream ss;
    ss << src;
    return ss.str();
}

template<class T>
inline T string_to_value(const string& str, T& value)
{
    stringstream stream(str);
    stream >> value;
    return value;
}

inline bool string_to_bool(const string& str)
{
    return str == "true" || str == "True";
}

inline void split_string(const char* src, const string& sep, vector<string>& split_vec)
{
    const char *separator = sep.c_str();
    split_vec.clear();
    split_vec.reserve(16);
    if(src == NULL || separator == NULL)
        return;

    const char *p = strstr(src, separator);
    if(NULL == p)
    {
        split_vec.push_back(src);
        return;
    }

    if(p == src)
    {
        split_vec.push_back("");
    }
    else
    {
        split_vec.push_back(string(src, p - src));
    }

    size_t len = strlen(separator);
    const char* pre = p + len;
    while(p = strstr(p + len, separator))
    {
        split_vec.push_back(string(pre, p - pre));
        pre = p + len;
    }

    if('\0' == *pre)
    {
        split_vec.push_back("");
    }
    else
    {
        split_vec.push_back(string(pre));
    }
}

inline void split_string(const string& src, const string& sep, vector<string>& split_vec)
{
    string::size_type i = src.find(sep);
    if(string::npos == i)
    {
        split_vec.push_back(src);
        return;
    }

    if(0 == i)
    {
        split_vec.push_back("");
    }
    else
    {
        split_vec.push_back(src.substr(0, i));
    }

    size_t len = sep.size();
    string::size_type pre = i + len;
    while(string::npos != (i = src.find(sep, pre)))
    {
        split_vec.push_back(src.substr(pre, i - pre));
        pre = i + len;
    }

    split_vec.push_back(src.substr(pre));
}

inline string join_string(const string& sep, const vector<string>& str_vec)
{
    string str;
    str.reserve(32*str_vec.size());

    size_t len = str_vec.size();
    if(len > 0)
    {
        str = str_vec[0];
    }

    for(size_t i = 1; i < len; i++)
    {
        str.append(sep);
        str.append(str_vec[i]);
    }

    return str;
}

inline string replace_string(const string& raw_str, const string& src_str, const string& replace_str)
{
    string new_str;
    new_str.reserve(raw_str.size()*2);
    size_t begin = 0;
    size_t len = src_str.size();
    string::size_type i = raw_str.find(src_str);
    if(string::npos == i)
        return raw_str;

    do
    {
        new_str.append(raw_str.substr(begin, i - begin));
        new_str.append(replace_str);
        begin = i + len;
    }
    while(string::npos != (i = raw_str.find(src_str, begin)));

    return new_str.append(raw_str.substr(begin));
}

inline string lstrip(const string& src, const string& sub_str)
{
    size_t len = sub_str.size();
    string::size_type i = 0;

    i = src.find(sub_str, i);
    int count = 0;
    if(i == 0)
    {
        count = 1;
        while((i = src.find(sub_str, i+len)) != string::npos)
        {
            if(i != len*count)
                break;
            count++;
        }
    }
    else
    {
        return src;
    }

    return src.substr(len*count);
}

inline string rstrip(const string& str, const string& sub_str)
{
    int sub_len = sub_str.size();
    int last_index = str.size()-1;
    for(int i = last_index; i >= 0; i -= sub_len)
    {
        int flag = 0;
        for(int j = 0; j < i && j < sub_len; j++)
        {
            if(sub_str[j] != str[i + 1 - sub_len + j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            break;
        }
        else
        {
            last_index = i - sub_len;
        }
    }

    return str.substr(0, last_index+1);
}

inline string strip(const string& src, const string& sub_str)
{
    return lstrip(rstrip(src, sub_str), sub_str);
}

inline int count_of_substr(const string& str, const string& sub_str)
{
    int count = 0;
    size_t len = sub_str.size();
    string::size_type i = 0;
    while((i = str.find(sub_str, i))!= string::npos)
    {
        count++;
        i += len;
    }

    return count;
}

inline int count_of_substr(const char *src, const string& sub_str)
{
    int count = 0;
    size_t len = sub_str.size();
    const char *p = sub_str.c_str();
    const char *index = src;
    while(NULL != (index = strstr(index, p)))
    {
        count++;
        index += len;
    }

    return count;
}

inline string lower_string(const string& src)
{
    string lower_str = src;
    size_t len = src.size();
    for(size_t i = 0; i < len; i++)
    {
        if(src[i] >= 'A' && src[i] <= 'Z')
            lower_str[i] += 32;
    }

    return lower_str;
}

inline string upper_string(const string& src)
{
    string upper_str = src;
    size_t len = src.size();
    for(size_t i = 0; i < len; i++)
    {
        if(src[i] >= 'a' && src[i] <= 'z')
            upper_str[i] -= 32;
    }

    return upper_str;
}

/**
 * 判断字符串是否数字
 * @param str
 * @return
 */
inline bool isDigit(const string &str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}
#endif //INFOREFINER_MODEL_STR_FUN_H
