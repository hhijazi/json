//
//  Value_.cpp
//  
//
//  Created by Hassan on 6/04/2016.
//
//

#include "json/Value_.hh"
#include "json/Value.hh"
#include "json/Object.hh"
#include "json/Array.hh"

#include <memory>

template class Value<std::string>;
template class Value<int>;
template class Value<long int>;
template class Value<long long int>;
template class Value<float>;
template class Value<double>;
template class Value<bool>;
template class Value<Null>;

template <typename K, typename V>
template class Value<Object<>>;
template class Value<Array>;