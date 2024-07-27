#ifndef TRAITS_HPP
#define TRAITS_HPP

#include <type_traits>

#if __cplusplus < 202002L
#error "This code requires C++20 or later. Please use a C++20 compatible compiler."
#endif

namespace traits {

class TraitBase {
};

template<typename T>
concept IsTrait = std::is_base_of_v<TraitBase, T>;

#define TRAIT : public traits::TraitBase

template<IsTrait... Ts>
class impl_checker : public Ts... {};

#define IMPL(...) : public traits::impl_checker<__VA_ARGS__>

} // namespace traits

#endif // TRAITS_HPP
