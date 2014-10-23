#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss(s);
    std::string item;
    while ( std::getline(ss, item, delim) )
    {
        elems.push_back( item );
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::vector<double> string_to_double(const std::vector<std::string>& svec)
{
    std::vector<double> dvec(svec.size());

    // lambda x : stod(x)
    auto func = [] (const std::string& val) { return std::stod(val); };
    std::transform(svec.begin(), svec.end(), dvec.begin(), func);
    return dvec;
}

int main()
{
    ifstream infile("test.txt");
    if (!infile.good())
        return 1; // exit if file not found
   
    int j = 0;
    string line;
    while ( std::getline(infile, line) )
    {
        if (j > 1) {
            vector<string> elems = split(line, '|');

            int nInput = atoi(elems[0].c_str());
            int nOutput = atoi(elems[1].c_str());
            string activation = elems[2];
            vector<double> weights = string_to_double(split(elems[3], ','));
            vector<double> bias = string_to_double(split(elems[4], ','));

            cout << "nInput = " << nInput << endl;
            cout << "nOutput = " << nOutput << endl;
            cout << "activation = " << activation << endl;
            
            int i = 0;
            for ( auto entry : weights )
            {
                cout << "weights[" << i << "] = " << entry << endl;
                i++;
            }
            
            i = 0;
            for ( auto entry : bias )
            {
                cout << "bias[" << i << "] = " << entry << endl;
                i++;
            }
        }
        j++;
    }
    
}
