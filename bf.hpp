#ifndef __BF_PROJECT_HPP__
#define __BF_PROJECT_HPP__

#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>

namespace bf
{

namespace internal
{
template <typename charT = char, typename... Targs>
void __out(std::basic_ostream<charT> &os, const Targs &...args) noexcept
{
	std::ios oldState(nullptr);
	oldState.copyfmt(os);
	((os << args), ...);
	os.copyfmt(oldState);
}

}	 // namespace internal

template <typename... Targs>
inline void println(const Targs &...args)
{
	internal::__out(std::cout, args..., "\n");
}

template <typename charT = char, typename... Targs>
inline void println_to(std::basic_ostream<charT> &o,
											 const Targs &...args) noexcept
{
	internal::__out(o, args..., '\n');
}

template <typename... Targs>
inline void print(const Targs &...args)
{
	internal::__out(std::cout, args...);
}

template <typename charT = char, typename... Targs>
inline void print_to(std::basic_ostream<charT> &o,
										 const Targs &...args) noexcept
{
	internal::__out(o, args...);
}

template <typename... Targs>
inline std::string format(const Targs &...args)
{
	std::ostringstream os;
	internal::__out(os, args...);
	return os.str();
}

template <typename... Targs>
inline std::string formatln(const Targs &...args)
{
	return format(args..., "\n");
}

#define logln(...) \
	println(__FILE__, ":", __LINE__, "(", __func__, ")", " ", __VA_ARGS__)

}	 // namespace bf

#endif	// __BF_PROJECT_HPP__