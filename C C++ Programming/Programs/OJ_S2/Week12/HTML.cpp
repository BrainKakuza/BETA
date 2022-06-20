#include <iostream>

using namespace std;

class HTMLElement
{
private:
  string tagName , content;
public:
  HTMLElement(string str)
  {
    bool change = true;

    for(int i = 1; i < str.length(); i++)
    {
      if(change)
      {
        tagName.push_back(str[i]);

        if(str[i + 1] == '>')
        {
          i++;
          change = false;
        }
      }else
      {
        content.push_back(str[i]);

        if(str[i + 1] == '<')
        {
          break;
        }
      }
    }
  }

  std::string getTagName()
  {
    return tagName;
  }
  std::string getContent()
  {
    return content;
  }
};
int main() {
  std::string str;
  getline(std::cin,str);
  HTMLElement html(str);
  std::cout<<html.getTagName()<<std::endl;
  std::cout<<html.getContent()<<std::endl;
  return 0;
}
