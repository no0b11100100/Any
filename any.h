#pragma once
#include <memory>

using std::unique_ptr;
using std::make_unique;

namespace ANY
{

class any
{
    class IType
    {
    public:
        virtual ~IType() {};
    };

    template<class T>
    class Type : public IType
    {
        T m_data;
    public:
        Type(T data) : m_data{data}
        {}

        T getValue()
        {
            return m_data;
        }
    };

    unique_ptr<IType> m_data;

public:

    any()
    {}

    template<class U>
    auto& operator=(U data)
    {
        using type_no_cv = std::remove_cv_t<U>;
        using type_no_ref = std::remove_reference_t<type_no_cv>;
        using type = std::remove_pointer_t<type_no_ref>;
        m_data = make_unique<Type<type>>(data);
        return *this;
    }

    template<class T>
    auto get()
    {
        return static_cast<Type<T>*>(m_data.get())->getValue();
    }
};

}// namespace JSON
