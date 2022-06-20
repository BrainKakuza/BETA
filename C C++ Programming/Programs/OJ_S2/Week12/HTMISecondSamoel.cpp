#include<iostream>
#include<list>
#include<map>

using namespace std;

class HTMLElementWithAttributes : public HTMLElement
{
public:
    HTMLElementWithAttributes(string str): HTMLElement(str)
    {
        string key;
        string value;
        bool valueEnd = false;
        bool quotation = false;

        for(int i = 1 + tagName.size(); str[i] != '>'; i++)
        {
            if(str[i] != '=' && !quotation)
            {
                key += str[i];
            }

            if(str[i] == '"' && !quotation)
            {
                quotation = true;
                continue;
            }

            if(str[i] != '"' && quotation && !valueEnd)
            {
                value += str[i];
            }

            if(str[i] == '"' && quotation)
            {
                valueEnd = true;
            }

            if(quotation && valueEnd)
            {
                attributes.insert({key , value});
                key = "";
                value = "";
                valueEnd = false;
                quotation = false;
            }  
        }
    }

    list<string> getAttributes() const
    {
        list<string> l = {};

        for(auto x: attributes)
        {
            l.push_back(x.first);
        }

        return l;
    }

    string operator [] (string key)
    {
        return attributes[key];
    }
private:
	map<string, string> attributes;
};
int main() {
  std::string str;
  getline(std::cin,str);
  HTMLElementWithAttributes html(str);
  std::cout << html.getTagName() << endl ;
  std::list<std::string> key = html.getAttributes();
  for(std::string k : key)
    std::cout<<html[k]<<std::endl;
  return 0;
}
