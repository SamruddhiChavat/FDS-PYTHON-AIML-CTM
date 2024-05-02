import re
pattern_a = r'b[aiu]t|h[aiu]t'
strings_a = ["bat", "bit", "but", "hat", "hit", "hut"]
for string in strings_a:
    if re.match(pattern_a, string):
        print(f"'{string}' matches the pattern.")
    else:
        print(f"'{string}' does not match the pattern.")

pattern_b = r'\b\w+\s\w+\b'
test_string_b = "John Doe, Jane Smith, Alice Wonderland"
matches_b = re.findall(pattern_b, test_string_b)
print("Matches for pattern b:", matches_b)

pattern_c = r'\b\w+\s*,\s*\w\b'
test_string_c = "Doe, J, Smith, A, Wonderland, B"
matches_c = re.findall(pattern_c, test_string_c)
print("Matches for pattern c:", matches_c)
