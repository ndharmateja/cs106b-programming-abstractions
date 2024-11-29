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
    return 0;
}
