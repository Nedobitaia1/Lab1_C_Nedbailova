#include "iostream"
#include "string"
#include <fstream>
using namespace std;

int main(void){
	
	string type1, type2;
	bool is_string = false;
	cout << "Input first type: ";
	getline(cin, type1);
	cout << "Input second type: ";
	getline(cin, type2);

	if(type1 == "string" || type2 == "string"){
		cout << "The types have a string type, all types will be converted to string." << endl;
		is_string = true;
		type1 = "string";
		type2 = "string";
	}

	if(is_string){
		string line;
		ifstream in("comands.txt");
		while (getline(in, line)){
			if(line[0] != '+') {
				cout << "Error! Only + operation can be used for strings.";
				return 0;
			}
		}
		in.close();			
	}

	ofstream fout("func_1.cpp");
	fout << "#include <iostream>" << endl;
	fout << "#include <type_traits>" << endl;
	fout << "using namespace std;" << endl;
	fout << "int f(void) {"<< endl;

	if(is_string){
		fout <<"	"<< type1 << " var1 = \"1\";"<< endl;
		fout <<"	"<< type1 << " var2 = \"2\";"<< endl;
		fout <<"	string result;"<< endl;
	} else{
		fout <<"	"<< type1 << " var1 = 1;"<< endl;
		fout <<"	"<< type2 << " var2 = 2;"<< endl;
		fout << "	using res_type = common_type_t<decltype(var1), decltype(var2)>;" << endl;
		fout << "	res_type result;" << endl;
	}
	
	string line;
	ifstream in("comands.txt");
	while (getline(in, line)){
		if(line.length() == 1) {
			fout << "	result = var1 " << line << " var2;"<< endl;
		} else{
			fout << "	result = result " << line[0] << " var"<<line[1]<<";"<< endl;
		}
	}
	in.close();
	fout << "	cout << result << endl;"<< endl;
	fout << "	return 0;" << endl;
	fout << "}" << endl;
	fout.close();
	return 0;
}
