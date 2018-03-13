#include "Util.h"

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>

namespace util {

uint16_t str_to_uint16_be(const std::string &s) {
    if (s.length() > 2 || s.length() <= 0) {
        throw std::runtime_error("invalid length");
    }

    uint64_t n = str_to_uint64_be(s);
    return static_cast<uint16_t>(n);
}

std::string uint16_to_str_be(uint16_t n) {
    std::string s;
    s.push_back(static_cast<uint8_t>(n >> 8));
    s.push_back(static_cast<uint8_t>(n & 0xff));

    return s;
}

uint32_t str_to_uint32_be(const std::string &s) {
    if (s.length() > 4 || s.length() <= 0) {
        throw std::runtime_error("invalid length");
    }

    uint64_t n = str_to_uint64_be(s);
    return static_cast<uint32_t>(n);
}

std::string uint32_to_str_be(uint32_t n) {
    std::string s;

    s.push_back(static_cast<uint8_t>(n >> 24));
    s.push_back(static_cast<uint8_t>(n >> 16));
    s.push_back(static_cast<uint8_t>(n >> 8));
    s.push_back(static_cast<uint8_t>(n & 0xff));

    return s;
}

std::string uint64_to_str_be(uint64_t n) {
    std::string s;
    s.push_back(static_cast<uint8_t>(n >> 56));
    s.push_back(static_cast<uint8_t>(n >> 48));
    s.push_back(static_cast<uint8_t>(n >> 40));
    s.push_back(static_cast<uint8_t>(n >> 32));
    s.push_back(static_cast<uint8_t>(n >> 24));
    s.push_back(static_cast<uint8_t>(n >> 16));
    s.push_back(static_cast<uint8_t>(n >> 8));
    s.push_back(static_cast<uint8_t>(n & 0xff));

    return s;
}

uint64_t str_to_uint64_be(const std::string &s) {
    if (s.length() > 8 || s.length() <= 0) {
        throw std::runtime_error("invalid length");
    }

    uint64_t n = 0;

    for (size_t i = 0; i < s.length(); i++) {
        n += static_cast<uint64_t>(static_cast<uint8_t>(s[i])) << (s.length() - i - 1) * 8;
    }

    return n;
}

std::string uint64_to_hex(uint64_t n) {
    std::ostringstream ss;
    ss << std::hex << n;

    return ss.str();
}

std::string uint8_to_hex(uint8_t n) {
    std::ostringstream ss;
    ss << std::hex << n;

    return ss.str();
}


std::string uint16_to_hex(uint16_t n) {
    std::ostringstream ss;
    ss << std::hex << n;

    return ss.str();
}




std::string rotate_left(const std::string &bytes, size_t n) {
    if (n >= bytes.size()) {
        throw std::invalid_argument("invalid argument");
    }

    auto result = bytes.substr(n);
    result.append(bytes.substr(0, n));

    return result;
}


std::string bytes_to_hex(const std::string &bytes) {
    std::ostringstream ss;
    ss << std::hex;

    for (const char &c : bytes) {
        ss << std::setfill('0') << std::setw(2) << +(static_cast<uint8_t>(c));
    }

    return ss.str();
}

std::string hex_to_bytes(const std::string &hex) {
    if (hex.length() % 2 != 0) {
        throw std::runtime_error("hex string does not have even length");
    }

    std::basic_string<uint8_t> tmp;

    for (size_t i = 0; i < hex.length(); i += 2) {
        uint16_t byte;
        auto temp = hex.substr(i, 2);
        std::istringstream(temp) >> std::hex >> byte;
        tmp.push_back(static_cast<uint8_t>(byte));
    }

    std::string result(begin(tmp), end(tmp));

    return result;
}

std::string get_local_time(const std::string& fmt) {
    std::stringstream ss;

    std::time_t t = std::time(nullptr);
    ss << std::put_time(std::localtime(&t), fmt.c_str());

    return ss.str();
}

std::string generate_uuid() {
    std::ifstream infile("/proc/sys/kernel/random/uuid");
    std::string uuid;

    infile >> uuid;
    return uuid;
}

std::string random_bytes(size_t bytes) {
    std::ifstream is("/dev/urandom", std::ios::binary);
    std::string str(bytes, '\0');

    if(is.read(&str[0], bytes)) {
        return str;
    } else {
        throw std::runtime_error("not enough random bytes from /dev/urandom");
    }
}

timepoint get_local_time(int hour, int min, int sec) {
    if (hour < 0 || hour > 23) {
        throw std::invalid_argument("invalid hour");
    }

    if (min < 0 || min > 59) {
        throw std::invalid_argument("invalid minute");
    }

    if (sec < 0 || sec > 59) {
        throw std::invalid_argument("invalid second");
    }

    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);

    auto tm = std::localtime(&now_time_t);

    tm->tm_hour = hour;
    tm->tm_min = min;
    tm->tm_sec = sec;

    auto t = std::mktime(tm);
    return std::chrono::system_clock::from_time_t(t);
}

timepoint plus_one_day(timepoint tp) {
    auto t = tp + std::chrono::hours(24);
    return t;
}

timepoint minus_one_day(timepoint tp) {
    auto t = tp - std::chrono::hours(24);
    return t;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;

    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

void ltrim(std::string *s) {
    s->erase(s->begin(), std::find_if(s->begin(), s->end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

void rtrim(std::string *s) {
    s->erase(std::find_if(s->rbegin(), s->rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s->end());
}

void trim(std::string *s) {
    ltrim(s);
    rtrim(s);
}

std::string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

std::string hex_to_string(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();
    if (len & 1) throw std::invalid_argument("odd length");

    std::string output;
    output.reserve(len / 2);
    for (size_t i = 0; i < len; i += 2)
    {
        char a = input[i];
        const char* p = std::lower_bound(lut, lut + 16, a);
        if (*p != a) throw std::invalid_argument("not a hex digit");

        char b = input[i + 1];
        const char* q = std::lower_bound(lut, lut + 16, b);
        if (*q != b) throw std::invalid_argument("not a hex digit");

        output.push_back(((p - lut) << 4) | (q - lut));
    }
    return output;
}

} // namespace util
