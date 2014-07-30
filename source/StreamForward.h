#ifndef STREAM_FORWARD_H
#define STREAM_FORWARD_H

#include <type_traits>

namespace stream {

template<typename T> class Stream;

namespace detail {

template<typename T> struct StreamIdentifier { using type = void; };
template<typename T> struct StreamIdentifier<Stream<T>> { using type = T; };

} /* detail */

template<typename S> using StreamType =
    typename detail::StreamIdentifier<std::remove_reference_t<S>>::type;

} /* namespace stream */


#endif