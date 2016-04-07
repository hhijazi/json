#pragma once

#include <iostream>
#include <json/Value_.hh>

class Null { };

template<typename T = Null>
class Value : public Value_{
    
private:
    T                      _val; /**< Current value. */
    
public:

    Value& operator=(const Value<T>& v)
    {
        _val = v._val;
        return *this;
    }
    
    Value& operator=(const T& t)
    {
        _val = t;
        return *this;
    }
    
    Value(const Value<T>& v): _val(v._val) { }
    
    Value(const T& v) : _val(v) { }
    
    const T& get() const noexcept
    {
        return _val;
    };
    
    T& get() noexcept
    {
        return _val;
    };
    
    void set(const T& t) noexcept
    {
        _val = t;
    }
    
    
    
};

template <>
class Value<Null> {

};

template <typename T>
T& as(const std::shared_ptr<Value_>& p)
{
    return std::static_pointer_cast<Value<T>>(p)->get();
}

template <typename T>
const T& as_const(const std::shared_ptr<Value_>& p)
{
    return std::static_pointer_cast<Value<T>>(p)->get();
}


