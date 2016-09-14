#include <type_traits>
#include <allocators>
#include <cassert>
#include <iterator>

namespace MiniSTL
{
	template<typename T>
	class string
	{
	public:
		/* Member type */
		typedef std::Traits traits_type;
		typedef Traits::char_type value_type;
		typedef Allocator allocator_type;
		typedef std::allocator_traits<Allocator>::size_type size_type;
		typedef std::_Has_allocator_type<Allocator>::difference_type difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef std::allocator_traits<Allocator>::pointer pointer;
		typedef std::allocator_traits<Allocator>::const_pointer const_pointer;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		/* Member functions */
		explicit string(const Allocator& alloc = Allocator()) { }
		
	};
}