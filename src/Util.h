/*
 * Util.h
 *
 *  Created on: Mar 9, 2018
 *      Author: jurgen
 */

#ifndef UTIL_H_
#define UTIL_H_

#pragma once

#include <string>
#include <functional>
#include <future>
#include <iostream>
#include <vector>


namespace util {

using timepoint = std::chrono::system_clock::time_point;

uint16_t str_to_uint16_be(const std::string& s);

std::string uint16_to_str_be(uint16_t n);

uint32_t str_to_uint32_be(const std::string& s);

std::string uint32_to_str_be(uint32_t n);

uint64_t str_to_uint64_be(const std::string& s);

std::string uint64_to_str_be(uint64_t n);

std::string uint64_to_hex(uint64_t n);
std::string uint8_to_hex(uint8_t n);
std::string uint16_to_hex(uint16_t n);

std::string bytes_to_hex(const std::string &bytes);

std::string rotate_left(const std::string &bytes, size_t n);

std::string hex_to_bytes(const std::string &hex);

std::string get_local_time(const std::string& fmt);

std::string generate_uuid();

std::string random_bytes(size_t bytes);

timepoint get_local_time(int hour, int min, int sec = 0);

timepoint plus_one_day(timepoint tp);

timepoint minus_one_day(timepoint tp);

void delayed_call(std::chrono::nanoseconds, std::function<void(void)>);

std::vector<std::string> split(const std::string &s, char delim);

void ltrim(std::string *s);

void rtrim(std::string *s);

void trim(std::string *s);

std::string hex_to_string(const std::string& input);

std::string string_to_hex(const std::string& input);

} // namespace util





#endif /* UTIL_H_ */
