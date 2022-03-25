#include <bits/stdc++.h>

using namespace std;


template<typename E>
constexpr auto toUType(E enumerator) noexcept
{
    return static_cast<underlying_type_t<E>>(enumerator); // std::underlying_type_t<E> is int32_t
}


int main()
{
    using UserInfo = tuple<string, string, size_t>; // 3 elements of tuple
    enum class UserInfoFields : int32_t  { uiName,  uiEmail, uiReputation }; // underlying_type_t is int32_t that explicitly defined here.
    
    UserInfo user;
    user = make_tuple(string("user"),string("user@gmail.com"), 100);
  
    auto index0 = toUType(UserInfoFields::uiName);
    auto index1 = toUType(UserInfoFields::uiEmail);
    auto index2 = toUType(UserInfoFields::uiReputation);

    auto index = static_cast<int32_t>(UserInfoFields::uiEmail);

    auto val1 = get< static_cast<int32_t>(UserInfoFields::uiEmail) >(user);
    auto val2 = get<toUType(UserInfoFields::uiEmail)>(user);    
    auto val3 = get<1>(user);


    return 0;
}