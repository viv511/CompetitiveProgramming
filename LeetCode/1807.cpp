#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
   std::unordered_map<std::string, std::string> lookup;
   lookup.reserve(knowledge.size());

   // assert(keyval.size() == 2)
   for (const auto& keyval : knowledge) {
      lookup[keyval[0]] = keyval[1];
   }

   bool active = false;
   std::string phrase = "";
   std::string ans = "";
   for (size_t i = 0; i < s.length(); i++) {
      if (active) {
         if (s[i] == ')') {
            active = false;

            auto it = lookup.find(phrase);
            if (it == lookup.end()) {
               ans += "?";
            }
            else {
               ans += it->second;
            }
         }
         else {
            phrase += s[i];
         }
      }
      else {
         if(s[i] == '(') {
            active = true;
            phrase = "";
         }
         else {
            ans += s[i];
         }
      }
   }

   return ans;
}