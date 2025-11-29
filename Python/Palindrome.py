# A simple program to check if a string is a palindrome

def palindrome(s):
    if s == s[::-1]:
        print(f'"{s}" is a palindrome.')
    else:
        print(f'"{s}" is not a palindrome.')

if __name__ == "__main__":
    s = input("Enter a string: ")
    palindrome(s)