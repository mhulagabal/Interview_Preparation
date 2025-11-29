# This function takes a string as input and returns a
# new string with the order of words reversed.

def reverse_words(senetence: str) -> str:
    """Reverses the order of words in a given string"""
    return " ".join(word[::-1] for word in senetence.split(" "))

if __name__ == "__main__":
    print(reverse_words("Hello World"))