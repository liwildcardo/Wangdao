#include "solutions.h"

int main()
{
    char a[10] = {'(', '[', '{', '[', '(', ')', ']', '}', ']', ')'};
    if (BracketCheck(a, sizeof a / sizeof(char))) printf("success!\n");

    return 0;
}
