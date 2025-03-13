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
    // static constexpr用于类的静态成员，这样每个类的实例共享同一份数据，且数据在编译时初始化，无需在类外定义。

    // 闰年判断
    bool isLeapYear() const
    {
        return (year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0);
    }

    // 自动调整日期（处理跨月、跨年）
    void normalizeDate()
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
                    throw std::invalid_argument("year overflow");
                }
                else
                    year_++;
            }
        }
    }

    // 自动调整时间（处理进位）
    void normalizeTime()
    {
        // while (second_ >= 60) // 处理秒
        // {
        //     second_ -= 60;
        //     minute_++;
        //     while (minute_ >= 60) // 处理分钟
        //     {
        //         minute_ -= 60;
        //         hour_++;
        //         while (hour_ >= 24) // 处理小时
        //         {
        //             hour_ -= 24;
        //             day_++;
        //             normalizeDate();
        //         }
        //     }
        // }
        if (second_ >= 60)
        {
            minute_ += second_ / 60;
            second_ %= 60;
        }

        if (minute_ >= 60)
        {
            hour_ += minute_ / 60;
            minute_ %= 60;
        }

        if (hour_ >= 24)
        {
            day_ += hour_ / 24;
            hour_ %= 24;
            normalizeDate();
        }
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

        normalizeDate();
        normalizeTime();
    }

    // 时间加法
    void addSeconds(unsigned int s)
    {
        while (s >= 60) // 处理秒
        {
            s -= 60;
            minute_++;
            normalizeTime();
        }
        second_ += s;
        normalizeTime();
    }

    void addMinutes(unsigned int m)
    {
        while (m >= 60)
        {
            m -= 60;
            hour_++;
            normalizeTime();
        }
        minute_ += m;
        normalizeTime();
    }

    void addHours(unsigned int h)
    {
        while (h >= 24)
        {
            h -= 24;
            day_++;
            normalizeTime();
        }
        hour_ += h;
        normalizeTime();
    }

    void addDays(unsigned int d)
    {
        while (d)
        {
            day_++;
            d--;
            normalizeDate();
        }
    }

    // 获取日期时间信息
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
        normalizeTime();
    }

    // 设置日期（会自动规范化）
    void setDate(unsigned int y, unsigned char m, unsigned char d)
    {
        year_ = y;
        month_ = m;
        day_ = d;
        normalizeDate();
    }

    // 比较运算符等扩展功能...
};

// 类外定义 (必须添加)
constexpr unsigned char DateTime::daysInMonth[12]; // C++ 11 允许类内初始化 constexpr static 成员，但数组类型的静态成员仍需要类外定义

// inline constexpr unsigned char DateTime::daysInMonth[12];// C++17 后更推荐的方式

#endif // MYTIME_H