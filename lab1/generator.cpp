#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // cin data types and their values (2 or 3)
    string type1, type2, type3;
    string var1, var2, var3;

    cout << "Enter two or three data types: ";
    cin >> type1 >> type2;
    if (cin.peek() != '\n') {
        cin >> type3;
    }
    bool has_type3 = !type3.empty();

    cout << "Enter values for the specified data types: ";
    cin >> var1 >> var2;
    if (has_type3) {
        cin >> var3;
    }

    // store operations as a vector<string>
    vector<string> operations = {"+", "-", "/", "*"};
    // modulus operator only works with int
    if (type1 == "int" && type2 == "int" && (!has_type3 || type3 == "int")) {
        operations.push_back("%");
    }

    // generate function that performs operations on entered vars
    ofstream fout("function.cpp");
    if (!fout) {
        cerr << "Ошибка создания файла function.cpp" << endl;
        return 1;
    }

    fout << "#include <iostream>" << endl << endl;
    fout << "int main() {" << endl;

    fout << "    " << type1 << " var1 = " << var1 << ";" << endl;
    fout << "    " << type2 << " var2 = " << var2 << ";" << endl;
    if (has_type3) {
        fout << "    " << type3 << " var3 = " << var3 << ";" << endl;
    }

    fout << std::fixed;

    for (const auto& op : operations) {
        fout << "    std::cout << \"var1 " << op << " var2 = \" << (var1 " << op << " var2) << std::endl;" << endl;
        if (has_type3) {
            fout << "    std::cout << \"var2 " << op << " var3 = \" << (var2 " << op << " var3) << std::endl;" << endl;
            fout << "    std::cout << \"var1 " << op << " var3 = \" << (var1 " << op << " var3) << std::endl;" << endl;
        }
    }

    fout << "    return 0;" << endl;
    fout << "}" << endl;
    fout.close();

    cout << "+++ function.cpp is generated successfully! +++" << endl;

    return 0;
}
