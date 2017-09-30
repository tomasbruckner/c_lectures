/**
    Task:
        Add your code under this block comment section so the source code is compiled
        without errors or warnings.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/

void bar(int i);
void foo(int i);

/* Do not change code under this line  */
int main() {
    foo(1);
    return 0;
}

void bar(int i) {
    if (i > 0) {
        foo(0);
    }
}

void foo(int i) {
    if (i > 0) {
        bar(0);
    }
}
