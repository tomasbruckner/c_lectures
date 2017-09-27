/**
    Zadani:
        Doplnte vas kod pod tento komentar, aby se program v poradku prelozil. 
        Zdrojovy kod prekladejte s parametry -pedantic -Wextra -Wall -std=c99 (viz prvni cviceni).
**/




/* Neupravujte kod pod timto radkem  */
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
