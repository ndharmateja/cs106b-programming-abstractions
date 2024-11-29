#include <iostream>
#include <string>

using namespace std;

void print_string(string &s) { cout << "'" << s << "' (" << s.length() << ")" << endl; }

int main(int argc, char const *argv[])
{
    string s = "dharma teja";
    print_string(s);
    s.erase(2, 2);
    print_string(s);
    s.append(" nuli");
    print_string(s);

    string s1 = "world";
    string s2 = "hello" + s1;
    print_string(s1);
    print_string(s2);

    string s3 = "hi" + '?';
    print_string(s3);
    return 0;
}
