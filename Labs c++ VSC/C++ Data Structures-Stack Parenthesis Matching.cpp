#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool IsPair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == ']')
		return true;
	return false;
}
bool IsBalanced(string exp)
{
	stack<char>  S;
	int length = exp.length();
	for (int i = 0; i < length; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !IsPair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

//int main()
//{
//
//	string expression;
//	expression = "(((2 + 3)) * (5 - 5)";
//	if (IsBalanced(expression))
//		cout << "Balanced\n";
//	else
//		cout << "Not Balanced\n";
//
//	expression = "((2 + 3) * (5 - 5))";
//	if (IsBalanced(expression))
//		cout << "Balanced\n";
//	else
//		cout << "Not Balanced\n";
//
//	return 0;
//}