#ifndef TYPETRAITS_H
#define TYPETRAITS_H

namespace MiniSTL
{
	// Helper class and typedefs

	template<typename T, T v>
	struct integral_constant
	{
		static constexpr T value = v;
		using value_type = T;
		using type = integral_constant;
		constexpr operator value_type() const noexcept { return value; }
		constexpr value_type operator()() const noexcept { return value; }
	};

	template<bool B>
	using bool_constant = integral_constant<bool, B>;    // defined in C++ 17

	using true_type = integral_constant<bool, true>;
	using false_type = integral_constant<bool, false>;

	// Primary type categories

	template<typename T, typename U>
	struct is_same : public false_type {  };
	template<typename T>
	struct is_same<T, T> : public true_type { };

	template<typename T>
	struct remove_const
	{
		using type = T;
	};
	template<typename T>
	struct remove_const<const T>
	{
		using type = T;
	};
	template<typename T>
	struct remove_volatile
	{
		using type = T;
	};
	template<typename T>
	struct remove_volatile<volatile T>
	{
		using type = T;
	};
	template<typename T>
	struct remove_cv
	{
		using type = typename remove_volatile<typename remove_const<T>::type>::type;
	};

	template<typename T>                                             // defined in C++ 17
	using remove_volatile_t = typename remove_volatile<T>::type;
	template<typename T>
	using remove_const_t = typename remove_const<T>::type;
	template<typename T>
	using remove_cv_t = typename remove_cv<T>::type;

	template<typename T>
	struct is_void : public is_same<void, typename remove_cv<T>::type> { };

	template<typename T>
	struct is_pointer_helper : public false_type { };
	template<typename T>
	struct is_pointer_helper<T*> : public true_type { };
	template<typename T>
	struct is_pointer : is_pointer_helper<typename remove_cv<T>::type> { };


}


#endif