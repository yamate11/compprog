#include <iostream>

// ヘルパーマクロ
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define FOREACH_MACRO(MACRO, ...) \
    EXPAND(MACRO(__VA_ARGS__)) 

#define EXPAND(x) x

#define ENUM_CASE(e) case e: return ostr << TOSTRING(e);

#define simpleEnum(name, ...) \
    enum name { __VA_ARGS__ }; \
    inline std::ostream& operator<<(std::ostream& ostr, name e) { \
        switch (e) { \
            FOREACH_MACRO(ENUM_CASE, __VA_ARGS__) \
        } \
        return ostr << "unknown"; \
    }

// 使用例
simpleEnum(MyEnum, val1, val2, val3, val4, val5)

int main() {
    MyEnum e = val3;
    std::cout << e << std::endl;  // 出力: val3
    return 0;
}
