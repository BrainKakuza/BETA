


class HTMLElementWithAttributes : public HTMLElement
{
public:
private:
	map<string, string> attributes ;
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
