# A simple Python program to remove duplicates from a list but keep the order of elements

def remove_duplicates(input_list):
    seen = set()
    result = []
    for item in input_list:
        if item not in seen:
            seen.add(item)
            result.append(item)
    return result

if __name__ == "__main__":
    sample_list = [1, 2, 2, 3, 4, 4, 5]
    print("Original list:", sample_list)
    print("List after removing duplicates:", remove_duplicates(sample_list))
