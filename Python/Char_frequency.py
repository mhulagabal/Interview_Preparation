# Python program to count the frequency of each character in a string

def freq_chars(s):
    freq = {}
    for ch in s:
        if ch not in freq:
            freq[ch] = 1
        else:
            freq[ch] += 1
    return freq

# Example usage
if __name__ == "__main__":
    text = "hello world"
    result = freq_chars(text)
    for char, count in result.items():

        print(f"'{char}': {count}")
