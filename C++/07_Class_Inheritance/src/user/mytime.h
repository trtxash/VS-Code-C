/**
 * @file	mytime.h
 * @brief   时间类模板实现，支持常见的时间操作
 * @brief   注：只是用来学习类等等东西，实际应用中不建议使用
 * @author 	TRTX-gamer
 * @version 0.0.2
 * @date 	2025-03-14 6:56
 */
#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

namespace mytime
{
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
            addSeconds(0);
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

        /*---------------------------时间运算---------------------------*/

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

        /*---------------------------运算符功能---------------------------*/

        // 只能用在加时间
        DateTime operator+(const DateTime &dt) const
        {
            // 这个 const 保证：
            // 1. 不可修改对象状态
            // 2. 可作用于 const 对象
            // 3. 重载区分
            DateTime temp = *this;
            temp.addSeconds(dt.second_);
            temp.addMinutes(dt.minute_);
            temp.addHours(dt.hour_);
            return temp;
        }

        DateTime &operator+=(const DateTime &dt)
        {
            addSeconds(dt.second_);
            addMinutes(dt.minute_);
            addHours(dt.hour_);
            return *this;
        }

        DateTime operator*(float f) const
        {
            DateTime temp = *this;
            temp.addHours((unsigned int)((f - 1) * temp.hour_));
            temp.addMinutes((unsigned int)((f - 1) * temp.minute_));
            temp.addSeconds((unsigned int)((f - 1) * temp.second_));
            return temp;
        }
        friend DateTime operator*(float f, const DateTime &t); // 友元函数声明，不是成员函数，故不能用成员运算符，但与成员函数访问权限相同

        DateTime &operator*=(float f)
        {
            addHours((unsigned int)((f - 1) * hour_));
            addMinutes((unsigned int)((f - 1) * minute_));
            addSeconds((unsigned int)((f - 1) * second_));
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const DateTime &dt);

        DateTime operator>>(std::ostream &os) const
        {
            unsigned int monthtemp = month_;
            unsigned int daytemp = day_;
            unsigned int hourtemp = hour_;
            unsigned int mintemp = minute_;
            unsigned int secondtemp = second_;

            os << year_ << "-" << monthtemp << "-" << daytemp << " " << hourtemp << ":" << mintemp << ":" << secondtemp;
            return *this;
        }

        operator int() const // 重载 int() 运算符，实现对象转换数字，与类的初始化对应（数字转换为对象）
        {
            return second_;
        }
    };

    // 类外定义 (必须添加)
    constexpr unsigned char DateTime::daysInMonth[12]; // C++ 11 允许类内初始化 constexpr static 成员，但数组类型的静态成员仍需要类外定义
    // inline constexpr unsigned char DateTime::daysInMonth[12];// C++17 后更推荐的方式

    inline std::ostream &operator<<(std::ostream &os, const DateTime &dt) // 返回ostream对象引用，实现流输出
    {
        unsigned int monthtemp = dt.month_;
        unsigned int daytemp = dt.day_;
        unsigned int hourtemp = dt.hour_;
        unsigned int mintemp = dt.minute_;
        unsigned int secondtemp = dt.second_;

        os << dt.year_ << "-" << monthtemp << "-" << daytemp << " " << hourtemp << ":" << mintemp << ":" << secondtemp;
        return os;
    }

    inline DateTime operator*(float f, const DateTime &t)
    {
        DateTime temp = t;
        temp.addHours((unsigned int)((f - 1) * temp.hour_));
        temp.addMinutes((unsigned int)((f - 1) * temp.minute_));
        temp.addSeconds((unsigned int)((f - 1) * temp.second_));
        return temp;
    }
}

#endif // MYTIME_H