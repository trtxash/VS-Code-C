/**
 * @file	mytime.h
 * @brief   时间类模板实现，支持常见的时间操作
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025-03-10-16:58
 */
#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class DateTime
{
private:
    unsigned int year_;
    unsigned char month_;
    unsigned char day_;
    unsigned char hour_;
    unsigned char minute_;
    unsigned char second_;

    // 月份天数表（非闰年）
    static constexpr unsigned char daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /*---------------------------自动调整日期---------------------------*/

    // 自动调整时间 （进位到day）
    inline void normalizeTime()
    {
        unsigned int minute_temp, hour_temp;

        minute_temp = minute_ + second_ / 60;
        second_ %= 60; // 计算秒
        hour_temp = hour_ + minute_temp / 60;
        minute_ = minute_temp % 60; // 计算分
        hour_ = hour_temp % 24;     // 计算时

        addDays(hour_temp / 24); // 进位到day
    }

    // 闰年判断
    inline bool isLeapYear() const
    {
        return (year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0); // 闰年是4的倍数但不是100的倍数，或者是400的倍数，2月有29天
    }

    // 自动调整日期（处理跨年）
    inline void normalizeDate()
    {
        // 处理闰年二月
        unsigned char febDays = isLeapYear() ? 29 : 28;

        while (day_ > daysInMonth[(month_ - 1) % 12] + (month_ == 2 ? febDays - 28 : 0))
        {
            day_ -= daysInMonth[(month_ - 1) % 12] + (month_ == 2 ? febDays - 28 : 0);

            month_++; // 分析了下，单次流动日流向月时，月占用永远小于日，不需要判断溢出

            while (month_ > 12)
            {
                month_ -= 12;
                if (year_ == 0XFFFFFFFF)
                {
                    year_ = 0;
                    std::cout << "year overflow" << std::endl;
                }
                else
                    year_++;
            }
        }
    }

    // 自动调整日期（处理时间，处理跨月、跨年）
    inline void normalize()
    {
        normalizeTime(); // 处理时间
        normalizeDate(); // 处理日期
    }

public:
    DateTime(unsigned int y = 2000, unsigned char m = 1, unsigned char d = 1,
             unsigned char h = 0, unsigned char min = 0, unsigned char s = 0)
        : year_(y), month_(m), day_(d), hour_(h), minute_(min), second_(s)
    {
        if (month_ == 0 || month_ > 12)
            std::cout << "Invalid month" << std::endl;
        if (day_ == 0 || day_ > 31)
            std::cout << "Invalid day" << std::endl;
        if (hour_ >= 24)
            std::cout << "Invalid hour" << std::endl;
        if (minute_ >= 60)
            std::cout << "Invalid minute" << std::endl;
        if (second_ >= 60)
            std::cout << "Invalid second" << std::endl;

        normalize();
    }

    /*---------------------------时间加法---------------------------*/

    void addSeconds(unsigned int s)
    {
        unsigned long temp = second_ + s;
        second_ = temp % 60;            // 取余
        temp /= 60;                     // 多少进位
        addMinutes((unsigned int)temp); // 进位
    }

    void addMinutes(unsigned int m)
    {
        unsigned long temp = minute_ + m;
        minute_ = temp % 60;          // 取余
        temp /= 60;                   // 多少进位
        addHours((unsigned int)temp); // 进位
    }

    void addHours(unsigned int h)
    {
        unsigned long temp = hour_ + h;
        hour_ = temp % 24;           // 取余
        temp /= 24;                  // 多少进位
        addDays((unsigned int)temp); // 进位
    }

    void addDays(unsigned int d)
    {
        normalizeDate(); // 为防止溢出,这里先处理本身day_溢出,此时day_小于32
        day_ += d / 2;   // 处理d的一半
        normalizeDate();
        day_ += d - (d / 2); // 处理d的另一半
        normalizeDate();
    }

    /*---------------------------获取或设置日期时间信息--------------------*/

    unsigned int year() const { return year_; }
    unsigned char month() const { return month_; }
    unsigned char day() const { return day_; }
    unsigned char hour() const { return hour_; }
    unsigned char minute() const { return minute_; }
    unsigned char second() const { return second_; }

    // 输出日期时间信息
    void show() const
    {
        unsigned int monthtemp = month_;
        unsigned int daytemp = day_;
        unsigned int hourtemp = hour_;
        unsigned int mintemp = minute_;
        unsigned int secondtemp = second_;

        std::cout << year_ << "-" << monthtemp << "-" << daytemp << " " << hourtemp << ":" << mintemp << ":" << secondtemp << std::endl;
    }

    // 设置时间（会自动规范化）
    void setTime(unsigned char h, unsigned char min, unsigned char s)
    {
        hour_ = h;
        minute_ = min;
        second_ = s;
        normalize();
    }

    // 设置日期（会自动规范化）
    void setDate(unsigned int y, unsigned char m, unsigned char d)
    {
        year_ = y;
        month_ = m;
        day_ = d;
        normalize();
    }

    /*---------------------------比较运算符等扩展功能---------------------------*/

    // 运算符重载
    // 只能用在加时间
    DateTime operator+(const DateTime &dt)
    {
        DateTime temp = *this;
        temp.addSeconds(dt.second_);
        temp.addMinutes(dt.minute_);
        temp.addHours(dt.hour_);
        return temp;
    }
};

// 类外定义 (必须添加)
constexpr unsigned char DateTime::daysInMonth[12]; // C++ 11 允许类内初始化 constexpr static 成员，但数组类型的静态成员仍需要类外定义

// inline constexpr unsigned char DateTime::daysInMonth[12];// C++17 后更推荐的方式

#endif // MYTIME_H