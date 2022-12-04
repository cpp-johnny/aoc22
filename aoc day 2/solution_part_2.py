
# create new list
new_score = ["BX", "CX", "AX", "AY", "BY", "CY", "CZ", "AZ", "BZ"]

def answer(input_list):
    with open("aoc_2022_d2.txt") as input:
        return sum(map(lambda pair: input_list.index(pair) + 1, map(lambda line: ''.join(line.strip().split()), input.readlines())))

# get answer
print(answer(new_score))
