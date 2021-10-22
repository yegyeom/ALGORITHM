//BOJ 3452번: 고스택
//2021-07-06
#include <iostream>
#include <vector>
#define MAX 1000000000
#define MIN -1000000000
using namespace std;

vector<long long> stk, num;
vector<string> command;
long long n;

bool program()
{
    int cnt = 0;

    //명령어 실행
    for (int i = 0; i < command.size(); i++)
    {
        if (command[i] == "NUM")
        {
            // num 벡터에 있는 값 사용
            stk.push_back(num[cnt++]);
        }
        else if (command[i] == "POP")
        {
            if (stk.size() < 1) return false;
            stk.pop_back();
        }
        else if (command[i] == "INV")
        {
            if (stk.size() < 1) return false;

            long long tmp = stk.back();
            tmp = -tmp;

            stk.pop_back();
            stk.push_back(tmp);
        }
        else if (command[i] == "DUP")
        {
            if (stk.size() < 1) return false;
            stk.push_back(stk.back());
        }
        else if (command[i] == "SWP")
        {
            if (stk.size() < 2) return false;

            long long tmp1 = stk.back();
            stk.pop_back();
            long long tmp2 = stk.back();
            stk.pop_back();

            stk.push_back(tmp1);
            stk.push_back(tmp2);
        }
        else if (command[i] == "ADD")
        {
            if (stk.size() < 2) return false;

            long long tmp1 = stk.back();
            stk.pop_back();
            long long tmp2 = stk.back();
            stk.pop_back();

            long long num = tmp1 + tmp2;
            if (num > MAX || num < MIN) return false;
            else stk.push_back(num);
        }
        else if (command[i] == "SUB")
        {
            if (stk.size() < 2) return false;

            long long tmp1 = stk.back();
            stk.pop_back();
            long long tmp2 = stk.back();
            stk.pop_back();

            long long num = tmp2 - tmp1;
            if (num > MAX || num < MIN) return false;
            else stk.push_back(num);
        }
        else if (command[i] == "MUL")
        {
            if (stk.size() < 2) return false;

            long long tmp1 = stk.back();
            stk.pop_back();
            long long tmp2 = stk.back();
            stk.pop_back();

            long long num = tmp1 * tmp2;
            if (num > MAX || num < MIN) return false;
            else stk.push_back(num);
        }
        else if (command[i] == "DIV")
        {
            if (stk.size() < 2) return false;

            long long tmp1, tmp2, num;
            tmp1 = stk.back();
            stk.pop_back();
            tmp2 = stk.back();
            stk.pop_back();

            if (tmp1 == 0) return false;

            if ((tmp1 > 0 && tmp2 > 0) || (tmp1 < 0 && tmp2 < 0))
                num = tmp2 / tmp1;
            else
            { //음수 한개
                num = abs(tmp2) / abs(tmp1);
                num = -num;
            }

            stk.push_back(num);
        }
        else if (command[i] == "MOD")
        {
            if (stk.size() < 2) return false;

            long long tmp1, tmp2, num;
            tmp1 = stk.back();
            stk.pop_back();
            tmp2 = stk.back();
            stk.pop_back();

            if (tmp1 == 0)
                return false;

            if (tmp2 < 0)
            {
                num = abs(tmp2) % tmp1;
                num = -num;
            }
            else if (tmp2 > 0)
            {
                num = tmp2 % tmp1;
            }

            stk.push_back(num);
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (1)
    {
        string str;
        command.clear();
        num.clear();

        while (1)
        {
            cin >> str;
            if (str == "END") break;
            else if (str == "QUIT") return 0;
            else if (str == "NUM")
            {
                int a;
                cin >> a;
                command.push_back(str);
                num.push_back(a);
            }
            else
                command.push_back(str);
        }

        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;

            stk.clear();
            stk.push_back(input);

            if (!program() || stk.size() != 1)
                cout << "ERROR\n";
            else
                cout << stk[0] << '\n';
        }
        cout << '\n';
    }

    return 0;
}