#define FOO(rep_part, unit, exp) ([&]() { auto __r = unit; rep_part __r = op(__r, exp); return __r; }())


// max of a,b,c,d
*max_element(vector<ll>{a, b, c, d})
