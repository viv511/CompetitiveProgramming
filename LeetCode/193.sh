# one-liner to output all valid phone numbers from file.txt
grep -E '^(([0-9]{3}-[0-9]{3}-[0-9]{4})|(\([0-9]{3}\) [0-9]{3}-[0-9]{4}))$' file.txt