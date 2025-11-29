# A simple program to find the second largest number in a list without builtin functions

def sort_ascending(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def find_second_largest(numbers):
    sorted_array = sort_ascending(numbers)
    return sorted_array[-2]

if __name__ == "__main__":
    numbers = [10, 20, 4, 45, 99, 99, 45]

    print("Second Largest Number:", find_second_largest(numbers))
