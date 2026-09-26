#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string evaluate(const string s, const vector<vector<string>>& knowledge) {
   std::unordered_map<std::string, std::string> lookup;
   lookup.reserve(knowledge.size());

   // assert(keyval.size() == 2)
   for (const auto& keyval : knowledge) {
      lookup[keyval[0]] = keyval[1];
   }

   std::string ans;
   ans.reserve(s.size());
   std::string phrase = "";
   for (size_t i = 0; i < s.length(); i++) {
      if(s[i] == '(') {         
         // optimization: as soon as we find a "(" we can find the whole phrase
         size_t closingParen = s.find(')', i);
         phrase = s.substr(i + 1, closingParen - i - 1);

         auto it = lookup.find(phrase);
         if (it == lookup.end()) {
            ans += "?";
         }
         else {
            ans += it->second;
         }

         i = closingParen;
      }
      else {
         ans += s[i];
      }
   }

   return ans;
}