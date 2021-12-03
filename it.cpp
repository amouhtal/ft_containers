template <class _TreeIterator>
class _LIBCPP_TEMPLATE_VIS __map_iterator
{
    typedef typename _TreeIterator::_NodeTypes                   _NodeTypes;
    typedef typename _TreeIterator::__pointer_traits             __pointer_traits;

    _TreeIterator __i_;

public:
    typedef bidirectional_iterator_tag                           iterator_category;
    typedef typename _NodeTypes::__map_value_type                value_type;
    typedef typename _TreeIterator::difference_type              difference_type;
    typedef value_type&                                          reference;
    typedef typename _NodeTypes::__map_value_type_pointer        pointer;

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator() _NOEXCEPT {}

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator(_TreeIterator __i) _NOEXCEPT : __i_(__i) {}

    _LIBCPP_INLINE_VISIBILITY
    reference operator*() const {return __i_->__get_value();}
    _LIBCPP_INLINE_VISIBILITY
    pointer operator->() const {return pointer_traits<pointer>::pointer_to(__i_->__get_value());}

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator& operator++() {++__i_; return *this;}
    _LIBCPP_INLINE_VISIBILITY
    __map_iterator operator++(int)
    {
        __map_iterator __t(*this);
        ++(*this);
        return __t;
    }

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator& operator--() {--__i_; return *this;}
    _LIBCPP_INLINE_VISIBILITY
    __map_iterator operator--(int)
    {
        __map_iterator __t(*this);
        --(*this);
        return __t;
    }

    friend _LIBCPP_INLINE_VISIBILITY
    bool operator==(const __map_iterator& __x, const __map_iterator& __y)
        {return __x.__i_ == __y.__i_;}
    friend
    _LIBCPP_INLINE_VISIBILITY
    bool operator!=(const __map_iterator& __x, const __map_iterator& __y)
        {return __x.__i_ != __y.__i_;}

    template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS map;
    template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS multimap;
    template <class> friend class _LIBCPP_TEMPLATE_VIS __map_const_iterator;
};