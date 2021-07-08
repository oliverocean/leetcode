// 0053

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_subarray(vector<int>& nums) {

    int the_max = INT_MIN;
    int streak = 0;

    for (auto n : nums) {
        streak = max(n, n + streak);
        the_max = max(the_max, streak);
    }

    return the_max;
}

//--[ test driver ]--//
int main() {
    cout << "\n---[ input ]---\n";

    cout << "> Original Vector:\n";
    vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // should be 6
    //std::vector<int> nums {1}; // should be 1
    //std::vector<int> nums {-2, 1}; // should be 1
    cout << " [ "; for (auto n : nums) { cout << n << ", "; } cout << "]";

    int result = max_subarray(nums);

    cout << "\n\n---[ output ]---\n";
    cout << "> result:\n [ " << result << " ]\n";
}

/*

--[ round 0 ]--
• n [ -2 ]
• streak [ 0 ]
• the_max [ -2147483648 ]
> streak = max(n, n + streak)?
<< [ -2 ] OR [ -2 ]
streak [ -2 ]
> the_max = max(the_max, streak)?
<< [ -2147483648 ] OR [ -2 ]
the_max [ -2 ]

--[ round 1 ]--
• n [ 1 ]
• streak [ -2 ]
• the_max [ -2 ]
> streak = max(n, n + streak)?
<< [ 1 ] OR [ -1 ]
streak [ 1 ]
> the_max = max(the_max, streak)?
<< [ -2 ] OR [ 1 ]
the_max [ 1 ]

--[ round 2 ]--
• n [ -3 ]
• streak [ 1 ]
• the_max [ 1 ]
> streak = max(n, n + streak)?
<< [ -3 ] OR [ -2 ]
streak [ -2 ]
> the_max = max(the_max, streak)?
<< [ 1 ] OR [ -2 ]
the_max [ 1 ]

--[ round 3 ]--
• n [ 4 ]
• streak [ -2 ]
• the_max [ 1 ]
> streak = max(n, n + streak)?
<< [ 4 ] OR [ 2 ]
streak [ 4 ]
> the_max = max(the_max, streak)?
<< [ 1 ] OR [ 4 ]
the_max [ 4 ]

--[ round 4 ]--
• n [ -1 ]
• streak [ 4 ]
• the_max [ 4 ]
> streak = max(n, n + streak)?
<< [ -1 ] OR [ 3 ]
streak [ 3 ]
> the_max = max(the_max, streak)?
<< [ 4 ] OR [ 3 ]
the_max [ 4 ]

--[ round 5 ]--
• n [ 2 ]
• streak [ 3 ]
• the_max [ 4 ]
> streak = max(n, n + streak)?
<< [ 2 ] OR [ 5 ]
streak [ 5 ]
> the_max = max(the_max, streak)?
<< [ 4 ] OR [ 5 ]
the_max [ 5 ]

--[ round 6 ]--
• n [ 1 ]
• streak [ 5 ]
• the_max [ 5 ]
> streak = max(n, n + streak)?
<< [ 1 ] OR [ 6 ]
streak [ 6 ]
> the_max = max(the_max, streak)?
<< [ 5 ] OR [ 6 ]
the_max [ 6 ]

--[ round 7 ]--
• n [ -5 ]
• streak [ 6 ]
• the_max [ 6 ]
> streak = max(n, n + streak)?
<< [ -5 ] OR [ 1 ]
streak [ 1 ]
> the_max = max(the_max, streak)?
<< [ 6 ] OR [ 1 ]
the_max [ 6 ]

--[ round 8 ]--
• n [ 4 ]
• streak [ 1 ]
• the_max [ 6 ]
> streak = max(n, n + streak)?
<< [ 4 ] OR [ 5 ]
streak [ 5 ]
> the_max = max(the_max, streak)?
<< [ 6 ] OR [ 5 ]
the_max [ 6 ]

---[ output ]---
> result: [ 6 ]
*/

// eof
